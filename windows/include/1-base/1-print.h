/*********************************************************************************
  *Copyright(C), 2021, Company
  *FileName:  1-print.h
  *Author:  yangqi
  *Version:  V1.0.0
  *Date: 2022-01-20 19:51:32
  *Description:


  *History:
     1.Date:
       Author:
       Modification:
     2.
**********************************************************************************/

#ifndef  __1_PRINT_H__
#define  __1_PRINT_H__

/***************************************includes***********************************/
//#include"xxx.h"
#include <stdio.h>

/***************************************Macros***********************************/
//#define
//#######   color print   ####################################
//e 033
#define NONE                 "\033[0m"
#define BLACK                "\e[0;30m"
#define L_BLACK              "\e[1;30m"
#define RED                  "\e[0;32;31m"
#define L_RED                "\033[1;31m"
#define GREEN                "\e[0;32m"
#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"
#define BLUE                 "\e[0;34m"
#define L_BLUE               "\e[1;34m"
#define PURPLE               "\e[0;35m"
#define L_PURPLE             "\e[1;35m"
#define CYAN                 "\e[0;36m"
#define L_CYAN               "\e[1;36m"
#define GRAY                 "\e[0;37m"
#define WHITE                "\e[1;37m"

#define BOLD                 "\e[1m"
#define UNDERLINE            "\e[4m"
#define BLINK                "\e[5m"
#define REVERSE              "\e[7m"
#define HIDE                 "\e[8m"
#define CLEAR                "\e[2J"
#define CLRLINE              "\r\e[K" //or "\e[1K\r"




#define printr(format, ...) do{printf(RED    format NONE,##__VA_ARGS__);}while(0)
#define printg(format, ...) do{printf(GREEN  format NONE,##__VA_ARGS__);}while(0)
#define printb(format, ...) do{printf(BLUE   format NONE,##__VA_ARGS__);}while(0)
#define printk(format, ...) do{printf(BLACK  format NONE,##__VA_ARGS__);}while(0)
//#define printw(format, arg...) do{printf(WHITE format NONE,##__VA_ARGS__);}while(0)
#define printy(format, ...) do{printf(YELLOW format NONE,##__VA_ARGS__);}while(0)
#define printc(format, ...) do{printf(CYAN   format NONE,##__VA_ARGS__);}while(0)
#define printp(format, ...) do{printf(PURPLE format NONE,##__VA_ARGS__);}while(0)

#define printlr(format, ...) do{printf(L_RED    format NONE,##__VA_ARGS__);}while(0)
#define printlg(format, ...) do{printf(L_GREEN  format NONE,##__VA_ARGS__);}while(0)
#define printlb(format, ...) do{printf(L_BLUE   format NONE,##__VA_ARGS__);}while(0)
#define printlk(format, ...) do{printf(L_BLACK  format NONE,##__VA_ARGS__);}while(0)
#define printlw(format, ...) do{printf(L_WHITE  format NONE,##__VA_ARGS__);}while(0)
#define printly(format, ...) do{printf(L_YELLOW format NONE,##__VA_ARGS__);}while(0)
#define printlc(format, ...) do{printf(L_CYAN   format NONE,##__VA_ARGS__);}while(0)
#define printlp(format, ...) do{printf(L_PURPLE format NONE,##__VA_ARGS__);}while(0)

#define print_error(format, ...) do{printf(RED    format NONE,##__VA_ARGS__);}while(0)
#define print_warn(format, ...)  do{printf(YELLOW format NONE,##__VA_ARGS__);}while(0)
#define print_infor(format, ...) do{printf(GREEN  format NONE,##__VA_ARGS__);}while(0)
#define print_debug(format, ...) do{printf(YELLOW format NONE,##__VA_ARGS__);}while(0)

#define printe(format, ...) do{printf(RED    format NONE,##__VA_ARGS__);}while(0)
#define printw(format, ...) do{printf(YELLOW format NONE,##__VA_ARGS__);}while(0)
#define printi(format, ...) do{printf(GREEN  format NONE,##__VA_ARGS__);}while(0)
#define printd(format, ...) do{printf(PURPLE format NONE,##__VA_ARGS__);}while(0)

//…¡À∏¥Ú”°
#define FLICKER_GREEN                "\e[5;32m"
#define FLICKER_NONE                 "\e[0m"
#define printif(format,...) do{printf(FLICKER_GREEN format FLICKER_NONE, ##__VA_ARGS__);}while(0)

/***************************************Variables***********************************/
//static int i


/***************************************Functions***********************************/
//void test(void);

#endif
/* [] END OF FILE */