/*********************************************************************************
  *Copyright(C),1996-2021, Company
  *FileName:  1-5-time.c
  *Author:  wyp
  *Version:  V1.0
  *Date:  2022-01-25 10:40:44
  *Description:


  *History:
     1.Date:
       Author:
       Modification:
     2.
**********************************************************************************/


/***************************************Includes***********************************/
//#include"xxx.h"
//#include"xxx.h"
#include <windows.h>
#include <stdio.h>

/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/
static char cur_time[20] = "0";


/***************************************Functions***********************************/

/** 
 * @brief get current time
 * @file 1-5-time.h
 * @name 
 * @param[in] void
 * @return void
 * @note 
 * @date 2022-01-25 10:40:53
 * @version V1.0.0
*/
extern char* time_get_current(void)
{
	//char cur_time[20];
    SYSTEMTIME sys;
    //sys.wDayOfWeek;
    //sys.wMilliseconds;
	GetLocalTime(&sys);
    snprintf(cur_time,20,"%4d-%02d-%02d %02d:%02d:%02d",sys.wYear,
        sys.wMonth,sys.wDay,sys.wHour,sys.wMinute,sys.wSecond);
	//printf("%4d/%02d/%02d %02d:%02d:%02d.%03d ÐÇÆÚ%1d/n", sys.wYear, sys.wMonth, \
    //    sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);
    //printf("time:%s\n",cur_time);
    return cur_time;
	//char *tempout = NULL;
	//tempout = cur_time;
	//printf("time %s\n", tempout);
	//return tempout;
}

/* [] END OF FILE */