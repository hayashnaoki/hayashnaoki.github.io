#include <U8g2lib.h>
#include "pins.h"
#include "display.h"

U8G2_SH1106_128X64_NONAME_F_4W_SW_SPI u8g2(
    U8G2_R0,
    PIN_SPI_SCK,
    PIN_SPI_MOSI,
    PIN_SPI_CS,
    PIN_SPI_MISO,
    U8X8_PIN_NONE
);

void displayInit() {
    u8g2.begin();
}

void displayVoltages(float vbat, float vsys) {
    char buf[16];
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_10x20_tr);

    snprintf(buf, sizeof(buf), "VBAT: %.2fV", vbat);
    u8g2.drawStr(0, 20, buf);

    snprintf(buf, sizeof(buf), "VSYS: %.2fV", vsys);
    u8g2.drawStr(0, 40, buf);

    u8g2.sendBuffer();
}