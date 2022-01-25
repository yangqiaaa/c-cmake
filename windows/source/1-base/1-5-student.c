/*********************************************************************************
  *Copyright(C),1996-2021, Company
  *FileName:  1-5-student.c
  *Author:  wyp
  *Version:  V1.0
  *Date:  2022-01-21 13:35:17
  *Description:


  *History:
     1.Date:
       Author:
       Modification:
     2.
**********************************************************************************/


/***************************************Includes***********************************/
#include "1-1-print.h"
#include "1-2-myinfor.h"
#include "1-3-myerror.h"
#include "1-5-student.h"

#include <windows.h>

/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/



/***************************************Functions***********************************/



/**
 * @brief init linked list
 * @param none
 * @return list head
 * @date 2021/09/27
 * @version V1.0
*/
static student_plist init_list(void)
{
    student_plist head=calloc(1,sizeof(student_list));//在堆空间申请了一个头节点
	if(head == NULL)
	{
		myerror(ERROR_LIST_INIT_FAIL);
		return NULL;
	}
    else
    {
        myinfor(INFOR_LIST_INIT_SUCCESS);
    }
	
	head->next=NULL;
	return head;	
}

/**
 * @brief crate node
 * @param none
 * @return list head
 * @date 2021/09/27
 * @version V1.0
*/
static student_plist newnode(char *id,char *name,char *sex,char *age,
	char *chinese_score,char*math_score,char *english_score,char *history_score)
{
	student_plist new=calloc(1,sizeof(student_list));//在堆空间申请了一个新节点
	if(new==NULL)
	{
		myerror(ERROR_LIST_CREATE_NODE_FAIL);
		return NULL;
	}
    else
    {
        myinfor(INFOR_LIST_CREATE_NODE_SUCCESS);
    }
	
	strcpy(new->id,id);
	strcpy(new->name,name);
	strcpy(new->sex,sex);
	strcpy(new->age,age);
	strcpy(new->chinese_score,chinese_score);
	strcpy(new->math_score,math_score);
	strcpy(new->english_score,english_score);
	strcpy(new->history_score,history_score);
	return new;	
}

/**
 * @brief header insert node
 * @param none
 * @return list head
 * @date 2021/09/27
 * @version V1.0
*/
void insert_node_head(student_plist my_list, student_plist new)
{
	if(my_list==NULL||new==NULL)
	{
		myerror(ERROR_LIST_HEAD_INSERT_FAIL);
        return;
	}
	else
	{
		myinfor(INFOR_LIST_HEAD_INSERT_SUCCESS);
	}
	new->next = my_list->next;//新建节点的数据域指向头节点 == 创建尾节点 
    my_list->next = new;//将新建节点数据域传给头节点
	//my_list->next = new->next;
}

/**
 * @brief tail insert node
 * @param none
 * @return list head
 * @date 2021/09/27
 * @version V1.0
*/
void insert_node_tail(student_plist my_list, student_plist new)
{
	if(my_list==NULL||new==NULL)
	{
		myerror(ERROR_LIST_TAIL_INSERT_FAIL);
        return;
	}
	else
	{
		myinfor(INFOR_LIST_TAIL_INSERT_SUCCESS);
	}
    //plist p =my_list->next;
    while(my_list->next!=NULL)
    {
        my_list = my_list->next;
    }

	my_list->next = new;
	//new->next=NULL;
}

/**
 * @brief header delete node
 * @param none
 * @return list head
 * @date 2021/09/27
 * @version V1.0
*/
void delete_node_head(student_plist my_list)
{
	if(my_list==NULL||my_list->next==NULL)
	{
		myerror(ERROR_LIST_HEAD_DELETE_FAIL);
        return;
	}
	else
	{
		myinfor(INFOR_LIST_HEAD_DELETE_SUCCESS);
	}
	
	student_plist node = my_list->next;
	my_list->next=node->next;
	
	free(node);
}


/**
 * @brief tail delete node
 * @param none
 * @return list head
 * @date 2021/09/27
 * @version V1.0
*/
void delete_node_tail(student_plist my_list)
{
    if(my_list==NULL || my_list->next==NULL)
	{
		myerror(ERROR_LIST_TAIL_DELETE_FAIL);
        return;
	}
	else
	{
		myerror(INFOR_LIST_TAIL_DELETE_SUCCESS);
	}
    //my_list->next.next ==
    while(my_list->next->next != NULL)
    {
        my_list = my_list->next;
    }

	student_plist node=my_list->next;
	my_list->next=NULL;
    free(node);
	
}

