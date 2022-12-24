
#ifndef _CORE_TASKS_H_
#define _CORE_TASKS_H_

#include "freertos/FreeRTOS.h"
#include "freertos/FreeRTOSConfig.h"

#define KBYTE (1024)

#define CORE_TASK_PRIO_MAX           (configMAX_PRIORITIES)
#define CORE_TASK_PRIO_MIN           (0)
#define CORE_TASK_MIN_STACK          (configMINIMAL_STACK_SIZE)
#define CORE_TASK_STACK_TYPE         portSTACK_TYPE
#define CORE_TASK_SIZE(a)            (sizeof(CORE_TASK_STACK_TYPE)*(a))


#define CORE_LVGL_ROUTUNE_TASK_PRIO         (CORE_TASK_PRIO_MIN + 4)
#define CORE_LVGL_ROUTUNE_TASK_STACK        (2*KBYTE + CORE_TASK_MIN_STACK)
#define CORE_LVGL_ROUTUNE_TASK_NAME         "lvgl_routune_timer"

#endif
