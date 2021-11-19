#include "Bubble.h"

/**
 * @brief 3.0 控制第一个灯亮
 * 
 */
void BubbleStart(void);

/**
 * @brief 延时函数
 * 
 */
void delay(void);

/**
 * @brief 4.0 控制一个灯闪烁
 * 
 */
void flink(void);

/**
 * @brief 5.0 认识I/O口引脚
 * 
 */
void learnIO(void);

/**
 * @brief 6.0 P3口点亮8位LED
 * 
 */
void startEight(void);

void BubbleStart(void) {
    while(1) P1 = 0xfe;
};

void delay(void) {
    unsigned int circle;

    for(circle = 0; circle < MAX_MACHIN_CIRCLE; circle++) ;
};

void flink(void) {
    while(1) {
        P1 = 0xfe;  // P1 = 1111 1110B, P1.0输出低电平
        delay();
        P1 = 0xff;  // P1 = 1111 1111B, P1.0输出高电平
        delay();
    }
};

void learnIO(void) {
    while(1) {
        P1 = 0xff;  // P1 = 1111 1111, 熄灭LED
        P0 = P1;    // P1口状态送入P0口
        P2 = P1;    // P1口状态送入P2口
        P3 = P1;
    }
};

void startEight(void) {
    P3 = 0xfe;  // 第一个灯亮
    delay();
    P3 = 0xfd;  // 第二个灯亮
    delay();
    P3 = 0xfb;  // 3
    delay();
    P3 = 0xf7;  // 4
    delay();
    P3 = 0xef;  // 5
    delay();
    P3 = 0xdf;  // 6s
    delay();
    P3 = 0xbf;  // 7 
    delay();
    P3 = 0x7f;  // 8
    delay();
};