/**
 * @brief find node by id
 * @param none
 * @return list head
 * @date 2021/09/27
 * @version V1.0
*/
student_plist  find_node_by_id(student_plist my_list,char *id)
{
	if(my_list==NULL)
	{
		return NULL;
	}

    int flag=0;
    int i=1;
	student_plist p = my_list->next;
	while(p!=NULL)
	{
		if(strcmp(id,p->id)==0)
        {
			printf("%s  ",p->id);
			printf("%s  ",p->name);
			printf("%s  ",p->sex);
			printf("%s  ",p->age);
			printf("%s  ",p->chinese_score);
			printf("%s  ",p->math_score);
			printf("%s  ",p->english_score);
			printf("%s  ",p->history_score);
			printf("\n");
            flag=1;
        }
		p=p->next;
        i++;
	}

	if(flag==1)
    {
        myinfor(INFOR_LIST_FIND_NODE);
    }
    else
    {
        myerror(ERROR_LIST_NO_FIND_NODE);
    }
	return p;
}

/**
 * @brief change node by id
 * @param none
 * @return list head
 * @date 2021/09/27
 * @version V1.0
*/
student_plist  change_node_by_id(student_plist my_list,char *id)
{
	if(my_list==NULL)
	{
		return NULL;
	}

    int flag=0;
    int i=1;
	student_plist p=my_list->next;
	while(p!=NULL)
	{
		if(strcmp(id,p->id)==0)
        {
			printf("%s  ",p->id);
			printf("%s  ",p->name);
			printf("%s  ",p->sex);
			printf("%s  ",p->age);
			printf("%s  ",p->chinese_score);
			printf("%s  ",p->math_score);
			printf("%s  ",p->english_score);
			printf("%s  ",p->history_score);
			printf("\n");

			char name[8];
			char sex[4];
			char age[4];
			char chinese_score[4];
			char math_score[4];
			char english_score[4];
			char history_score[4];
			printf("请输入姓名：");
			scanf("%s",name);
			strcpy(p->name,name);

			printf("%s  ",p->id);
			printf("%s  ",p->name);
			printf("%s  ",p->sex);
			printf("%s  ",p->age);
			printf("%s  ",p->chinese_score);
			printf("%s  ",p->math_score);
			printf("%s  ",p->english_score);
			printf("%s  ",p->history_score);
			printf("\n");
            flag=1;
        }
		p=p->next;
        i++;
	}

	if(flag==1)
    {
        printf("find\n");
    }
    else
    {
        printf("no find\n");
    }
	return p;
}

/**
 * @brief Traversal list
 * @param none
 * @return list head
 * @date 2021/09/27
 * @version V1.0
*/
void print_list(student_plist my_list)
{
	if(my_list==NULL)
	{
		printi("遍历链表失败\n");
        return;
	}
	else
	{
		printi("遍历链表\n");
	}
	printi("学号  ");
	printi("姓名  ");
	printi("性别  ");
	printi("年龄  ");
	printi("语文成绩  ");
	printi("数学成绩  ");
	printi("英语成绩  ");
	printi("历史成绩  ");
	printi("\n");
	student_plist p=my_list->next;
	while(p!=NULL)
	{
		printi("%s  ",p->id);
		printi("%s  ",p->name);
		printi("%s  ",p->sex);
		printi("%s  ",p->age);
		printi("%s  ",p->chinese_score);
		printi("%s  ",p->math_score);
		printi("%s  ",p->english_score);
		printi("%s  ",p->history_score);
		//printi("\n");
		p=p->next;
	}
	printi("\n");
}

//读取文件病将数据导入链表
void read_txt(student_plist my_list)
{
    int i;
    FILE* txt=fopen("..\\txt\\student.txt","r");
    //FILE* txt=fopen("C:\\Users\\24100\\Desktop\\1-c\\txt\\student.txt","r");
	if(txt==NULL)
	{
		printe("读取失败,文件不存在或者路径错误\n");
		return;
	}
	else
	{
		printi("读取文件成功\n");
        printi("开始解析数据");
        for(i = 0; i < 6; i++)
        {
            Sleep(300);
            printi(".");
        }
		printi("\n\n");
	}
	Sleep(1000);

	//解析数据 一直读取到文件尾
	char buffer[40]={0};
	while(!feof(txt))
	{
		//读取每行 自带换行
		fgets(buffer, sizeof(buffer), txt);
		printi("len=%d,buffer=%s",strlen(buffer),buffer);

		//有数据，字符串切割 新建节点并加入
		if(strlen(buffer)!=0)
		{
			char *data[8];
			int i = 0;
			char *p;
			p = NULL;
			/*分割同一字符串，第一次调用时传入字符串的首地址，第二个参数是分割符*/
			p = strtok(buffer, "-");
			while(p)
			{
				data[i] = p;
				++i;
				p = strtok(NULL, "-");
			}

			for (i = 0; i < 8; ++i)
			{
				printi("%s ", data[i]);
			}
			//printf("\n");
			char *id			= data[0];
			char *name		   	= data[1];
			char *sex		   	= data[2];
			char *age		   	= data[3];
			//char *score[4];
			char *chinese_score	= data[4];
			char *math_score   	= data[5];
			char *english_score	= data[6];
			char *history_score	= data[7];
			printi("%s-%s-%s-%s-%s-%s-%s-%s",id,name,sex,age,chinese_score,
				math_score,english_score,history_score);
			student_plist new=NULL;
			new=newnode(id,name,sex,age,chinese_score,
				math_score,english_score,history_score);
			insert_node_tail(my_list,new);
		}
		else
		{
			printi("空行\n");
		}
		printi("\n");
		memset(buffer,0,sizeof(buffer));
		Sleep(500);
	}
	printi("读取结束\n");
	printi("\n");
	Sleep(500);
}

