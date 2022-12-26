#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "freertos/timers.h"
#include "esp_err.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "lvgl.h"
#include "core/core_tasks.h"
#include "core/st7789_panel_driver.h"
#include "ui/ui.h"
#include "ui/ui_helpers.h"
#include "app/app_types.h"

#define DISP_P_MNGR_LVGL_TICK_PERIOD_MS    2

static const char *TAG = "disp_p_mngr";

static lv_disp_draw_buf_t disp_buf; // contains internal graphic buffer(s) called draw buffer(s)
static lv_disp_drv_t disp_drv;
static esp_lcd_panel_handle_t *panel = NULL;

static bool display_panel_mngr_notify_lvgl_flush_ready(esp_lcd_panel_io_handle_t panel_io, esp_lcd_panel_io_event_data_t *edata, void *user_ctx)
{
    lv_disp_drv_t *disp_driver = (lv_disp_drv_t *)user_ctx;
    lv_disp_flush_ready(disp_driver);
    return false;
}

/* Rotate display and touch, when rotated screen in LVGL. Called when driver parameters are updated. */
static void display_panel_mngr_lvgl_port_update_callback(lv_disp_drv_t *drv)
{
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t) drv->user_data;
    ESP_LOGI(TAG, "%s", __func__);

    switch (drv->rotated) {
    case LV_DISP_ROT_NONE:
        // Rotate LCD display
        esp_lcd_panel_swap_xy(panel_handle, false);
        esp_lcd_panel_mirror(panel_handle, true, false);
        break;
    case LV_DISP_ROT_90:
        // Rotate LCD display
        esp_lcd_panel_swap_xy(panel_handle, true);
        esp_lcd_panel_mirror(panel_handle, true, true);
        break;
    case LV_DISP_ROT_180:
        // Rotate LCD display
        esp_lcd_panel_swap_xy(panel_handle, false);
        esp_lcd_panel_mirror(panel_handle, false, true);
        break;
    case LV_DISP_ROT_270:
        // Rotate LCD display
        esp_lcd_panel_swap_xy(panel_handle, true);
        esp_lcd_panel_mirror(panel_handle, false, false);
        break;
    }
}

static void display_panel_mngr_lvgl_flush_cb(lv_disp_drv_t *drv, const lv_area_t *area, lv_color_t *color_map)
{
    esp_lcd_panel_handle_t panel_handle = (esp_lcd_panel_handle_t) drv->user_data;
    int offsetx1 = area->x1;
    int offsetx2 = area->x2;
    int offsety1 = area->y1;
    int offsety2 = area->y2;
    // copy a buffer's content to a specific area of the display
    esp_lcd_panel_draw_bitmap(panel_handle, offsetx1, offsety1, offsetx2 + 1, offsety2 + 1, color_map);
    ESP_LOGD(TAG, "%s", __func__);
}

static void display_panel_mngr_increase_lvgl_tick(void *arg)
{
    /* Tell LVGL how many milliseconds has elapsed */
    lv_tick_inc(DISP_P_MNGR_LVGL_TICK_PERIOD_MS);
}


static void display_panel_lv_timer_inc_task(void *param)
{
    ESP_LOGI(TAG, "%s task started.", __func__);
    while (1) {
        // raise the task priority of LVGL and/or reduce the handler period can improve the performance
        vTaskDelay(pdMS_TO_TICKS(10));
        // The task running lv_timer_handler should have lower priority than that running `lv_tick_inc`
        lv_timer_handler();
    }
}

