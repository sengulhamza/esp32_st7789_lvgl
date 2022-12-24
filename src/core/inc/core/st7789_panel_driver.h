#ifndef _ST7789_PANEL_DRIVER_H_
#define _ST7789_PANEL_DRIVER_H_

#include <stdint.h>
#include "esp_lcd_panel_io.h"
#include "esp_lcd_panel_vendor.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_panel_commands.h"

// The pixel number in horizontal and vertical
#define ST7789_LCD_H_RES              240
#define ST7789_LCD_V_RES              240

#ifdef __cplusplus
extern "C" {
#endif

esp_lcd_panel_handle_t *st7789_panel_driver_init(void *lvgl_fluxh_ntfy_fnc, void *disp_drv);

#ifdef __cplusplus
}
#endif

#endif
