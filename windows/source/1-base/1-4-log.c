/*********************************************************************************
  *Copyright(C),1996-2021, Company
  *FileName:  1-4-log.c
  *Author:  wyp
  *Version:  V1.0
  *Date:  2022-01-24 10:27:00
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
#include "1-2-myinfor.h"
#include "1-3-myerror.h"
#include "1-4-log.h"


/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/
static FILE *log = NULL;
static enum LOG_LEVEL log_level_flag = LOG_LEVEL_INFOR;


/***************************************Functions***********************************/
/** 
 * @brief 
 * @file 1-4-log.c
 * @name 
 * @param[in] void
 * @return void
 * @note 
 * @date 2022-01-24 10:27:30
 * @version V1.0.0
*/
extern FILE *log_init(const char *log_path, const char* mode)
{
    log = fopen(log_path, mode);
    if(log == NULL)
    {
        myerror(ERROR_FILE_OPEN_FAIL);
    }
    else myinfor(INFOR_FILE_OPEN_SUCCESS);
	return log;
}

/** 
 * @brief 
 * @file 1-4-log.c
 * @name 
 * @param[in] void
 * @return void
 * @note 
 * @date 2022-01-24 15:37:12
 * @version V1.0.0
*/
extern int log_close(FILE *log)
{
    int ret;
    ret = fclose(log);
    if(ret < 0)
    {
        myerror(ERROR_FILE_CLOSE_FAIL);
    }
    else myinfor(INFOR_FILE_CLOSE_SUCCESS);
	return ret;
}


/** 
 * @brief 
 * @file 1-4-log.c
 * @name 
 * @param[in] void
 * @return void
 * @note 
 * @date 2022-01-24 15:37:20
 * @version V1.0.0
*/
extern FILE *log_get_log_state(void)
{
    return log;
}


/** 
 * @brief 
 * @file 1-4-log.c
 * @name 
 * @param[in] void
 * @return void
 * @note 
 * @date 2022-01-24 15:37:25
 * @version V1.0.0
*/
extern int log_set_level(enum LOG_LEVEL log_level)
{
    int i;
    for(i = LOG_LEVEL_DEBUG; i < LOG_LEVEL_MAX; i++)
    {
        if(i == log_level)
        {
            log_level_flag = log_level;
            myinfor(INFOR_LOG_SET_LEVEL_SUCCESS);
            return 0;
        }
    }
    myerror(ERROR_LOG_SET_LEVEL_FAIL);
    return ERROR_LOG_SET_LEVEL_FAIL;
}



/** 
 * @brief 
 * @file 1-4-log.c
 * @name 
 * @param[in] void
 * @return void
 * @note 
 * @date 2022-01-24 16:05:53
 * @version V1.0.0
*/
extern enum LOG_LEVEL log_get_level(void)
{
    return log_level_flag;
}


/** 
 * @brief 
 * @file 1-4-log.c
 * @name 
 * @param[in] void
 * @return void
 * @note 
 * @date 2022-01-24 16:05:59
 * @version V1.0.0
*/
extern char *log_get_level_buf(enum LOG_LEVEL level)
{
    if(level == LOG_LEVEL_DEBUG) return "DEBUG";
    else if(level == LOG_LEVEL_INFOR) return "INFOR";
    else if(level == LOG_LEVEL_WARNING) return "WARNING";
    else if(level == LOG_LEVEL_ERROR) return "ERROR";
    else return "UNKNOW";
}

/* [] END OF FILE */