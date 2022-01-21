/*********************************************************************************
  *Copyright(C),1996-2021, Company
  *FileName:  1-4-picture-file-sync.c
  *Author:  wyp
  *Version:  V1.0
  *Date:  2022-01-21 13:12:59
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
#include "1-4-pfy.h"

/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/



/***************************************Functions***********************************/
/** 1
 * @brief picture file synthesizer
 * @param none
 * @return 0 exist <0 inexistent
 * @author yang qi
 * @date 2021/09/27
 * @version V1.0
*/
int picture_file_synthesizer(void)
{
	FILE *f_pic,*f_file,*f_finish,*f_mv;
	char ch,pic_name[20],file_name[20],finish_name[20],mv_name[20];
	printw("file need add suffix\n:");
	printi("please enter picture name:");
	
	scanf("%s",pic_name);
	printw("file need add suffix\n:");
    printi("please enter file name:");

	scanf( "%s",file_name);
 	printi("sync file name:");
	scanf("%s",finish_name);
	
	if(!(f_pic = fopen(pic_name,"rb")))
	{
		printf("fail to open file\n",pic_name);
		return -1;
	}
	if(!(f_file = fopen(file_name,"rb")))
	{
		printe("fail to open file\n",file_name);
		return -1;
	}
	if(!(f_finish = fopen(finish_name,"wb")))
	{
		printe("fail to open file\n",finish_name);
		return -1;
	}
	
	while(!(feof(f_pic)))
	{
		ch = fgetc(f_pic);
		fputc(ch,f_finish);	
	}
	fclose(f_pic);
	while(!(feof(f_file)))
	{
		ch = fgetc(f_file);
		fputc(ch,f_finish);	
	}
	fclose(f_file);
	fclose(f_finish);
	
	return 0;
}

/* [] END OF FILE */