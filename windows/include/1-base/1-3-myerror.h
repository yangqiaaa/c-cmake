/*********************************************************************************
  *Copyright(C), 2021, Company
  *FileName:  3-myerror.h
  *Author:  yangqi
  *Version:  V1.0.0
  *Date: 2022-01-21 10:08:54
  *Description:


  *History:
     1.Date:
       Author:
       Modification:
     2.
**********************************************************************************/

#ifndef __1_3_MYERROR_H__
#define __1_3_MYERROR_H__

/***************************************includes***********************************/
//#include"xxx.h"
#include "1-1-print.h"

#include <string.h>
#include <time.h>
#include <stdint.h>
#include <windows.h>

/***************************************Macros***********************************/
//#define
/** 1
 * @brief picture file synthesizer
 * @param int x
 * @return have const char *strerror,no id
 * @date 2021/09/27
 * @version V1.0
*/
enum MYERROR
{
    //no use
	ERROR_NONE=0,
	//main cmd no find
	ERROR_CMD_NO_FIND,
	//list init fail
	ERROR_LIST_INIT_FAIL,
	//list create node fail
	ERROR_LIST_CREATE_NODE_FAIL,
	//list header insert fail
	ERROR_LIST_HEAD_INSERT_FAIL,
	//list tail insert fail
	ERROR_LIST_TAIL_INSERT_FAIL,
	//list head delete fail
	ERROR_LIST_HEAD_DELETE_FAIL,
	//list tail delete fail
	ERROR_LIST_TAIL_DELETE_FAIL,
	//list no find node
	ERROR_LIST_NO_FIND_NODE,
	//melon init fail
    ERROR_MELON_INIT_FAIL,
	//mysql init fail
	ERROR_MYSQL_INIT_FAIL,
	//mysql connect fail
	ERROR_MYSQL_CONNECT_FAIL,
	//mysql insert fail
	ERROR_MYSQL_INSERT_FAIL,
};

/***************************************Variables***********************************/
//static int i


/***************************************Functions***********************************/
//void test(void);
/** 
 * @brief picture file synthesizer
 * @param int x
 * @return have const char *strerror,no id
 * @date 2021/09/27
 * @version V1.0
*/
static const char *mystrerror(int x) 
{
    static char tmp[100]={"0"};
	switch (x)
	{
		//cmd
		case ERROR_CMD_NO_FIND:				return "cmd no find";
		//list
		case ERROR_LIST_INIT_FAIL:			return "list init fail";
		case ERROR_LIST_CREATE_NODE_FAIL:	return "list create node fail";
		case ERROR_LIST_HEAD_INSERT_FAIL:   return "list head insert fail";
		case ERROR_LIST_TAIL_INSERT_FAIL:	return "list tail insert fail";
		case ERROR_LIST_HEAD_DELETE_FAIL:	return "list head delete fail";
		case ERROR_LIST_TAIL_DELETE_FAIL:	return "list tail delete fail";
		case ERROR_LIST_NO_FIND_NODE:		return "list by id no find node";
    	//melon
    	case ERROR_MELON_INIT_FAIL: 		return "Melon init failed.";
		//mysql	
		case ERROR_MYSQL_INIT_FAIL: 		return "mysql init failed.";
		case ERROR_MYSQL_CONNECT_FAIL: 		return "mysql connect failed.";
		case ERROR_MYSQL_INSERT_FAIL: 		return "mysql insert failed.";

	default:
		break;
	}
	snprintf(tmp, sizeof(tmp), "error code: %d", x);
	return tmp;
}

static char error_path[100];
//传入想要切割的字符，加一个参数
static char* file_relative_path(char * dir, char *str)
{
	char path[100];
	char *delim = "/";
	char *tempin = NULL;
	char *temp = NULL;
	char ret[100];
	strncpy(path, dir ,sizeof(path) - 1);
	temp = path;
	while(NULL != ( temp = strtok_r( temp, delim, &tempin) ))
	{
		//printf("temp[%s] tempin[%s]\n",temp,tempin);
	    //printf("\n temp[%s] \n",temp);
        //if(!strcmp(temp,"cmake"))
		//if(!strcmp(temp,"1-c"))
        if(!strcmp(temp, str))
        {
            //printi("111111 %s\n", tempin);
			//return tempin;
			strncpy( error_path, tempin, sizeof(error_path)-1 );
			//printi("111111 %s\n", tempin);
			return error_path;
        }
		temp = NULL;
    }
    return __FILE__;
}

static char cur_time[20];
//显示当前时间
static char* get_time(void)
{
	//char cur_time[20];
    SYSTEMTIME sys;
    //sys.wDayOfWeek;
    //sys.wMilliseconds;
	GetLocalTime(&sys);
    snprintf(cur_time,20,"%4d-%02d-%02d %02d:%02d:%02d",sys.wYear,
        sys.wMonth,sys.wDay,sys.wHour,sys.wMinute,sys.wSecond);
	//printf("%4d/%02d/%02d %02d:%02d:%02d.%03d 星期%1d/n", sys.wYear, sys.wMonth, \
    //    sys.wDay, sys.wHour, sys.wMinute, sys.wSecond, sys.wMilliseconds, sys.wDayOfWeek);
    printf("time:%s\n",cur_time);
    return cur_time;
	//char *tempout = NULL;
	//tempout = cur_time;
	//printf("time %s\n", tempout);
	//return tempout;
}

/** 
 * @brief picture file synthesizer
 * @param int x
 * @return have const char *strerror,no id
 * @date 2021/09/27
 * @version V1.0 调用快
 * @version V1.1 __DATE__, __TIME__ 打印时间需要转换
*/
#if 1
#define myerror(i) do{printe("[%s] ", get_time());\
	printe("[%s] \n", file_relative_path(__FILE__, "c-cmake-main"));\
	printe("[%s] [%d] %s\n",__FUNCTION__, __LINE__, mystrerror(i));}while(0);
#else
#define myerror(i) do{printe("%s %s %s\n%s %d %s\n", \
	__DATE__, __TIME__, file_relative_path(__FILE__,".."), \
	__FUNCTION__, __LINE__, mystrerror(i));}while(0);
#endif

#endif
/* [] END OF FILE */