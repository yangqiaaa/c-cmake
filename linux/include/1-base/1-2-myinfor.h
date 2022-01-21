/*********************************************************************************
  *Copyright(C), 2021, Company
  *FileName:  1-2-myinfor.h
  *Author:  yangqi
  *Version:  V1.0.0
  *Date: 2022-01-21 10:57:41
  *Description:


  *History:
     1.Date:
       Author:
       Modification:
     2.
**********************************************************************************/

#ifndef __2_MYINFOR_H__
#define __2_MYINFOR_H__

/***************************************includes***********************************/
//#include"xxx.h"
#include "1-1-print.h"

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
	//melon init success
    MELON_INIT_SUCCESS,
	//mysql INIT SUCCESS
	MYSQL_INIT_SUCCESS,
	//mysql connect SUCCESS
	MYSQL_CONNECT_SUCCESS,
	//mysql insert SUCCESS
	MYSQL_INSERT_SUCCESS,
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
    //melon
    case MELON_INIT_SUCCESS: 	return "Melon init success.";
	//mysql
	case MYSQL_INIT_SUCCESS: 	return "mysql init success.";
	case MYSQL_CONNECT_SUCCESS: return "mysql connect success.";
	case MYSQL_INSERT_SUCCESS: 	return "mysql insert success.";

	default:
		break;
	}
	snprintf(tmp, sizeof(tmp), "error code: %d", x);
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