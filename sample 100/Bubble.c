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

/**
 * @brief 7.0 对P3口地址的操作流水点亮8位LED
 * 
 */
void opsSevent(void);

/**
 * @brief 8.0 不同数据类型控制灯闪烁时间
 * 
 */
void int_delay(void);

void dataType(void);

/**
 * @brief 9.0 分别显示加法和减法运算结果
 * 
 */
void calculation(void);

/**
 * @brief 10.0 P0 P1 现实乘法运算效果
 * 
 */
void multi(void);

/**
 * @brief 11.0 显示除法运算结果
 * 
 */
void decease(void);

/**
 * @brief 12.0 自增运算控制P0 口 8位LED流水花样
 * 
 */
void selfIncrement(void);

/**
 * @brief 13.0 P0口显示逻辑与运算结果
 * 
 */
void andResult(void);

/**
 * @brief 14.0 条件运算
 * 
 */
void conditionResult(void);

/**
 * @brief 15.0 异或
 * 
 */
void orResult(void);

/**
 * @brief 16.0 <<
 * 
 */
void leftRe(void);

/**
 * @brief 17.0 万能逻辑电路实验
 * 
 */
void adapterRe(void);

/**
 * @brief 18.0 >>
 * 
 */
void RightRe(void);

/**
 * @brief 19.0 if, 控制方向
 * 
 */
void ifDirections(void);

/**
 * @brief 20.0 switch控制
 * 
 */
void switchControl(void);

/**
 * @brief 21.0 for 鸣笛
 * 
 */
void alertSequence(void);

/**
 * @brief 22.0 while 灯
 * 
 */
void whileLights(void);

/**
 * @brief 23.0 do-while
 * 
 */
void doWhileLight(void);

/**
 * @brief 24.0 char[] ops
 * 
 */
void charArrayOps(void);

/**
 * @brief 25.0 char const variables
 * 
 */
void charConstVar(void);

/**
 * @brief 26.0 pointer calculation
 * 
 */
void pointerCal(void);

/**
 * @brief 26.0 显示指针运算结果
 * 
 */
void pointerRe(void);

/**
 * @brief 32.0 指针做函数参数控制流水灯
 * 
 */
void led_flow_pointer(unsigned char *p);

/**
 * @brief 函数指针控制流水灯
 * 
 */
void led_flow_function(void);
void led_flow_use(void);

/**
 * @brief 34.0 指针数组作为函数参数显示多个字符串
 * 
 */
void array_pointer(void);
void array_pointer_use(unsigned char *x[]);

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

void opsSevent(void) {
    /**
     * P3 在存储器中的地址是b0H 通过sfr定义8051内核单片机
     * 的所有内部8位特殊功能寄存器，对地址x的操作也是对P1口的操作
     */
    sfr x = 0xb0; 
    
    while(1) {
        x = 0xfe;   // 1
        delay();
        x = 0xfd;   // 2
        delay();
        x = 0xfb;   //3
        delay();
        x = 0xf7;   //4
        delay();
        x = 0xef;   //5
        delay();
        x = 0xdf;   //6
        delay();
        x = 0xbf;   //7
        delay();
        x = 0x7f;   //8
        delay();
    }
}

void int_delay(void) {
    unsigned int m;
    for(m = 0; m < MAX_DELAY; m++)  ;
}

/**
 * @brief 用字符型数据延时一段时间
 * 
 */
void dataType(void) {
    unsigned char i;

    while(1) {
        for (i = 0; i < 3; i++)
        {
            P1 = 0xfe;  // P1.0 口的灯点亮
            int_delay();
            P1 = 0xff;  // 熄灭
            int_delay();
        }
        
        for (i = 0; i < 3; i++)
        {
            P1 = 0xef;   // P1.4 口的灯点亮
            int_delay();
            P1 = 0xff;  // 熄灭
            int_delay();
        }
        
    }
}

void calculation(void) {
    unsigned char m, n;

    m = 43; // 十进制数 2x16+11 = 43 
    n = 60;  // 十进制数 3x16 + 12 = 60
    P1 = m + n; // P1=103=0110 0111, P1.3,P1.4,P1.7灯点亮
    P0 = n - m; // P0=17=0001 0001, P0.0, P0.4灯熄灭
}

void multi(void) {
    unsigned char m, n;
    unsigned int s;

    m = 64;
    n = 71;
    s = m * n;  // s =  64*71 = 4544, 高8位送P1，低8位送P0. 4544 = 17*256+192
    P1 = s / 256;
    P0 = s % 256;
}

void decease(void) {
    P1 = 36 / 5;    // 求整数
    P0 = ((36 % 5) * 10) / 5;   // 求小数
    while (1)
    {
        ;
    }
}

void selfIncrement(void) {
    unsigned char i;
    for(i = 0; i < MAX_CHAR_CIRCLE; i++) {
        P0 = i;
        delay();
    }
}

void andResult(void) {
    P0 = (4 > 0) && (9 > 0xab);
    while (1) ;
}

void conditionResult(void) {
    P0 = (8 > 4) ? 8 : 4;   // 条件运算结果送到P0口, P0 = 8 = 0000 1000B
    while(1) ;
}

