#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "pico/stdlib.h"

#include "pico_rgb_keypad.hpp"

using namespace pimoroni;

PicoRGBKeypad teclado;

uint8_t rojo = 0;
uint8_t verde = 0;
uint8_t azul = 0;
uint8_t boton = 0;
const uint8_t RANGO = 17;

void rgb(double ratio);

int main() {
  teclado.init();
  teclado.set_brightness(0.1f);

  while (true){
    for (double i = 0; i < RANGO; i++) {
        rgb(i / RANGO);
        if (boton >= 16) {
            boton = 0;
        }
        teclado.illuminate(boton, rojo, verde, azul);
        boton++;
        teclado.update();
        sleep_ms(6);
    }
  }
  return 0;
}

// La siguiente función sale de aqui: https://stackoverflow.com/questions/40629345/fill-array-dynamicly-with-gradient-color-c
void rgb(double ratio) {
    //we want to normalize ratio so that it fits in to 6 regions
    //where each region is 256 units long
    uint16_t normalized = uint16_t(ratio * 256 * 6);

    //find the distance to the start of the closest region
    uint8_t x = normalized % 256;

    uint8_t red = 0, green = 0, blue = 0;
    switch(normalized / 256) {
        case 0: // Rojo
            red = 255;
            green = x;
            blue = 0;
            break;
        case 1: // Amarillo
            red = 255 - x;
            green = 255;
            blue = 0;
            break;
        case 2: // Verde
            red = 0;
            green = 255;
            blue = x;
            break;
        case 3: // Cyan
            red = 0;
            green = 255 - x;
            blue = 255;
            break;
        case 4: // Blue
            red = x;
            green = 0;
            blue = 255;
            break;
        case 5: // Magenta
            red = 255;
            green = 0;
            blue = 255 - x;
            break;
    }

    rojo = red;
    verde = green;
    azul = blue;
}
