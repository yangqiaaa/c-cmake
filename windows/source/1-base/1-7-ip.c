/*********************************************************************************
  *Copyright(C),1996-2021, Company
  *FileName:  1-7-ip.c
  *Author:  wyp
  *Version:  V1.0
  *Date:  2022-01-21 13:56:25
  *Description:


  *History:
     1.Date:
       Author:
       Modification:
     2.
**********************************************************************************/


/***************************************Includes***********************************/

#define _WINSOCK_DEPRECATED_NO_WARNINGS
 
#include<stdlib.h>
#include<WinSock2.h>
#include "1-1-print.h"

/***************************************Macros***********************************/
//#define


/***************************************Variables***********************************/



/***************************************Functions***********************************/
int get_ip_by_domain_name(char * domain_name)
{
	WSADATA wsaData;
	int i;
	struct hostent *host;

	printf("Usage : %s <addr>\n", domain_name);

	if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
		printf("WSAStartup() error!");
 
	host = gethostbyname(domain_name);
	if (!host)
		printf("gethost.....error!");
 
	printf("Official name: %s\n", host->h_name);
	for (i = 0; host->h_aliases[i]; i++)
		printf("Aliases %d: %s\n", i + 1, host->h_aliases[i]);
	printf("Address type : %s \n",(host->h_addrtype==AF_INET)?"AF_INET":"AF_INET6");
 
	for (i = 0; host->h_addr_list[i]; i++)
		printf("IP addr %d: %s \n",i+1,inet_ntoa(*(struct in_addr*)host->h_addr_list[i]));
 
	WSACleanup();

    //printi("请按任意键返回.......\n");
	//getchar();//run main scanf输入cmd之后需要enter键,带有一个换行键
    //getchar();
	return 0;
}

/* [] END OF FILE */