void orResult(void) {
    P0 = 0xa2 ^ 0x3c;
    while (1) ;
}

void leftRe(void) {
    P0 = 0x3b << 2;
    while (1) ;
}

void adapterRe(void) {
    sbit F = P1 ^ 4;    // F位定义为P1.4
    sbit X = P1 ^ 5; // X->P1.5
    sbit Y = P1 ^ 6; // Y->P1.6
    sbit Z = P1 ^ 7; // Z->P1.7

    while(1) {
        F = ((~X) & Y) | Z;
        ;
    }
}

void RightRe(void) {
    unsigned char i;

    while (1) {
        P1 = 0xff;
        delay();

        for (i = 0; i < 8; i++) {
            P1 = P1 >> 1;   //>>,高位补0
            delay();
        }
    }
}

void ifDirections(void) {
    sbit S1 = P1 ^ 4; // S1->P1.4
    sbit S2 = P1 ^ 5; // S2->P1.5

    while(1) {
        if (S1 == 0) P0 = 0x0f; //按下S1,P0高4位亮起
        if (S2 == 0) P0 = 0xf0; // 按下S2,P0低4位亮起
    }
}

void switchControl(void) {
    sbit S1 = P1 ^ 4; // S1->P1.4

    unsigned char i = 0;

    while(1) {
        if (S1 == 0) {
            delay();
            if (S1 == 0)    i++;
            if (i == 9) i = 1;
        }

        switch (i)
        {
        case 1:
            P0 = 0xfe;  // 1
            break;
        case 2: P0 = 0xfd;   //2
            break;
        case 3: P0 = 0xfb;   // 3
            break;
        case 4: P0 = 0xf7;   // 4
            break;
        case 5: P0 = 0xef;   // 5
            break;
        case 6: P0 = 0xdf;   // 6
            break;
        case 7: P0 = 0xbf;   // 7
            break;
        case 8: P0 = 0x7f;   // 8
            break;
        
        default:
            P0 = 0xff; // closed
            break;
        }
    }
}

void alertSequence(void) {
    unsigned int i;
    sbit sound = P3 ^ 7;

    while (1) {
        for (i = 0; i <830; i++) {
            sound = 0;
            delay();
            sound = 1;
            delay();
        }

        for(i = 0; i < 200; i++) {
            sound = 0;
            delay();
            sound = 1;
            delay();
        }
    }
}

void whileLights(void) {
    unsigned char i;
    while (1) {
        i = 0;

        while (i < 0xff) {
            P0 = i;
            delay();
            i++;
        }
    }
}

void doWhileLight(void) {
    do {
        P0 = 0xfe;  //1
        delay();
        P0 = 0xfd;   //2
        delay();
        P0 = 0xfb;   // 3
        delay();
        P0 = 0xf7;   // 4
        delay();
        P0 = 0xef;   // 5
        delay();
        P0 = 0xdf;   //6
        delay();
        P0 = 0xbf;   // 7
        delay();
        P0 = 0x7f;   // 8
        delay();
    } while(1);
}

void charArrayOps(void) {
    unsigned char i;
    unsigned char code Tab[] = [ 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f ];

    while(1) {
        for(i = 0; i < 8; i++) {
            P0 = Tab[i];
            delay();
        }
    }
}

void charConstVar(void) {
    unsigned char str[] = ["Now, Temperature is :"];
    unsigned char i;

    while(1) {
        i = 0;

        while(str[i] != '\0') {
            P0 = str[i];
            delay();
            i++;
        }
    }
}

void pointerCal(void) {
    unsigned char *p1, *p2;
    unsigned char i, j;
    i = 25;
    j = 15;

    p1 = &i;
    p2 = &j;
    P0 = *p1 + *p2;

    while(1) ;
}

void pointerRe(void) {
    unsigned char *p1, *p2;
    unsigned char i, j;

    i = 25;
    j = 15;

    p1 = &i;
    p2 = &j;

    P0 = *p1 + *p2;

    while(1) ;
}

void led_flow_pointer(unsigned char *p) {
    unsigned char i;

    while(1) {

        i = 0;
        while(*(p+i) != '\0') {
            P0 = *(p+i);
            delay();
            i++;
        }
    }
}

void led_flow_function(void) {
    unsigned char i;
    unsigned char code Tab[] = [ 0xfe, 0xfd, 0xfb, 0xf7, 0xef, 0xdf, 0xbf, 0x7f ];

    for (i = 0; i < 8; i++)
    {
        P0 = Tab[i];
        delay();
    }
    
}
void led_flow_use(void) {
    void (*p)(void); // 定义函数指针

    p = led_flow_function;

    while(1) {
        (*p)();
    }

}

void array_pointer(void) {
    unsigned char code str1[] = "Temperature";
    unsigned char code str2[] = "is";
    unsigned char code str3[] = "low";
    unsigned char *p[] = [str1];
}

void array_pointer_use(unsigned char *x[]) {
    unsigned char i, j;

    for (i = 0; i < 4; i++) {
        j = 0;

        while(*(x[i] + j) != '\0') {
            P0 = *(x[i] + j);
            delay();
            j++;
        }
    }
}

