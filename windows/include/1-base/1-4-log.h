/*********************************************************************************
    *Copyright(C), 2021, Company
    *FileName:  1-4-log.h
    *Author:  yangqi
    *Version:  V1.0.0
    *Date: 2022-01-24 10:24:35
    *Description:


    *History:
     1.Date:
       Author:
       Modification:
     2.
**********************************************************************************/

#ifndef  __1_4_LOG_H__
#define  __1_4_LOG_H__

/***************************************includes***********************************/
//#include"xxx.h"
#include "1-1-print.h"
/***************************************Macros***********************************/
//#define
enum LOG_LEVEL
{
	LOG_LEVEL_DEBUG,
	LOG_LEVEL_INFOR,
	LOG_LEVEL_WARNING,
	LOG_LEVEL_ERROR,
	LOG_LEVEL_MAX
};

/***************************************Variables***********************************/
//static int i


/***************************************Functions***********************************/
//void test(void);
extern FILE *log_init(const char *log_path, const char* mode);

extern int log_close(FILE *log);

extern FILE *log_get_log_state(void);

extern int log_set_level(enum LOG_LEVEL log_level);

extern char *log_get_level_buf(enum LOG_LEVEL level);

#endif
/* [] END OF FILE */