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
#include "1-5-time.h"
#include "1-7-str.h"
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
	ERROR_MYSQL_INSERT_FAIL
};


/** 1
 * @brief picture file synthesizer
 * @param int x
 * @return have const char *strinfor,no id
 * @date 2021/09/27
 * @version V1.0
*/
enum MYINFOR
{
    //no use
	INFOR_NONE=0,
	//no use
	INFOR_CMD_FIND,
	//file
	//file open success
	INFOR_FILE_OPEN_SUCCESS,
	//file close success
	INFOR_FILE_CLOSE_SUCCESS,
	//log
	INFOR_LOG_SET_LEVEL_SUCCESS,
	//list
	//list init success
	INFOR_LIST_INIT_SUCCESS,
	//list create node success
	INFOR_LIST_CREATE_NODE_SUCCESS,
	//list header insert node success
	INFOR_LIST_HEAD_INSERT_SUCCESS,
	//list tail insert node success
	INFOR_LIST_TAIL_INSERT_SUCCESS,
	//list header delete node success
	INFOR_LIST_HEAD_DELETE_SUCCESS,
	//list tail delete node success
	INFOR_LIST_TAIL_DELETE_SUCCESS,
	//list find
	INFOR_LIST_FIND_NODE,
	//melon init success
    INFOR_MELON_INIT_SUCCESS,
	//mysql INIT SUCCESS
	INFOR_MYSQL_INIT_SUCCESS,
	//mysql connect SUCCESS
	INFOR_MYSQL_CONNECT_SUCCESS,
	//mysql insert SUCCESS
	INFOR_MYSQL_INSERT_SUCCESS
};

/***************************************Variables***********************************/
//static int i


/***************************************Functions***********************************/
//void test(void);
extern FILE *log_init(const char *log_path, const char* mode);

extern int log_close(FILE *log);

extern FILE *log_get_log_state(void);

extern int log_set_level(enum LOG_LEVEL log_level);

extern enum LOG_LEVEL log_get_level(void);

extern char *log_get_level_buf(enum LOG_LEVEL level);

extern const char *mystrerror(int x) ;

extern const char *mystrinfor(int x);

extern void log_fwrite(const char *log_path, const char* mode, const char *file_name, \
    const char *function_name, int line, enum LOG_LEVEL level);


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
#define myerror(i) do{printe("[%s] ", time_get_current()); \
	printe("[%-7s] ", log_get_level_buf(LOG_LEVEL_ERROR) ); \
	printe("[%-30s] ", str_get_file_relative_path(__FILE__, "c-cmake-main")); \
	printe("[%-15s] [%-4d] %s\n",__FUNCTION__, __LINE__, mystrerror(i)); \
	if( log_get_level() <= LOG_LEVEL_ERROR){ \
		log_fwrite("../data/log/my.log", "a+", __FILE__, __FUNCTION__, __LINE__, LOG_LEVEL_ERROR); \
	} \
}while(0);
#else
#define myerror(i) do{printe("%s %s %s\n%s %d %s\n", \
	__DATE__, __TIME__, file_relative_path(__FILE__,".."), \
	__FUNCTION__, __LINE__, mystrerror(i));}while(0);
#endif


/** 1
 * @brief picture file synthesizer
 * @param int x
 * @return have const char *strinfor,no id
 * @author yang qi
 * @date 2021/09/27
 * @version V1.0
*/
#if 1
#define myinfor(i) do{printi("[%s] ", time_get_current()); \
	printi("[%-7s] ", log_get_level_buf(LOG_LEVEL_INFOR) ); \
	printi("[%-30s] ", str_get_file_relative_path(__FILE__, "c-cmake-main")); \
	printi("[%-15s] [%-4d] %s\n",__FUNCTION__, __LINE__, mystrinfor(i)); \
	if(log_get_level() <= LOG_LEVEL_INFOR ){ \
		log_fwrite("../data/log/my.log", "a+", __FILE__, __FUNCTION__, __LINE__, LOG_LEVEL_INFOR); \
	} \
}while(0);
#else
#define myinfor(i) do{printi("%s %s\n %s\n %s %d\n %s\n", \
	__DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, \
	mystrinfor(i));}while(0);
#endif


#endif
/* [] END OF FILE */