/*********************************************************************************
  *Copyright(C),1996-2021, Company
  *FileName:  windows.c
  *Author:  wyp
  *Version:  V1.0
  *Date:  2022-01-21 10:59:04
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
//#include <stdio.h>
#include <stdlib.h>
#include "1-1-print.h"
#include "1-2-myinfor.h"
#include "1-3-myerror.h"
#include "1-4-pfy.h"
#include "1-5-student.h"
#include "1-6-num.h"
#include "1-7-ip.h"



/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/
static char cmd[20];


/***************************************Functions***********************************/


/** 
 * @brief run help to get usage # cmd [help]
 * @func: main.c
 * @param[in] void
 * @return void
 * @date 2021-12-02 17:11:35
 * @version V1.0.0
*/
void run_help(void)
{
    printi("cmd 'exit' or 'quit'\n");
    printi("cmd 'help' print help infor\n");
    printi("cmd 'sync' picture file synthesizer\n");
    printi("cmd 'student' student handle system\n");
    printi("cmd '1-4-carray' test data struct carrcy\n");
    printi("please press any key to end.......\n");
	getchar();//run main scanf输入cmd之后需要enter键,带有一个换行键
    getchar();
}

/** 
 * @brief run exit to exit # cmd [quit] or [exit]
 * @func: main.c
 * @param[in] void
 * @return void
 * @date 2021-12-02 17:11:52
 * @version V1.0.0
*/
void run_exit(void)
{
    myerror(ERROR_CMD_NO_FIND);
    printi("if you dn't how to usage,please input 'help' to see cmd\n");
    printi("please press any key to end.......\n");
	getchar();//run main scanf after input cmd and ned enter键,带有一个换行键
    getchar();
}


/** 
 * @brief run main to while loop
 * @func: main.c
 * @param[in] void
 * @return void
 * @date 2021-12-02 17:11:59
 * @version V1.0.0
*/
int run_main()
{
    printi("if you dn't how to usage,please input 'help' to see cmd\n");
    printi("cmd:");
    scanf("%s",cmd);
    while(strcmp(cmd,"exit"))
    {
        if(!strcmp(cmd,"help")) run_help();
        else if( !strcmp(cmd,"sync") ) picture_file_synthesizer();
        else if( !strcmp(cmd,"student") ) run_1_5_student();
        // else if( !strcmp(cmd,"ortpsend") ) ortp_send();
        // else if( !strcmp(cmd,"ortprecv") ) ortp_recv();
        // else if( !strcmp(cmd,"1-4-carray") ) run_1_4_carraytest();
        else if(!strcmp(cmd,"quit")) break;
        else run_exit();
        //Sleep(1000);
        system("cls");
        printi("cmd:");
        scanf("%s",cmd);
    }
    return 0;


}


/** 
 * @brief login printi linux cmd [ figlet yangqi ]
 * @func: main.c
 * @param[in] none
 * @return 
 * @date 2021-12-02 17:12:10
 * @version V1.0.0
*/
void login(void)
{
    system("cls");
    printi("\n");//figlet yangqi \\转义字符
    printi("                               _ \n");
    printi(" _   _  __ _ _ __   __ _  __ _(_)\n");
    printi("| | | |/ _` | '_ \\ / _` |/ _` | |\n");
    printi("| |_| | (_| | | | | (_| | (_| | |\n");
    printi(" \\__, |\\__,_|_| |_|\\__, |\\__, |_|\n");
    printi(" |___/             |___/    |_|  \n");
    printi("\n");
    printi("please press any key to end\n");
    getchar();
    system("cls");
}


/** 
 * @brief 
 * @func: main.c
 * @param[in] //
 * @param[out] //
 * @return 
 * @date 2021-12-02 17:12:15
 * @version V1.0.0
*/
int main(void)
{
    //In Windows system, color printing needs to call the screen clearing function, 
    //otherwise it is just random code
    system("cls");

	login();
    run_main();

    //Let the console not flash in the windows system
    printf("please press any key to end\n");
    getchar();
}

/* [] END OF FILE */
