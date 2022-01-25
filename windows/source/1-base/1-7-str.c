/*********************************************************************************
  *Copyright(C),1996-2021, Company
  *FileName:  1-7-str.c
  *Author:  wyp
  *Version:  V1.0
  *Date:  2022-01-25 10:53:43
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


/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/
static char new_path[100] = "0";


/***************************************Functions***********************************/

//传入想要切割的字符，加一个参数
/** input absolute path,output relative path
 * @brief 
 * @file 1-7-str.c
 * @name 
 * @param[in] char* dir // absolute or [__FILE__]
 * @param[in] char* str // cut str
 * @return if exist str, return char* new dir,other return __FILE__
 * @note 
 * @date 2022-01-25 10:55:07
 * @version V1.0.0
*/
extern char* str_get_file_relative_path(const char *dir, char *str)
{
	char path[100];
	char *delim = "/";
	char *tempin = NULL;
	char *temp = NULL;
	char ret[100];
	strncpy(path, dir ,sizeof(path) - 1);
	temp = path;
	while(NULL != ( temp = strtok_r( temp, delim, &tempin) ))
	{
		//printf("temp[%s] tempin[%s]\n",temp,tempin);
	    //printf("\n temp[%s] \n",temp);
        //if(!strcmp(temp,"cmake"))
		//if(!strcmp(temp,"1-c"))
        if(!strcmp(temp, str))
        {
            //printi("111111 %s\n", tempin);
			//return tempin;
			strncpy( new_path, tempin, sizeof(new_path)-1 );
			//printi("111111 %s\n", tempin);
			return new_path;
        }
		temp = NULL;
    }
    return __FILE__;
}


/* [] END OF FILE */