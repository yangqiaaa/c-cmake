/*********************************************************************************
  *Copyright(C), 2021, Company
  *FileName:  2-myinfor.h
  *Author:  yangqi
  *Version:  V1.0.0
  *Date: 2022-01-21 10:05:04
  *Description:


  *History:
     1.Date:
       Author:
       Modification:
     2.
**********************************************************************************/

#ifndef __1_2_MYINFOR_H__
#define __1_2_MYINFOR_H__


/***************************************includes***********************************/
//#include"xxx.h"
#include "1-1-print.h"
#include "1-4-log.h"

/***************************************Macros***********************************/
//#define
/** 1
 * @brief picture file synthesizer
 * @param int x
 * @return have const char *strerror,no id
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
	INFOR_MYSQL_INSERT_SUCCESS,
};

/***************************************Variables***********************************/
//static int i


/***************************************Functions***********************************/
//void test(void);
/**
 * @brief picture file synthesizer
 * @param[in] int x
 * @return have const char *strerror,no id
 * @date 2021/09/27
 * @version V1.0
*/
static const char *mystrinfor(int x) 
{
    static char tmp[100]={"0"};
	switch (x)
	{
		//file
		case INFOR_FILE_OPEN_SUCCESS:			return "file open success";
		case INFOR_FILE_CLOSE_SUCCESS:			return "file close success";
		//log
		case INFOR_LOG_SET_LEVEL_SUCCESS:		return "log set level success";
		//list
		case INFOR_LIST_INIT_SUCCESS:			return "list init success";			
		case INFOR_LIST_CREATE_NODE_SUCCESS:	return "list create node success";
		case INFOR_LIST_HEAD_INSERT_SUCCESS: 	return "list head insert success";
		case INFOR_LIST_TAIL_INSERT_SUCCESS:	return "list tail insert success";
		case INFOR_LIST_HEAD_DELETE_SUCCESS:	return "list head delete success";
		case INFOR_LIST_TAIL_DELETE_SUCCESS:	return "list tail delete success";
		case INFOR_LIST_FIND_NODE:				return "list by id find node";
    	//melon
    	case INFOR_MELON_INIT_SUCCESS: 			return "Melon init success.";	
		//mysql
		case INFOR_MYSQL_INIT_SUCCESS: 			return "mysql init success.";	
		case INFOR_MYSQL_CONNECT_SUCCESS: 		return "mysql connect success.";
		case INFOR_MYSQL_INSERT_SUCCESS: 		return "mysql insert success.";

	default:
		break;
	}
	snprintf(tmp, sizeof(tmp), "infor code: %d", x);
	return tmp;
}


/** 1
 * @brief picture file synthesizer
 * @param int x
 * @return have const char *strerror,no id
 * @author yang qi
 * @date 2021/09/27
 * @version V1.0
*/
#if 1
#define myinfor(i) do{printi("%s\n",mystrinfor(i));}while(0);
#else
#define myinfor(i) do{printi("%s %s\n %s\n %s %d\n %s\n", \
	__DATE__, __TIME__, __FILE__, __FUNCTION__, __LINE__, \
	mystrinfor(i));}while(0);
#endif


#endif
/* [] END OF FILE */