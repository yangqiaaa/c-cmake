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
extern int log_init(void)
{
    FILE *log;
    log = fopen("../data/log/my.log","a+");
    if(log == NULL)
    {
        myerror(ERROR_FILE_OPEN_FAIL);
    }
    else myinfor(INFOR_FILE_OPEN_SUCCESS);
}

/* [] END OF FILE */