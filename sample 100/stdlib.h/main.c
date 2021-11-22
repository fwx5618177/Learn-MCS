/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <reg51.h>
#include <stdlib.h>

void delay(void) {
    unsigned char m, n;

    for (m = 0; m < 200; m++) for (n = 0; n < 250; n++) ;
}

void main(void) {
    unsigned char i;

    while (1) {
        for (i = 0; i <10; i++) {
            P3 = rand() / 160;
            delay();
        }
    }
}