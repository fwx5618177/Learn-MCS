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

/**
 * @brief 直流电机实验
 * 
 */
void delay_ms(u16 ms) {
    u16 i, j;
    for (i = ms; i > 0; i--)
    {
        for(j = 110; j > 0; j--)    ;
    }
     
}

void machineTrigger(void) {


    while(1) {
        DC_Motor = 1;
        delay_ms(DC_MOTOR_RUN_TIME);
        DC_Motor = 0;
        delay_ms(DC_MOTOR_RUN_TIME);
        DC_Motor = 1;
        delay_ms(DC_MOTOR_RUN_TIME);
        DC_Motor = 0;
    }
}

/**
 * @brief 电动步机
 * 
 */
void step_motor_28BYJ48_send_pulse(u8 step, u8 dir) {
    u8 temp = step;

    if(dir == 0)
        temp = 7 - step;

    switch(temp) {
        case 0: IN1_A = 1; IN1_B = 0; IN1_C = 0; IN1_D = 0; break;
        case 1: IN1_A = 1; IN1_B = 1; IN1_C = 0; IN1_D = 0; break;
        case 2: IN1_A = 0; IN1_B = 1; IN1_C = 0; IN1_D = 0; break;
        case 3: IN1_A = 0; IN1_B = 1; IN1_C = 1; IN1_D = 0; break;
        case 4: IN1_A = 0; IN1_B = 0; IN1_C = 1; IN1_D = 0; break;
        case 5: IN1_A = 0; IN1_B = 0; IN1_C = 1; IN1_D = 1; break;
        case 6: IN1_A = 0; IN1_B = 0; IN1_C = 0; IN1_D = 1; break;
        case 7: IN1_A = 1; IN1_B = 0; IN1_C = 0; IN1_D = 1; break;
    }
}

u8 key_scan(u8 mode) {
    static u8 key = 1;
    if(mode) key = 1;

    if(key == 1 && (KEY_1 == 0 || KEY_2 == 0 || KEY_3 == 0 || KEY_4 == 0)) {
        delay_10us(1000);

        key = 0;

        if(KEY_1 == 0) return KEY1_PRESS;
        else if(KEY_2 == 0) return KEY2_PRESS;
        else if(KEY_3 == 0) return KEY3_PRESS;
        else if(KEY_4 == 0) return KEY4_PRESS;
    } else if(KEY_1 == 1 && KEY_2 == 1 && KEY_3 == 1 && KEY_4 ==1) {
        key = 1;
    }

    return KEY1_UNPRESS;
}

void stepMachine(void){
    u8 key = 0;
    u8 dir = 0;
    u8 speed = STEP_MAXSPEED;
    u8 step = 0;

    while(1) {
        key = key_scan(0);

        if(key == KEY1_PRESS) {
            dir = !dir;
        } else if (key == KEY2_PRESS) {
            if (speed > STEP_MAXSPEED) speed -= 1;
        } else if (key == KEY3_PRESS) {
            if (speed < STEP_MINSPEED) speed += 1;
        }

        step_motor_28BYJ48_send_pulse(step++, dir);

        if(step == 8) step = 0;

        delay_ms(speed);
    }
}