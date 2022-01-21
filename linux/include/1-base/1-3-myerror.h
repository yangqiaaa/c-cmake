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

//������Ҫ�и���ַ�����һ������
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

//��ʾ��ǰʱ��
static char* get_time(void)
{
    /*
    ��1�� int gettimeofday��struct timeval*tv, struct timezone *tz��
    ����ͷ�ļ�:   <sys/time.h>
    �����tv�Ǳ����ȡʱ�����Ľṹ�壬����tz���ڱ���ʱ�������
    struct timezone
    {
        int tz_minuteswest;//��������ʱ����������ʱ��
        int tz_dsttime;//DST ʱ���������ʽ
    };
    timezone ��������ʹ������NULL���ɡ�

    ���ṹ��timeval�Ķ���Ϊ��
    struct timeval
    {
        long int tv_sec; // ����
        long int tv_usec; // ΢����
    };
    �䷵��ֵ�Ǵ�1970-1-1�յ����ڵĵ�ʱ�䣬���Ծ�ȷ��΢���

    ��2��struct tm *localtime_r(const time_t *timep, struct tm *result);�������룩
    ����ͷ�ļ� <time.h>
    ����result�Ǳ���ת��ʱ�����Ľṹ��
    struct tm
    {
        int tm_sec;       // �� �C ȡֵ����Ϊ[0,59]
        int tm_min;       // �� - ȡֵ����Ϊ[0,59]
        int tm_hour;      // ʱ - ȡֵ����Ϊ[0,23]
        int tm_mday;     // һ�����е����� - ȡֵ����Ϊ[1,31]
        int tm_mon;       // �·ݣ���һ�¿�ʼ��0����һ�£� - ȡֵ����Ϊ[0,11]
        int tm_year;        // ��ݣ���ֵ����ʵ����ݼ�ȥ1900
        int tm_wday;      // ���� �C ȡֵ����Ϊ[0,6]������0���������죬1��������һ���Դ�����
        int tm_yday;
        //��ÿ���1��1�տ�ʼ������ �C ȡֵ����Ϊ[0,365]������0����1��1�գ�1����1��2�գ��Դ�����
        int tm_isdst;
        //����ʱ��ʶ����ʵ������ʱ��ʱ��tm_isdstΪ����
        //��ʵ������ʱ�Ľ���tm_isdstΪ0�����˽����ʱ��tm_isdst()Ϊ����
    }*/
    struct timeval tv;
    gettimeofday(&tv,NULL);//��ȡ1970-1-1�����ڵ�ʱ�������浽tv��
    uint64_t sec=tv.tv_sec;
    uint64_t min=tv.tv_sec/60;
    struct tm cur_tm;//����ת�����ʱ����
    localtime_r((time_t*)&sec,&cur_tm);
    char cur_time[20];
    snprintf(cur_time,20,"%d-%02d-%02d %02d:%02d:%02d",cur_tm.tm_year+1900,
        cur_tm.tm_mon+1,cur_tm.tm_mday,cur_tm.tm_hour,cur_tm.tm_min,cur_tm.tm_sec);
    //printi("current time is %s\n",cur_time);//��ӡ��ǰʱ��
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
 * @version V1.0 ���ÿ�
 * @version V1.1 __DATE__, __TIME__ ��ӡʱ����Ҫת��
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