#include "FirstBubble.h"

/**
 * @brief 1.0 第一个灯亮
 * 
 */
void LedStart1(void) {
    LED1 = 0;
    while(1) ;
}
/**
 * @brief delay_10us
 * 
 */
void delay_10us(u16 ten_us) {
    while(ten_us--) ;
}

/**
 * @brief 2.0 灯闪烁
 * 
 */
void spark(void) {
    while(1) {
        LED1 = 0;
        delay_10us(50000);
        LED1 = 1;
        delay_10us(50000);
    }
}

/**
 * @brief 3.0 流水灯
 * 
 */
void moveBubble(void) {
    u8 i = 0;
    
    while (1)
    {
        for ( i = 0; i < MAX_BUBBLE_QUANTITY; i++)
        {
            LED_PORT = ~(0x01 << i);
            delay_10us(50000);
        }
        
    }
    
}

/**
 * @brief _crol_, _cror_
 * 
 */
// void crol_cror(void) {
//     LED_PORT = ~0x01;
//     delay_10us(50000);

//     while(1) {
//         for(u8 i = 0; i < 7; i++) {
//             // LED_PORT = _crol_(LED_PORT, 1);
//             delay_10us(50000);
//         }

//         for (u8 i = 0; i < 7; i++)
//         {
//             LED_PORT = _cror_(LED_PORT, 1);
//             delay_10us(50000);
//         }
        
//     }
// }

/**
 * @brief 蜂鸣器
 * 
 */
void alertAlarm(void) {
    u16 i = 2000;

    while(1) {
        while(i--) {
            BEEP = !BEEP;
            delay_10us(50000);
        }
        i = 0;
        BEEP = 0;
    }
}

/**
 * @brief 显示器
 * 
 */
void screenOps(void) {
    SMG_A_DP_PORT = gsmg_code[0];
    while(1) ;
}