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

uint8_t color_rojo[7] = {0, 0, 0, 0, 0, 0, 0};
uint8_t color_verde[7] = {0, 0, 0, 0, 0, 0, 0};
uint8_t color_azul[7] = {0, 0, 0, 0, 0, 0, 0};
uint16_t indice = 0;

const uint8_t RANGO = 17;

void rgb(double ratio);

int main()
{
    teclado.init();
    teclado.set_brightness(0.1f);

    // ** Barrido diagonal V2 suave NO FUNCIONA
    // while (true)
    // {
    //     rgb(indice / RANGO);
    //     if (indice == 0) {
    //         color_rojo[7] = color_rojo[0];
    //         color_verde[7] = color_verde[0];
    //         color_azul[7] = color_azul[0];
    //     } else {
    //         color_rojo[indice - 1] = color_rojo[indice];
    //         color_verde[indice - 1] = color_verde[indice];
    //         color_azul[indice - 1] = color_azul[indice];
    //     }
        
    //     color_rojo[0] = rojo;
    //     color_verde[0] = verde;
    //     color_azul[0] = azul;

    //     teclado.illuminate(0, color_rojo[0], color_verde[0], color_azul[0]);

    //     teclado.illuminate(1, color_rojo[1], color_verde[1], color_azul[1]);
    //     teclado.illuminate(4, color_rojo[1], color_verde[1], color_azul[1]);

    //     teclado.illuminate(2, color_rojo[2], color_verde[2], color_azul[2]);
    //     teclado.illuminate(5, color_rojo[2], color_verde[2], color_azul[2]);
    //     teclado.illuminate(8, color_rojo[2], color_verde[2], color_azul[2]);

    //     teclado.illuminate(3, color_rojo[3], color_verde[3], color_azul[3]);
    //     teclado.illuminate(6, color_rojo[3], color_verde[3], color_azul[3]);
    //     teclado.illuminate(9, color_rojo[3], color_verde[3], color_azul[3]);
    //     teclado.illuminate(12, color_rojo[3], color_verde[3], color_azul[3]);

    //     teclado.illuminate(7, color_rojo[4], color_verde[4], color_azul[4]);
    //     teclado.illuminate(10, color_rojo[4], color_verde[4], color_azul[4]);
    //     teclado.illuminate(13, color_rojo[4], color_verde[4], color_azul[4]);

    //     teclado.illuminate(11, color_rojo[5], color_verde[5], color_azul[5]);
    //     teclado.illuminate(14, color_rojo[5], color_verde[5], color_azul[5]);

    //     teclado.illuminate(15, color_rojo[6], color_verde[6], color_azul[6]);

    //     teclado.update();
    //     sleep_ms(20);

    //     indice++;
    //     if (indice > 6) indice = 0;
    // }
    // ** Barrido diagonal V2 suave NO FUNCIONA

    // ** Barrido diagonal suave NO FUNCIONA
    // while (true)
    // {
    //     for (uint8_t i = 6; i > 0; i--)
    //     {
    //         rgb(indice / RANGO);
    //         if (indice >= RANGO) {
    //             indice = 0;
    //         } else {
    //             indice++;
    //         }

            
                
    //         color_rojo[0] = rojo;

    //         color_verde[0] = verde;

    //         color_azul[0] = azul;

    //         teclado.illuminate(0, color_rojo[0], color_verde[0], color_azul[0]);

    //         teclado.illuminate(1, color_rojo[1], color_verde[1], color_azul[1]);
    //         teclado.illuminate(4, color_rojo[1], color_verde[1], color_azul[1]);

    //         teclado.illuminate(2, color_rojo[2], color_verde[2], color_azul[2]);
    //         teclado.illuminate(5, color_rojo[2], color_verde[2], color_azul[2]);
    //         teclado.illuminate(8, color_rojo[2], color_verde[2], color_azul[2]);

    //         teclado.illuminate(3, color_rojo[3], color_verde[3], color_azul[3]);
    //         teclado.illuminate(6, color_rojo[3], color_verde[3], color_azul[3]);
    //         teclado.illuminate(9, color_rojo[3], color_verde[3], color_azul[3]);
    //         teclado.illuminate(12, color_rojo[3], color_verde[3], color_azul[3]);

    //         teclado.illuminate(7, color_rojo[4], color_verde[4], color_azul[4]);
    //         teclado.illuminate(10, color_rojo[4], color_verde[4], color_azul[4]);
    //         teclado.illuminate(13, color_rojo[4], color_verde[4], color_azul[4]);

    //         teclado.illuminate(11, color_rojo[5], color_verde[5], color_azul[5]);
    //         teclado.illuminate(14, color_rojo[5], color_verde[5], color_azul[5]);

    //         teclado.illuminate(15, color_rojo[6], color_verde[6], color_azul[6]);

        
    //         color_rojo[i + 1] = color_rojo[i];
    //         color_verde[i + 1] = color_verde[i];
    //         color_azul[i + 1] = color_azul[i];

    //         teclado.update();
    //         sleep_ms(20);
    //     }

        
    // }
    // ** Barrido diagonal suave NO FUNCIONA
    

    // *** Iluminación botón a botón
    //   while (true){
    //     for (double i = 0; i < RANGO; i++) {
    //         rgb(i / RANGO);
    //         if (boton >= 16) {
    //             boton = 0;
    //         }
    //         teclado.illuminate(boton, rojo, verde, azul);
    //         boton++;
    //         teclado.update();
    //         sleep_ms(6);
    //     }
    //   }
    // *** Iluminación botón a botón

    // *** Barrido en diagonal NO SUAVE
    while (true)
    {
        for (double i = 0; i < RANGO; i++)
        {
            rgb(i / RANGO);
            if (boton >= 7)
            {
                boton = 0;
            }
            switch (boton)
            {
            case 0:
                teclado.illuminate(0, rojo, verde, azul);
                break;
            case 1:
                teclado.illuminate(1, rojo, verde, azul);
                teclado.illuminate(4, rojo, verde, azul);
                break;
            case 2:
                teclado.illuminate(2, rojo, verde, azul);
                teclado.illuminate(5, rojo, verde, azul);
                teclado.illuminate(8, rojo, verde, azul);
                break;
            case 3:
                teclado.illuminate(3, rojo, verde, azul);
                teclado.illuminate(6, rojo, verde, azul);
                teclado.illuminate(9, rojo, verde, azul);
                teclado.illuminate(12, rojo, verde, azul);
                break;
            case 4:
                teclado.illuminate(7, rojo, verde, azul);
                teclado.illuminate(10, rojo, verde, azul);
                teclado.illuminate(13, rojo, verde, azul);
                break;
            case 5:
                teclado.illuminate(11, rojo, verde, azul);
                teclado.illuminate(14, rojo, verde, azul);
                break;
            case 6:
                teclado.illuminate(15, rojo, verde, azul);
                break;
            }
            boton++;
            teclado.update();
            sleep_ms(50);
        }
    }
    // *** Barrido en diagonal NO SUAVE
    return 0;
}

// La siguiente función sale de aqui: https://stackoverflow.com/questions/40629345/fill-array-dynamicly-with-gradient-color-c
void rgb(double ratio)
{
    //we want to normalize ratio so that it fits in to 6 regions
    //where each region is 256 units long
    uint16_t normalized = uint16_t(ratio * 256 * 6);

    //find the distance to the start of the closest region
    uint8_t x = normalized % 256;

    uint8_t red = 0, green = 0, blue = 0;
    switch (normalized / 256)
    {
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