#ifndef DISPLAY_H
#define DISPLAY_H

#include <lvgl.h>
#include "Arduino.h"
#include <Adafruit_ST7789.h>
#include <Adafruit_GFX.h>

// 定义显示屏引脚
#define TFT_SCLK 12
#define TFT_MOSI 11
#define TFT_MISO -1
#define TFT_CS   10
#define TFT_DC   14
#define TFT_RST  9
#define TFT_BL   21

// 创建显示屏对象
extern Adafruit_ST7789 tft;

void display_init();
void display_process();

#endif