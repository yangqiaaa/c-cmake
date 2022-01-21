/*********************************************************************************
  *Copyright(C),1996-2021, Company
  *FileName:  1-6-num.c
  *Author:  wyp
  *Version:  V1.0
  *Date:  2022-01-21 13:48:56
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
#include "1-6-num.h"

/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/



/***************************************Functions***********************************/
/** 
 * @brief 
 * @file 1-1-num.c
 * @name 
 * @param[in] int* num
 * @return 0 unique ### -1 not unique
 * @note 已经遍历元素不用在管
 * @date 2021-12-15 15:55:41
 * @version V1.0.0
*/
extern int num_judge_element_unique(int* num)
{
    int len = num_get_length(num);
    int i = 0;
    int j = 0;
    for ( i = 0; i < len; i++)
    {
        for ( j = i + 1; j < len; j++)
        {
            if ( num[i] == num[j] )
            {
                printe("array num element is not unique\n");
                return -1;
            }
        }
    }

    printi("array num element is unique\n");
    return 0;
}


/* [] END OF FILE */