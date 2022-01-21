/*********************************************************************************
  *Copyright(C), 2021, Company
  *FileName:  1-3-myerror.h
  *Author:  yangqi
  *Version:  V1.0.0
  *Date: 2022-01-21 11:03:11
  *Description:


  *History:
     1.Date:
       Author:
       Modification:
     2.
**********************************************************************************/

#ifndef __3_MYERROR_H__
#define __3_MYERROR_H__

/***************************************includes***********************************/
//#include"xxx.h"
#include "1-1-print.h"

#include <string.h>
#include <time.h>
#include <sys/time.h>
#include <stdint.h>

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
	//melon init fail
    MELON_INIT_FAIL,
	//mysql init fail
	MYSQL_INIT_FAIL,
	//mysql connect fail
	MYSQL_CONNECT_FAIL,
	//mysql insert fail
	MYSQL_INSERT_FAIL,
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
    //melon
    case MELON_INIT_FAIL: 		return "Melon init failed.";
	//mysql
	case MYSQL_INIT_FAIL: 		return "mysql init failed.";
	case MYSQL_CONNECT_FAIL: 	return "mysql connect failed.";
	case MYSQL_INSERT_FAIL: 	return "mysql insert failed.";

	default:
		break;
	}
	snprintf(tmp, sizeof(tmp), "error code: %d", x);
	return tmp;
}

//传入想要切割的字符，加一个参数
static char* file_relative_path(char * dir, char *str)
{
	char path[100];
	char *delim = "/";
	char *tempin = NULL;
	char *temp = NULL;
	strncpy(path, dir ,sizeof(path) - 1);
	temp = path;
	while(NULL != ( temp = strtok_r( temp, delim, &tempin) ))
	{
		//printf("\n temp[%s] tempin[%s]\n",temp,tempin);
	    //printf("\n temp[%s] \n",temp);
        //if(!strcmp(temp,"cmake"))
		//if(!strcmp(temp,"1-c"))
        if(!strcmp(temp, str))
        {
            //printi("111111 %s\n", tempin);
			return tempin;
        }
		temp = NULL;
    }
    return __FILE__;
}

//显示当前时间
static char* get_time(void)
{
    /*
    （1） int gettimeofday（struct timeval*tv, struct timezone *tz）
    所属头文件:   <sys/time.h>
    其参数tv是保存获取时间结果的结构体，参数tz用于保存时区结果：
    struct timezone
    {
        int tz_minuteswest;//格林威治时间往西方的时差
        int tz_dsttime;//DST 时间的修正方式
    };
    timezone 参数若不使用则传入NULL即可。

    而结构体timeval的定义为：
    struct timeval
    {
        long int tv_sec; // 秒数
        long int tv_usec; // 微秒数
    };
    其返回值是从1970-1-1日到现在的的时间，可以精确到微妙级。

    （2）struct tm *localtime_r(const time_t *timep, struct tm *result);（可重入）
    所属头文件 <time.h>
    其中result是保存转换时间结果的结构体
    struct tm
    {
        int tm_sec;       // 秒 – 取值区间为[0,59]
        int tm_min;       // 分 - 取值区间为[0,59]
        int tm_hour;      // 时 - 取值区间为[0,23]
        int tm_mday;     // 一个月中的日期 - 取值区间为[1,31]
        int tm_mon;       // 月份（从一月开始，0代表一月） - 取值区间为[0,11]
        int tm_year;        // 年份，其值等于实际年份减去1900
        int tm_wday;      // 星期 – 取值区间为[0,6]，其中0代表星期天，1代表星期一，以此类推
        int tm_yday;
        //从每年的1月1日开始的天数 – 取值区间为[0,365]，其中0代表1月1日，1代表1月2日，以此类推
        int tm_isdst;
        //夏令时标识符，实行夏令时的时候，tm_isdst为正。
        //不实行夏令时的进候，tm_isdst为0；不了解情况时，tm_isdst()为负。
    }*/
    struct timeval tv;
    gettimeofday(&tv,NULL);//获取1970-1-1到现在的时间结果保存到tv中
    uint64_t sec=tv.tv_sec;
    uint64_t min=tv.tv_sec/60;
    struct tm cur_tm;//保存转换后的时间结果
    localtime_r((time_t*)&sec,&cur_tm);
    char cur_time[20];
    snprintf(cur_time,20,"%d-%02d-%02d %02d:%02d:%02d",cur_tm.tm_year+1900,
        cur_tm.tm_mon+1,cur_tm.tm_mday,cur_tm.tm_hour,cur_tm.tm_min,cur_tm.tm_sec);
    //printi("current time is %s\n",cur_time);//打印当前时间
	char *tempin = NULL;
	tempin = cur_time;
	//printi("time %s\n", tempin);
	return tempin;
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
#define myerror(i) do{printe("%s ", get_time());\
	printe(" %s\n", file_relative_path(__FILE__, "c-cmake-main"));\
	printe("%s %d %s\n",__FUNCTION__, __LINE__, mystrerror(i));}while(0);
#else
#define myerror(i) do{printe("%s %s %s\n%s %d %s\n", \
	__DATE__, __TIME__, file_relative_path(__FILE__), \
	__FUNCTION__, __LINE__, mystrerror(i));}while(0);
#endif

#endif
/* [] END OF FILE */