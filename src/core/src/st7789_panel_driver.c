#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "esp_err.h"
#include "esp_log.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_lcd_st7789.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "core/st7789_panel_driver.h"

#define LCD_HOST  SPI2_HOST

#define ST7789_LCD_PIXEL_CLOCK_HZ     (20 * 1000 * 1000)
#define ST7789_LCD_BK_LIGHT_ON_LEVEL  1
#define ST7789_LCD_BK_LIGHT_OFF_LEVEL !ST7789_LCD_BK_LIGHT_ON_LEVEL
#define ST7789_PIN_NUM_SCLK           18
#define ST7789_PIN_NUM_MOSI           23
#define ST7789_PIN_NUM_MISO           -1
#define ST7789_PIN_NUM_LCD_DC         27
#define ST7789_PIN_NUM_LCD_RST        33
#define ST7789_PIN_NUM_LCD_CS         -1
#define ST7789_PIN_NUM_BK_LIGHT       32
#define ST7789_PIN_NUM_TOUCH_CS       15

// Bit number used to represent command and parameter
#define ST7789_LCD_CMD_BITS           8
#define ST7789_LCD_PARAM_BITS         8

static const char *TAG = "st7789_panel_driver";


static esp_lcd_panel_handle_t panel_handle = NULL;

esp_lcd_panel_handle_t *st7789_panel_driver_init(void *lvgl_fluxh_ntfy_fnc, void *disp_drv)
{
    ESP_LOGI(TAG, "Turn off LCD backlight");
    gpio_config_t bk_gpio_config = {
        .mode = GPIO_MODE_OUTPUT,
        .pin_bit_mask = 1ULL << ST7789_PIN_NUM_BK_LIGHT
    };
    ESP_ERROR_CHECK(gpio_config(&bk_gpio_config));

    ESP_LOGI(TAG, "Initialize SPI bus");
    spi_bus_config_t buscfg = {
        .sclk_io_num = ST7789_PIN_NUM_SCLK,
        .mosi_io_num = ST7789_PIN_NUM_MOSI,
        .miso_io_num = ST7789_PIN_NUM_MISO,
        .quadwp_io_num = -1,
        .quadhd_io_num = -1,
        .max_transfer_sz = ST7789_LCD_H_RES * ST7789_LCD_V_RES * sizeof(uint16_t),
    };
    ESP_ERROR_CHECK(spi_bus_initialize(LCD_HOST, &buscfg, SPI_DMA_CH_AUTO));

    ESP_LOGI(TAG, "Install panel IO");
    esp_lcd_panel_io_handle_t io_handle = NULL;
    esp_lcd_panel_io_spi_config_t io_config = {
        .dc_gpio_num = ST7789_PIN_NUM_LCD_DC,
        .cs_gpio_num = ST7789_PIN_NUM_LCD_CS,
        .pclk_hz = SPI_MASTER_FREQ_40M,
        .lcd_cmd_bits = ST7789_LCD_CMD_BITS,
        .lcd_param_bits = ST7789_LCD_PARAM_BITS,
        .spi_mode = 2,
        .trans_queue_depth = 10,
        .on_color_trans_done = lvgl_fluxh_ntfy_fnc,
        .user_ctx = disp_drv,
    };
    // Attach the LCD to the SPI bus
    ESP_ERROR_CHECK(esp_lcd_new_panel_io_spi((esp_lcd_spi_bus_handle_t)LCD_HOST, &io_config, &io_handle));

    ESP_LOGI(TAG, "Install ST7789 panel driver");
    esp_lcd_panel_dev_config_t panel_config = {
        .reset_gpio_num = ST7789_PIN_NUM_LCD_RST,
        .rgb_endian = LCD_RGB_ENDIAN_RGB,
        .bits_per_pixel = 16,
    };
    ESP_ERROR_CHECK(esp_lcd_new_panel_st7789(io_handle, &panel_config, &panel_handle));

    //ESP_ERROR_CHECK(esp_lcd_panel_reset(panel_handle)); //disabled reset here, delay not enough, need fixup.
    gpio_set_level(ST7789_PIN_NUM_LCD_RST, 1);
    vTaskDelay(pdMS_TO_TICKS(100));
    gpio_set_level(ST7789_PIN_NUM_LCD_RST, 0);
    vTaskDelay(pdMS_TO_TICKS(100));
    gpio_set_level(ST7789_PIN_NUM_LCD_RST, 1);
    vTaskDelay(pdMS_TO_TICKS(100));

    ESP_ERROR_CHECK(esp_lcd_panel_init(panel_handle));

    // user can flush pre-defined pattern to the screen before we turn on the screen or backlight
    ESP_ERROR_CHECK(esp_lcd_panel_disp_on_off(panel_handle, true));

    ESP_LOGI(TAG, "Turn on LCD backlight");
    gpio_set_level(ST7789_PIN_NUM_BK_LIGHT, ST7789_LCD_BK_LIGHT_ON_LEVEL);

    return panel_handle;
}