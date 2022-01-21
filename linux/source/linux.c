/*********************************************************************************
  *Copyright(C),1996-2021, Company
  *FileName:  linux.c
  *Author:  wyp
  *Version:  V1.0
  *Date:  2022-01-21 10:58:28
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
#include "1-2-myinfor.h"
#include "1-3-myerror.h"



/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/



/***************************************Functions***********************************/
int main(void)
{
    printf("windows");
    printi("1111\n");
    printe("22222\n");
    printw("33333\n");
    printd("4444444\n");
    myinfor(MELON_INIT_SUCCESS);
    myerror(MELON_INIT_FAIL);
}

/* [] END OF FILE */
//#include <stdio.h>
