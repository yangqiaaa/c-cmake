/*********************************************************************************
  *Copyright(C),1996-2021, Company
  *FileName:  1-8-ntp.c
  *Author:  wyp
  *Version:  V1.0
  *Date:  2022-01-21 14:05:21
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
#include <time.h>
#include <winsock2.h>
#include "1-8-ntp.h"
#include "1-1-print.h"
#include <winsock.h>

/***************************************Macros***********************************/
//#define
//#define
/* 2208988800    1970-1900 in seconds*/
#define JAN_1970 0x83AA7E80      
 
typedef union
{
    int  time;
    char time_array[4];
} Timestamp;
 
typedef struct 
{
    char message_hdr[16];//报文头部 
    char RefTimestamp[8];
    Timestamp T1;
    char T1_decimal[4]; //T1的小数部分 
    Timestamp T2;
    char T2_decimal[4]; //T2的小数部分 
    Timestamp T3;
    char T3_decimal[4]; //T3的小数部分 
} NTP_MESSAGE;

/***************************************Variables***********************************/



/***************************************Functions***********************************/
/** 
 * @brief get second from 1900.1.1 to 1970.1.1
 * @file ntp.c
 * @name 
 * @param[in] void
 * @return unsigned int second 
 * @note 
 * @date 2021-12-09 15:11:38
 * @version V1.0.0
*/
unsigned int get_second_from_1900_to_1970(void)
{
    int i = 0;
    unsigned int second = 365*(1970-1900);
    for(i=1900;i<1970;i++)
    {
        if( (i%400 == 0) || (i%4==0 && i%100 != 0) )
        {
            second++;
        }
    }
    second *= 24*60*60;
    printi("%lld\n", second);
    printi("%x\n", second);

}



/** 
 * @brief 
 * @file ntp.c
 * @name 
 * @param[in] void
 * @return void
 * @note 
 * @date 2021-12-09 15:14:20
 * @version V1.0.0
*/
extern int run_1_8_ntp(void)
{
    get_second_from_1900_to_1970();
    //get ip
    //create UDP socket
    WORD socketVersion = MAKEWORD(2,2);
    WSADATA wsaData; 
    if(WSAStartup(socketVersion, &wsaData) != 0)
    {
        printe("create socket failed\n");
        return -1;
    }
    else printi("create socketsuccess\n");

    SOCKET ntp_client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    
    SOCKADDR_IN sin;
    sin.sin_family = AF_INET;
    //NTP Port UDP 123
    sin.sin_port = htons(123);
    //阿里云ntp地址
    sin.sin_addr.S_un.S_addr = inet_addr("203.107.6.88");
    int len = sizeof(sin);
    //请求报文 48 16*3 0001 1011 #### 00   VN 3 011   MODE 5 011 客户端服务器模式
    char sendData[] = { //构造报文
        0x1B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xD0, 0xAF, 0x5F, 0xF5, 0x23, 0xD7, 0x08, 0x00
    };
    
    printi("Connect to NTP Server...\n");
    
    time_t T1=time(NULL);
    //发送报文
    sendto(ntp_client, sendData, sizeof(sendData), 0, (SOCKADDR *)&sin, len);
 
    char recvData[48]={0};
    //接受应答
    int ret = recvfrom(ntp_client, recvData, 48, 0, (SOCKADDR *)&sin, &len);
    if(ret > 0)
    {
        time_t T4=time(NULL);
        
        printi("Connect success!\n\n");
        printi("Now the local time is %s",ctime(&T4));
        
        NTP_MESSAGE *ntp_time=(NTP_MESSAGE *)recvData;
        
        /* 大小端变换 由于NTP以1900为始，需变换 */
        ntp_time->T2.time=ntohl(ntp_time->T2.time)-JAN_1970;//T2
        ntp_time->T3.time=ntohl(ntp_time->T3.time)-JAN_1970;//T3
        
        /* NTP报文的网络延时=（T4-T1）-（T3-T2） */
        time_t net_delay=(T4-T1)-(ntp_time->T3.time-ntp_time->T2.time);
        printi("Net delay is %ld second(s).\n",net_delay);
        
        /* 误差补偿秒数=（（T2-T1）+（T3-T4））/2 */
        time_t Deviation=(((time_t)ntp_time->T2.time-T1)+((time_t)ntp_time->T3.time-T4))/2;
        printi("\nThe deviation is %d second(s).\n",Deviation);
        
        if(Deviation != 0)
        {
            printf("Reset the local time...\n");
            
            time_t now=time(NULL)+Deviation;
            struct tm *ptr;
            ptr=localtime(&now);
            char buffer[20]={0};
            
            sprintf(buffer,"date %d-%d-%d",ptr->tm_year+1900,ptr->tm_mon+1,ptr->tm_mday);
            system(buffer);
            
            sprintf(buffer,"time %d:%d:%d",ptr->tm_hour,ptr->tm_min,ptr->tm_sec);
            system(buffer);
            now=time(NULL);
            printi("Now the local time is %s",ctime(&now));
        }
        else //没有误差，无需校时 
        {
            printi("Here is no need to set local time.\n");
        }
    }
 
    closesocket(ntp_client);
    WSACleanup();
    system("pause");
    return 0;
}

/* [] END OF FILE */