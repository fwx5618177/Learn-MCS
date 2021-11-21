/**
 * @file main.c
 * @author wenxuan feng (fwx5618177@gmail.com)
 * @brief 内部函数应用举例
 * @version 0.1
 * @date 2021-11-21
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <reg51.h>
#include <intrins.h>

/**
 * @brief 延时150ms
 * 
 */
void delay(void) {
    unsigned char m, n;

    for (m = 0; m < 200; m++) for (n = 0; n <250; n++) ;
}

/**
 * @brief 主函数
 * 
 */
void main(void) {
    P3 = 0xfe;
    while(1) {
        P3 = _crol_(P3, 1); // P3的二进制位循环左移1位后再赋值给P3
        delay();
    }
}