//学生菜单
void show_student(void)
{
    printi("************************\n");
	printi("*****学生信息管理系统*****\n");
	printi("*************************\n");
	printi("*****系统功能菜单*********\n");
	printi("*****0.系统帮助及说明*****\n");
	printi("*****1.刷新学生信息*******\n");
	printi("*****2.查询学生信息*******\n");
	printi("*****3.修改学生信息*******\n");
	printi("*****4.增加学生信息*******\n");
	printi("*****5.按学号删除信息******\n");
	printi("*****6.显示当前信息*******\n");
	printi("*****7.保存当前学生信息****\n");
	printi("*****8.退出系统************\n");
	printi("**************************\n");
}

//帮助信息
void show_student_0_help(void)
{
    printi("0.欢迎使用系统帮助！\n");
	printi("1.初次进入系统后,会加载本地学生信息;\n");
	printi("2.按照菜单提示键入数字代号;\n");
	printi("3.增加学生信息后,切记保存;\n");
	printi("4.谢谢您的使用！\n");
	printi("请按任意键返回.......\n");
	getchar();//输入数字后输入enter 10
	getchar();
}

//定义一个链表节点指针
student_plist  my_list;

void choose(void)
{ 
    while(1)
    {
        char str_id[8];				
		char string_1[8]="0";
		char string_2[8]="00";
		char string_3[8]="000";
		char data[8]="0";
		system("cls");
        show_student();
        printf("请选择:");
        int num;
        scanf("%d",&num);
        switch(num)
        {
			case 0:show_student_0_help();break;
            case 1:break;
            case 2:
			{
				printi("请输入id：");
				int id;
				scanf("%d",&id);
				printf("%d\n",id);
				while(id>10000)
				{
					printf("请重新输入id：");
					scanf("%d",&id);
				}
				sprintf(str_id,"%d",id);
				//printf("%s,%d\n",str_id,strlen(str_id));
				if(strlen(str_id)==1)
				{
					strcat(string_3,str_id);
					strcpy(data,string_3);
				}
				else if(strlen(str_id)==2)
				{
					strcat(string_2,str_id);
					strcpy(data,string_2);
				}
				else if(strlen(str_id)==3)
				{
					strcat(string_1,str_id);
					strcpy(data,string_1);
				}
				else
				{
					strcpy(data,str_id);
				}
				//printf("%s\n",data);
				find_node_by_id(my_list,data);
				printi("请按任意键返回.......\n");
				getchar();//输入数字后输入enter 10
				getchar();
				break;
			}
            case 3:
			{
				printi("请输入要要修改的学生的学号:\n");
				int change_id;
				scanf("%d",&change_id);
				while(change_id>10000)
				{
					printi("请重新输入id：");
					scanf("%d",&change_id);
				}
				sprintf(str_id,"%d",change_id);
				//printf("%s,%d\n",str_id,strlen(str_id));
				if(strlen(str_id)==1)
				{
					strcat(string_3,str_id);
					strcpy(data,string_3);
				}
				else if(strlen(str_id)==2)
				{
					strcat(string_2,str_id);
					strcpy(data,string_2);
				}
				else if(strlen(str_id)==3)
				{
					strcat(string_1,str_id);
					strcpy(data,string_1);
				}
				else
				{
					strcpy(data,str_id);
				}
				//printf("%s\n",data);
				student_plist p;
				change_node_by_id(my_list,data);
				printi("请按任意键返回.......\n");
				getchar();//输入数字后输入enter 10
				getchar();
				break;
			}
            case 4:break;
            case 5:break;
            case 6:
				print_list(my_list);
				printi("请按任意键返回.......\n");
				getchar();//输入数字后输入enter 10
				getchar();
				break;
            case 7:break;
            case 8:return;break;
            default:printi("请在0-8之间选择\n");Sleep(500);break;
        }
    }
}


extern int run_1_5_student()
{
	//初始化链表
	my_list = init_list();
    read_txt(my_list);
	system("cls");
	print_list(my_list);
	Sleep(1000);
	system("cls");
	choose();

    printi("请按任意键退出.......\n");
    getchar();
    return 0;
}

/* [] END OF FILE */