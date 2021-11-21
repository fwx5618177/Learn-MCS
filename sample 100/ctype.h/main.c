/**
 * @file main.c
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <reg51.h>
#include <ctype.h>

void main(void) {
    while (1) {
        P3 = isalpha('_') ? 0xf0 : 0x0f;
    }
}