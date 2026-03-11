#include "display.h"

Adafruit_ST7789 tft(TFT_CS, TFT_DC, TFT_RST);  // 这是硬件SPI路径
void display_init() {
    SPI.begin(12, -1, 11, 10);  // SCLK, MISO, MOSI, SS
    tft.init(240, 320, SPI_MODE0); // 初始化显示屏，设置分辨率和SPI模式
    tft.setRotation(3); // 设置显示屏旋转方向
    tft.setSPISpeed(80000000);    // 设置SPI速度，单位为Hz，具体值根据显示屏和ESP32的性能调整,实际320*240横屏
    tft.fillScreen(ST77XX_WHITE); // 清屏，设置背景色为黑色
    delay(500);
}