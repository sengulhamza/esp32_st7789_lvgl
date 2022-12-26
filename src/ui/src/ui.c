// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: Thermostat
#include <stdio.h>
#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_Screen1;
lv_obj_t *ui_Header;
lv_obj_t *ui_Header_Date;
lv_obj_t *ui_Header_Time;
lv_obj_t *ui_Arc_Group;
void ui_event_Arc1(lv_event_t *e);
lv_obj_t *ui_Arc1;
lv_obj_t *ui_Temp_Num_Bg;
lv_obj_t *ui_Label_Celsius;
lv_obj_t *ui_Label_Slider;
void ui_event_Fan_Speed_Control(lv_event_t *e);
lv_obj_t *ui_Fan_Speed_Control;

///////////////////// FUNCTIONS ////////////////////
void ui_event_Arc1(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e); lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED) {
        _ui_arc_set_text_value(ui_Label_Celsius, target, "", "°");
    }
}

void ui_event_Fan_Speed_Control(lv_event_t *e)
{
    lv_event_code_t event_code = lv_event_get_code(e); lv_obj_t *target = lv_event_get_target(e);
    if (event_code == LV_EVENT_VALUE_CHANGED) {
        fan_speed_value(e);
    }
}

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x464B55), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Screen1, lv_color_hex(0x2D323C), LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header = lv_obj_create(ui_Screen1);
    lv_obj_set_height(ui_Header, 27);
    lv_obj_set_width(ui_Header, lv_pct(100));
    lv_obj_set_align(ui_Header, LV_ALIGN_TOP_MID);
    lv_obj_clear_flag(ui_Header, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Header, lv_color_hex(0x14191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Header, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Header, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header_Date = lv_label_create(ui_Header);
    lv_obj_set_width(ui_Header_Date, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Header_Date, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Header_Date, LV_ALIGN_LEFT_MID);
    lv_label_set_text(ui_Header_Date, "Monday, 26.12.2022");
    lv_obj_set_style_text_color(ui_Header_Date, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Header_Date, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Header_Time = lv_label_create(ui_Header);
    lv_obj_set_width(ui_Header_Time, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Header_Time, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_Header_Time, LV_ALIGN_RIGHT_MID);
    lv_label_set_text(ui_Header_Time, "14:55");
    lv_obj_set_style_text_color(ui_Header_Time, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Header_Time, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Arc_Group = lv_obj_create(ui_Screen1);
    lv_obj_set_width(ui_Arc_Group, 240);
    lv_obj_set_height(ui_Arc_Group, 240);
    lv_obj_set_align(ui_Arc_Group, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Arc_Group, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Arc_Group, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Arc_Group, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Arc1 = lv_arc_create(ui_Arc_Group);
    lv_obj_set_width(ui_Arc1, 130);
    lv_obj_set_height(ui_Arc1, 130);
    lv_obj_set_x(ui_Arc1, 0);
    lv_obj_set_y(ui_Arc1, -22);
    lv_obj_set_align(ui_Arc1, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_Arc1, 0, 60);
    lv_arc_set_value(ui_Arc1, 0);
    lv_obj_set_style_radius(ui_Arc1, 350, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0x1E232D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Arc1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Arc1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Arc1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Arc1, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc1, 15, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_Arc1, lv_color_hex(0x36B9F6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_Arc1, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_Arc1, 15, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Arc1, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Arc1, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_Temp_Num_Bg = lv_obj_create(ui_Arc1);
    lv_obj_set_width(ui_Temp_Num_Bg, 85);
    lv_obj_set_height(ui_Temp_Num_Bg, 85);
    lv_obj_set_align(ui_Temp_Num_Bg, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Temp_Num_Bg, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Temp_Num_Bg, 200, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Temp_Num_Bg, lv_color_hex(0x0C191E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Temp_Num_Bg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Temp_Num_Bg, lv_color_hex(0x191C26), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Temp_Num_Bg, LV_GRAD_DIR_VER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Temp_Num_Bg, lv_color_hex(0x5A646E), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Temp_Num_Bg, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Celsius = lv_label_create(ui_Temp_Num_Bg);
    lv_obj_set_width(ui_Label_Celsius, 78);
    lv_obj_set_height(ui_Label_Celsius, LV_SIZE_CONTENT);    /// 20
    lv_obj_set_x(ui_Label_Celsius, 13);
    lv_obj_set_y(ui_Label_Celsius, 2);
    lv_obj_set_align(ui_Label_Celsius, LV_ALIGN_CENTER);
    lv_label_set_long_mode(ui_Label_Celsius, LV_LABEL_LONG_DOT);
    lv_label_set_text(ui_Label_Celsius, "0°");
    lv_obj_set_style_text_color(ui_Label_Celsius, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Celsius, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Celsius, &ui_font_Number, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label_Slider = lv_label_create(ui_Screen1);
    lv_obj_set_width(ui_Label_Slider, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label_Slider, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label_Slider, -9);
    lv_obj_set_y(ui_Label_Slider, -44);
    lv_obj_set_align(ui_Label_Slider, LV_ALIGN_BOTTOM_MID);
    lv_label_set_text(ui_Label_Slider, " ");
    lv_obj_set_style_text_color(ui_Label_Slider, lv_color_hex(0xD2CDC8), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label_Slider, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_Label_Slider, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label_Slider, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Fan_Speed_Control = lv_slider_create(ui_Screen1);
    lv_slider_set_value(ui_Fan_Speed_Control, 50, LV_ANIM_OFF);
    if (lv_slider_get_mode(ui_Fan_Speed_Control) == LV_SLIDER_MODE_RANGE) {
        lv_slider_set_left_value(ui_Fan_Speed_Control, 0, LV_ANIM_OFF);
    }
    lv_obj_set_width(ui_Fan_Speed_Control, 170);
    lv_obj_set_height(ui_Fan_Speed_Control, 20);
    lv_obj_set_x(ui_Fan_Speed_Control, 0);
    lv_obj_set_y(ui_Fan_Speed_Control, -15);
    lv_obj_set_align(ui_Fan_Speed_Control, LV_ALIGN_BOTTOM_MID);
    lv_obj_set_style_bg_color(ui_Fan_Speed_Control, lv_color_hex(0x0F1215), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Fan_Speed_Control, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Fan_Speed_Control, lv_color_hex(0x1E242D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Fan_Speed_Control, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Fan_Speed_Control, 10, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Fan_Speed_Control, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Fan_Speed_Control, lv_color_hex(0x37B9F5), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Fan_Speed_Control, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Fan_Speed_Control, lv_color_hex(0x1464F0), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Fan_Speed_Control, LV_GRAD_DIR_HOR, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_Fan_Speed_Control, lv_color_hex(0x5F6464), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Fan_Speed_Control, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_color(ui_Fan_Speed_Control, lv_color_hex(0x3C424B), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui_Fan_Speed_Control, LV_GRAD_DIR_VER, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_color(ui_Fan_Speed_Control, lv_color_hex(0x373C46), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_opa(ui_Fan_Speed_Control, 255, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui_Fan_Speed_Control, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_outline_pad(ui_Fan_Speed_Control, 0, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_color(ui_Fan_Speed_Control, lv_color_hex(0x000000), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_opa(ui_Fan_Speed_Control, 150, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_Fan_Speed_Control, 20, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_Fan_Speed_Control, 2, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_Fan_Speed_Control, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_Fan_Speed_Control, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_Fan_Speed_Control, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_Fan_Speed_Control, 10, LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Fan_Speed_Control, lv_color_hex(0x0096FF), LV_PART_KNOB | LV_STATE_PRESSED);
    lv_obj_set_style_border_opa(ui_Fan_Speed_Control, 255, LV_PART_KNOB | LV_STATE_PRESSED);
    lv_obj_set_style_border_width(ui_Fan_Speed_Control, 4, LV_PART_KNOB | LV_STATE_PRESSED);

    lv_obj_add_event_cb(ui_Arc1, ui_event_Arc1, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Fan_Speed_Control, ui_event_Fan_Speed_Control, LV_EVENT_ALL, NULL);

}

void ui_init(void)
{
    lv_disp_t *dispp = lv_disp_get_default();
    lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