static void display_panel_demo_task(void *param)
{
    vTaskDelay(pdMS_TO_TICKS(1000)); //wait for panel reset routine and power sequence
    ESP_LOGI(TAG, "%s task started.", __func__);
    uint8_t minutes  = 0, seconds = 0, connection_label = 0;
    char time_string[100] = {0};
    while (1) {
        //this task and generated text is only for demo
        if (++seconds >= 60) { //max second is 59
            if (++minutes >= 100) { //max min is 99
                minutes = 0;
            }
            seconds = 0;
        }
        sprintf(time_string, "%02d°", seconds);
        lv_label_set_text(ui_Label_Celsius, time_string);
        uint8_t slider_val = rand() % 101;
        //_ui_arc_increment(ui_Arc1, seconds);
        lv_arc_set_value(ui_Arc1, seconds);
        sprintf(time_string, "free/min heap:%" PRIu32 "/%" PRIu32 "", esp_get_free_heap_size(), esp_get_minimum_free_heap_size());
        lv_label_set_text(ui_Label_Slider, time_string);
        //_ui_slider_set_property(ui_Slider1, _UI_SLIDER_PROPERTY_VALUE_WITH_ANIM, slider_val); // slider demo. range is [0 - 100]
        lv_slider_set_value(ui_Fan_Speed_Control, slider_val, LV_ANIM_ON);
        ESP_LOGI(TAG, "label3: %s \t slider_val:%d \t connection_label:%d", time_string, slider_val, connection_label);
        vTaskDelay(pdMS_TO_TICKS(1000)); //one second (1000ms)
    }
}

esp_err_t display_panel_mngr_init(void)
{
    panel = st7789_panel_driver_init(display_panel_mngr_notify_lvgl_flush_ready, &disp_drv);

    ESP_LOGI(TAG, "Initialize LVGL library");
    lv_init();
    // alloc draw buffers used by LVGL
    // it's recommended to choose the size of the draw buffer(s) to be at least 1/10 screen sized
    lv_color_t *buf1 = heap_caps_malloc(ST7789_LCD_H_RES * 20 * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf1);
    lv_color_t *buf2 = heap_caps_malloc(ST7789_LCD_H_RES * 20 * sizeof(lv_color_t), MALLOC_CAP_DMA);
    assert(buf2);
    // initialize LVGL draw buffers
    lv_disp_draw_buf_init(&disp_buf, buf1, buf2, ST7789_LCD_H_RES * 20);

    ESP_LOGI(TAG, "Register display driver to LVGL");
    lv_disp_drv_init(&disp_drv);
    disp_drv.hor_res = ST7789_LCD_H_RES;
    disp_drv.ver_res = ST7789_LCD_V_RES;
    disp_drv.flush_cb = display_panel_mngr_lvgl_flush_cb;
    disp_drv.drv_update_cb = display_panel_mngr_lvgl_port_update_callback;
    disp_drv.draw_buf = &disp_buf;
    disp_drv.user_data = panel;
    lv_disp_drv_register(&disp_drv);

    ESP_LOGI(TAG, "Install LVGL tick timer");
    // Tick interface for LVGL (using esp_timer to generate 2ms periodic event)
    const esp_timer_create_args_t lvgl_tick_timer_args = {
        .callback = &display_panel_mngr_increase_lvgl_tick,
        .name = "lvgl_tick"
    };
    esp_timer_handle_t lvgl_tick_timer;
    ESP_ERROR_CHECK(esp_timer_create(&lvgl_tick_timer_args, &lvgl_tick_timer));
    ESP_ERROR_CHECK(esp_timer_start_periodic(lvgl_tick_timer, DISP_P_MNGR_LVGL_TICK_PERIOD_MS * 1000));

    ESP_LOGI(TAG, "Display LVGL Meter Widget");
    //example_lvgl_demo_ui(disp);
    ui_init();

    xTaskCreate(display_panel_demo_task,
                CORE_LVGL_ROUTUNE_TASK_NAME,
                CORE_LVGL_ROUTUNE_TASK_STACK,
                NULL,
                CORE_LVGL_ROUTUNE_TASK_PRIO,
                NULL);

    xTaskCreate(display_panel_lv_timer_inc_task,
                "lv_tick_inc_task",
                CORE_TASK_SIZE(4 * KBYTE),
                NULL,
                CORE_TASK_PRIO_MIN,
                NULL);

    return ESP_OK;
}