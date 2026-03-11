#include <Arduino.h>
#include "display.h"
#include "lv_port_disp.h"
#include <lvgl.h>
#include "lvgl_test.h"
static TaskHandle_t lvglTaskHandle = nullptr;


/* LVGL 任务 */
static void lvgl_task(void *pvParameters)
{
    (void)pvParameters;

    const TickType_t delay_ticks = pdMS_TO_TICKS(5);

    while (true) {
        lv_timer_handler();
        vTaskDelay(delay_ticks);
    }
}

void setup() {
  // put your setup code here, to run once:
  display_init();
  lv_init();
  lv_port_disp_init();

  ui_test_perf();
    /* 创建 LVGL 任务
       栈大小和优先级可按项目调整 */
    xTaskCreatePinnedToCore(
        lvgl_task,          // 任务函数
        "lvgl_task",        // 名称
        4096,               // 栈大小
        nullptr,            // 参数
        2,                  // 优先级
        &lvglTaskHandle,    // 任务句柄
        1                   // 绑定核心，可选 0/1
    );
}

void loop() {
  // put your main code here, to run repeatedly:
}

