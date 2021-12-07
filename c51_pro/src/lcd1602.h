#ifndef _LCD1602_H
#define _LCD1602_H
/*

 #define uchar unsigned char
#define uint unsigned int
#define LCD_DATA  P0
sbit LCD_EN=P2^5;
sbit LCD_RS=P2^3;
sbit LCD_RW=P2^4;
/**********************************************

***********************************************/
void delay_ms(uint temp)
{
 uint x,y;
 for(x=temp;x>0;x--)
  for(y=110;y>0;y--);
}
/**********************************************
***********************************************/
void LCD_w_com(uchar com)
{
 LCD_RS=0;
 LCD_RW=0;
 LCD_DATA=com;
 delay_ms(5);
 LCD_EN=1;
 delay_ms(5);
 LCD_EN=0;
}
/**********************************************
***********************************************/
void LCD_w_data(uchar dat)
{
 LCD_RS=1;
 LCD_RW=0;
 LCD_DATA=dat;
 delay_ms(5);
 LCD_EN=1;
 delay_ms(5);
 LCD_EN=0;
}
/**********************************************
***********************************************/
void LCD_init()
{
 LCD_EN=0; 
 LCD_w_com(0x38);
 LCD_w_com(0x0c);
 LCD_w_com(0x06);
 LCD_w_com(0x01); 
}
/**********************************************
***********************************************/
void LCD_disp_cher(uchar x,uchar y,uchar *p)
{
 if(y==1)
 {   
  LCD_w_com(0x80+x);
  while(*p)
  {
  LCD_w_data(*p);
  p++;
  }
 } 
 if(y==2)
 {    
  LCD_w_com(0x80+0x40+x);
  while(*p)
  {
  LCD_w_data(*p);
  p++;
  } 
 }
}
#endif

