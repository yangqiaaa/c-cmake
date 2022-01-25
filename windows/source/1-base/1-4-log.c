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
#include "1-1-print.h"
#include "1-4-log.h"

#include <stdlib.h>
#include <string.h>


/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/
static FILE *log = NULL;
static enum LOG_LEVEL log_level_flag = LOG_LEVEL_INFOR;

static unsigned char log_buf[1024] = "0";
static char log_level_buf[8] = "0";
static char cur_time[20] = "0";
static char error_path[100] = "0";
static char function_buf[15] = "0";
static char line_buf[10] = "0";

static char error_buf[100] = "0";
static char infor_buf[100] = "0";
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
        //myerror(ERROR_FILE_OPEN_FAIL);
        printe("log init fail\n");
    }
    //else printi("log init success\n");
    //else myinfor(INFOR_FILE_OPEN_SUCCESS);
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
        //myerror(ERROR_FILE_CLOSE_FAIL);
        printe("log close fail\n");
    }
    //else myinfor(INFOR_FILE_CLOSE_SUCCESS);
    ///else printi("log close success\n");
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


/** 
 * @brief picture file synthesizer
 * @param int x
 * @return have const char *strerror,no id
 * @date 2021/09/27
 * @version V1.0
*/
extern const char *mystrerror(int x) 
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


/** 
 * @brief 
 * @file 1-4-log.c
 * @name 
 * @param[in] void
 * @return void
 * @note 
 * @date 2022-01-25 13:16:52
 * @version V1.0.0
*/
extern const char *mystrinfor(int x) 
{
	switch (x)
	{
		//file
		case INFOR_FILE_OPEN_SUCCESS:			strcpy(infor_buf, "file open success");         return infor_buf;
		case INFOR_FILE_CLOSE_SUCCESS:			strcpy(infor_buf, "file close success");        return infor_buf;
		//log
		case INFOR_LOG_SET_LEVEL_SUCCESS:		strcpy(infor_buf, "log set level success");     return infor_buf;
		//list
		case INFOR_LIST_INIT_SUCCESS:			strcpy(infor_buf, "list init success");         return infor_buf;			
		case INFOR_LIST_CREATE_NODE_SUCCESS:	strcpy(infor_buf, "list create node success");  return infor_buf;
		case INFOR_LIST_HEAD_INSERT_SUCCESS: 	strcpy(infor_buf, "list head insert success");  return infor_buf;
		case INFOR_LIST_TAIL_INSERT_SUCCESS:	strcpy(infor_buf, "list tail insert success");  return infor_buf;
		case INFOR_LIST_HEAD_DELETE_SUCCESS:	strcpy(infor_buf, "list head delete success");  return infor_buf;
		case INFOR_LIST_TAIL_DELETE_SUCCESS:	strcpy(infor_buf, "list tail delete success");  return infor_buf;
		case INFOR_LIST_FIND_NODE:				strcpy(infor_buf, "list by id find node");      return infor_buf;
    	//melon
    	case INFOR_MELON_INIT_SUCCESS: 			strcpy(infor_buf, "Melon init success.");       return infor_buf;	
		//mysql
		case INFOR_MYSQL_INIT_SUCCESS: 			strcpy(infor_buf, "mysql init success.");       return infor_buf;	
		case INFOR_MYSQL_CONNECT_SUCCESS: 		strcpy(infor_buf, "mysql connect success.");    return infor_buf;
		case INFOR_MYSQL_INSERT_SUCCESS: 		strcpy(infor_buf, "mysql insert success.");     return infor_buf;

		default:
			break;
	}
	snprintf(infor_buf, sizeof(infor_buf), "infor code: %d", x);
	return infor_buf;
}


/** 
 * @brief 
 * @file 1-4-log.c
 * @name 
 * @param[in] void
 * @return void
 * @note 
 * @date 2022-01-25 11:48:59
 * @version V1.0.0
*/
extern void log_fwrite(const char *log_path, const char* mode, const char *file_name, \
    const char *function_name, int line, enum LOG_LEVEL level)
{
    log = log_init(log_path, mode);

	//time
	strcpy(log_buf, "["); 
	strcpy(cur_time, time_get_current());
	strcat(log_buf, cur_time); 
	strcat(log_buf, "] ["); 

	//log level
	strcpy(log_level_buf , log_get_level_buf(level) ); 
	while( strlen(log_level_buf) < 7){ 
		strcat(log_level_buf, " "); 
	} 
	strcat(log_buf, log_level_buf); 
	strcat(log_buf, "] ["); 

	//error path
	strcpy(error_path, str_get_file_relative_path(file_name, "c-cmake-main"));
	while( strlen(error_path) < 30){
		strcat(error_path, " "); 
	} 
	strcat(log_buf, error_path);
	strcat(log_buf, "] ["); 
	//function name
	//strcat(function_buf, __FUNCTION__);
	strcpy(function_buf, function_name);
	while( strlen(function_buf) < 15){ 
		strcat(function_buf, " "); 
	} 
	strcat(log_buf, function_buf);
	strcat(log_buf, "] [");

	//line  
	//itoa(__LINE__, line_buf, 10); 
	itoa(line, line_buf, 10); 
	while( strlen(line_buf) < 4){ 
		strcat(line_buf, " "); 
	} 
	strcat(log_buf, line_buf); 
	strcat(log_buf, "] ");
    //msg buf
    if(level == LOG_LEVEL_ERROR) strcat(log_buf, error_buf); 
    else if(level == LOG_LEVEL_INFOR) strcat(log_buf, infor_buf);
    
	strcat(log_buf, "\n"); 
	if( log_get_log_state() != NULL){
		fwrite(log_buf, 1, strlen(log_buf), log_get_log_state());
	}

	//printe("log_buf:%s\n", log_buf); 
	memset(log_buf, 0, sizeof(log_buf));
    memset(log_level_buf, 0, sizeof(log_level_buf)); 
    memset(cur_time, 0, sizeof(cur_time)); 
    memset(error_path, 0, sizeof(error_path)); 
    memset(function_buf, 0, sizeof(function_buf)); 
    memset(line_buf, 0, sizeof(line_buf)); 
    memset(error_buf, 0, sizeof(error_buf)); 
    memset(infor_buf, 0, sizeof(infor_buf)); 
	log_close(log);
}


/* [] END OF FILE */