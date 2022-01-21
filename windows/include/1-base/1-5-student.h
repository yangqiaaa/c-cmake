/*********************************************************************************
    *Copyright(C), 2021, Company
    *FileName:  1-5-student.h
    *Author:  yangqi
    *Version:  V1.0.0
    *Date: 2022-01-21 13:37:42
    *Description:


    *History:
     1.Date:
       Author:
       Modification:
     2.
**********************************************************************************/

#ifndef __1_5_STUDENT_H__
#define __1_5_STUDENT_H__

/***************************************includes***********************************/
//#include"xxx.h"


/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/
//static int i
typedef struct student
{
	char id[8];
	char name[8];
	char sex[4];
	char age[4];
	char chinese_score[4];
	char math_score[4];
	char english_score[4];
	char history_score[4];
	struct student *next;
}student_list,*student_plist;

/***************************************Functions***********************************/
//void test(void);
static student_plist init_list(void);

static student_plist newnode(char *id,char *name,char *sex,char *age,
	char *chinese_score,char*math_score,char *english_score,char *history_score);

static void insert_node_head(student_plist my_list, student_plist new);

static void insert_node_tail(student_plist my_list, student_plist new);

static void delete_node_head(student_plist my_list);

static void delete_node_tail(student_plist my_list);

static student_plist find_node_by_id(student_plist my_list,char *id);

static student_plist  change_node_by_id(student_plist my_list,char *id);

static void print_list(student_plist my_list);

void read_txt(student_plist my_list);

void show_student(void);

void show_student_0_help(void);

static void choose(void);

 extern int run_1_5_student();
#endif
/* [] END OF FILE */