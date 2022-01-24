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
#include "1-4-log.h"

#include <string.h>
#include <time.h>
#include <stdint.h>
#include <windows.h>
#include <stdlib.h>

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
	//file
	//file open fail
	ERROR_FILE_OPEN_FAIL,
	//file close fail
	ERROR_FILE_CLOSE_FAIL,
	//log
	//set log level fail
	ERROR_LOG_SET_LEVEL_FAIL,
	// list
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
static unsigned char log_buf[1024];
static char cur_time[20];
static char error_path[100];
static char line_buf[10];
static char error_buf[100];
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
	switch (x)
	{
		//cmd
		case ERROR_CMD_NO_FIND:				strcpy(error_buf, "cmd no find");				return error_buf;
		//file
		case ERROR_FILE_OPEN_FAIL:			strcpy(error_buf, "file open fail"); 			return error_buf;
		case ERROR_FILE_CLOSE_FAIL:			strcpy(error_buf, "file close fail"); 			return error_buf;
		//log
		case ERROR_LOG_SET_LEVEL_FAIL:		strcpy(error_buf, "log level set fail");		return error_buf;
		//list
		case ERROR_LIST_INIT_FAIL:			strcpy(error_buf, "list init fail"); 			return error_buf;
		case ERROR_LIST_CREATE_NODE_FAIL:	strcpy(error_buf, "list create node fail"); 	return error_buf;
		case ERROR_LIST_HEAD_INSERT_FAIL:   strcpy(error_buf, "list head insert fail"); 	return error_buf;
		case ERROR_LIST_TAIL_INSERT_FAIL:	strcpy(error_buf, "list tail insert fail"); 	return error_buf;
		case ERROR_LIST_HEAD_DELETE_FAIL:	strcpy(error_buf, "list head delete fail"); 	return error_buf;
		case ERROR_LIST_TAIL_DELETE_FAIL:	strcpy(error_buf, "list tail delete fail"); 	return error_buf;
		case ERROR_LIST_NO_FIND_NODE:		strcpy(error_buf, "list by id no find node"); 	return error_buf;
    	//melon
    	case ERROR_MELON_INIT_FAIL: 		strcpy(error_buf, "Melon init failed."); 		return error_buf;
		//mysql	
		case ERROR_MYSQL_INIT_FAIL: 		strcpy(error_buf, "mysql init failed."); 		return error_buf;
		case ERROR_MYSQL_CONNECT_FAIL: 		strcpy(error_buf, "mysql connect failed."); 	return error_buf;
		case ERROR_MYSQL_INSERT_FAIL: 		strcpy(error_buf, "mysql insert failed."); 		return error_buf;

		default:
			break;
	}
	snprintf(error_buf, sizeof(error_buf), "error code: %d", x);
	return error_buf;
}


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
    //printf("time:%s\n",cur_time);
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
 * @version v1.2 add log ,end "\r\n",have a blank line;
 * "\n",only change a new line
*/
#if 1
#define myerror(i) do{printe("[%s] ", get_time()); \
	printe("[%s] \n", file_relative_path(__FILE__, "c-cmake-main")); \
	printe("[%s] [%d] %s\n",__FUNCTION__, __LINE__, mystrerror(i)); \
	strcpy (log_buf, "["); \
	strcat(log_buf, cur_time); \
	strcat(log_buf, "] ["); \
	strcat(log_buf, error_path); \
	strcat(log_buf, "] ["); \
	strcat(log_buf, __FUNCTION__); \
	strcat(log_buf, "] ["); \
	itoa(__LINE__, line_buf, 10); \
	strcat(log_buf, line_buf); \
	strcat(log_buf, "] ["); \
	strcat(log_buf, error_buf); \
	strcat(log_buf, "]\n"); \
	if( log_get_log_state() != NULL){\
		fwrite(log_buf, 1, strlen(log_buf), log_get_log_state());\
	}\
	printe("log_buf:%s\n", log_buf); \
	memset(log_buf, 0, sizeof(log_buf)); \
}while(0);
#else
#define myerror(i) do{printe("%s %s %s\n%s %d %s\n", \
	__DATE__, __TIME__, file_relative_path(__FILE__,".."), \
	__FUNCTION__, __LINE__, mystrerror(i));}while(0);
#endif

#endif
/* [] END OF FILE */