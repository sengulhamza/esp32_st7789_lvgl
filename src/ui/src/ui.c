// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.1.1
// LVGL VERSION: 8.2.0
// PROJECT: LA66_Interface

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t *ui_Screen1;
lv_obj_t *ui_Label5;
lv_obj_t *ui_Label6;
lv_obj_t *ui_Panel1;
lv_obj_t *ui_Slider1;
lv_obj_t *ui_TextArea1;
lv_obj_t *ui_Label1;
lv_obj_t *ui_Label2;
lv_obj_t *ui_Panel2;
lv_obj_t *ui_Panel3;
lv_obj_t *ui_Label3;
lv_obj_t *ui_TextArea2;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
ui_Screen1 = lv_obj_create(NULL);
lv_obj_clear_flag( ui_Screen1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x60005C), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label5 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Label5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label5, -71 );
lv_obj_set_y( ui_Label5, -52 );
lv_obj_set_align( ui_Label5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label5,"RSSI Level");

ui_Label6 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Label6, lv_pct(53));
lv_obj_set_height( ui_Label6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label6, -45 );
lv_obj_set_y( ui_Label6, -90 );
lv_obj_set_align( ui_Label6, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label6,"Connection Status");

ui_Panel1 = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_Panel1, 20);
lv_obj_set_height( ui_Panel1, 21);
lv_obj_set_x( ui_Panel1, 31 );
lv_obj_set_y( ui_Panel1, -89 );
lv_obj_set_align( ui_Panel1, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel1, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x404040), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Slider1 = lv_slider_create(ui_Screen1);
lv_slider_set_value( ui_Slider1, 50, LV_ANIM_OFF);
if (lv_slider_get_mode(ui_Slider1)==LV_SLIDER_MODE_RANGE ) lv_slider_set_left_value( ui_Slider1, 0, LV_ANIM_OFF);
lv_obj_set_width( ui_Slider1, 124);
lv_obj_set_height( ui_Slider1, 10);
lv_obj_set_x( ui_Slider1, 49 );
lv_obj_set_y( ui_Slider1, -54 );
lv_obj_set_align( ui_Slider1, LV_ALIGN_CENTER );

ui_TextArea1 = lv_textarea_create(ui_Screen1);
lv_obj_set_width( ui_TextArea1, 56);
lv_obj_set_height( ui_TextArea1, 38);
lv_obj_set_x( ui_TextArea1, -79 );
lv_obj_set_y( ui_TextArea1, 50 );
lv_obj_set_align( ui_TextArea1, LV_ALIGN_CENTER );
lv_textarea_set_text(ui_TextArea1,"0");
lv_textarea_set_placeholder_text(ui_TextArea1,"Placeholder...");
lv_obj_set_style_text_color(ui_TextArea1, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TextArea1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_TextArea1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_decor(ui_TextArea1, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TextArea1, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TextArea1, lv_color_hex(0x404040), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TextArea1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_dir(ui_TextArea1, LV_GRAD_DIR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_TextArea1, LV_BORDER_SIDE_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label1 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label1, -82 );
lv_obj_set_y( ui_Label1, -2 );
lv_obj_set_align( ui_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label1," PING\nCount");

ui_Label2 = lv_label_create(ui_Screen1);
lv_obj_set_width( ui_Label2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label2, 78 );
lv_obj_set_y( ui_Label2, 6 );
lv_obj_set_align( ui_Label2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label2,"PONG\nCount");

ui_Panel2 = lv_obj_create(ui_Screen1);
lv_obj_set_width( ui_Panel2, 65);
lv_obj_set_height( ui_Panel2, 65);
lv_obj_set_x( ui_Panel2, 0 );
lv_obj_set_y( ui_Panel2, 50 );
lv_obj_set_align( ui_Panel2, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel2, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x00FF35), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_Panel2, LV_BORDER_SIDE_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Panel3 = lv_obj_create(ui_Panel2);
lv_obj_set_width( ui_Panel3, 55);
lv_obj_set_height( ui_Panel3, 55);
lv_obj_set_align( ui_Panel3, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_Panel3, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_Panel3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Panel3, lv_color_hex(0x404040), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Panel3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_Panel3, LV_BORDER_SIDE_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label3 = lv_label_create(ui_Panel3);
lv_obj_set_width( ui_Label3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_Label3, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label3,"00:00");
lv_obj_set_style_text_color(ui_Label3, lv_color_hex(0x00FF35), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label3, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TextArea2 = lv_textarea_create(ui_Screen1);
lv_obj_set_width( ui_TextArea2, 56);
lv_obj_set_height( ui_TextArea2, 38);
lv_obj_set_x( ui_TextArea2, 82 );
lv_obj_set_y( ui_TextArea2, 50 );
lv_obj_set_align( ui_TextArea2, LV_ALIGN_CENTER );
lv_textarea_set_text(ui_TextArea2,"0");
lv_textarea_set_placeholder_text(ui_TextArea2,"Placeholder...");
lv_obj_set_style_text_color(ui_TextArea2, lv_color_hex(0x00FF00), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TextArea2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_TextArea2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_decor(ui_TextArea2, LV_TEXT_DECOR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TextArea2, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_TextArea2, lv_color_hex(0x404040), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_TextArea2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_grad_dir(ui_TextArea2, LV_GRAD_DIR_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_TextArea2, LV_BORDER_SIDE_NONE, LV_PART_MAIN| LV_STATE_DEFAULT);

}

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_Screen1_screen_init();
lv_disp_load_scr( ui_Screen1);
}
