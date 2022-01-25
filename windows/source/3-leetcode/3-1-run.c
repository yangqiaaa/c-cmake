/*********************************************************************************
  *Copyright(C),1996-2021, Company
  *FileName:  3-1-run.c
  *Author:  wyp
  *Version:  V1.0
  *Date:  2022-01-21 14:40:07
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
#include <string.h>

#include "3-1-leetcode.h"
#include "1-1-print.h"
#include "1-4-log.h"
#include "1-6-num.h"

/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/



/***************************************Functions***********************************/
/** 
 * @brief 
 * @file 3-1-run.c
 * @name 
 * @param[in] void
 * @return void
 * @note 
 * @date 2021-12-13 10:26:25
 * @version V1.0.0
*/
static char cmd[20];

static int num[6] = {2,7,11,15};

extern int leetcode_run_help()
{
    printi("cmd 'exit' or 'quit'\n");
    printi("cmd 'help' printi infor\n");
    printi("cmd 'sync' \n");
    printi("cmd 'student' student handle system\n");
    printi("请按任意键返回.......\n");
	  getchar();//run main scanf输入cmd之后需要enter键,带有一个换行键
    getchar();
}

extern int run_3_1_leetcode_main()
{
    printi("if you dn't how to usage,please input 'help' to see cmd\n");
    printi("leetcode cmd:");
    scanf("%s",cmd);
    while(strcmp(cmd,"exit"))
    {
        if(!strcmp(cmd,"help")) leetcode_run_help();
        else if(!strcmp(cmd,"1-1")) leetcode_1_sum_of_two_number(num, num_get_length(num), 9);
        else if(!strcmp(cmd,"1-2")) leetcode_1_hash_twosum(num, num_get_length(num), 9);
        //else if(!strcmp(cmd,"student")) run_2_h1_student();
        // else if(!strcmp(cmd,"ntp")) run_ntp();
        // else if(!strcmp(cmd,"get-ip")) get_ip_by_domain_name("time1.aliyun.com");
        // else if (!strcmp(cmd,"leetcode")) run_leetcode();
        else if(!strcmp(cmd,"quit")) break;
        else 
        {
            myerror(ERROR_CMD_NO_FIND);
            printi("if you dn't how to usage,please input 'help' to see cmd\n");
            printi("请按任意键返回.......\n");
	          getchar();//run main scanf输入cmd之后需要enter键,带有一个换行键
            getchar();
        }
        //Sleep(1000);
        //system("cls");
        printi("leetcode cmd:");
        scanf("%s",cmd);
    }
    return 0;
}

/* [] END OF FILE */