#include "usart.h"
#include "serial_port.h"
#include<stdio.h>      /*标准输入输出定义*/    
#include<stdlib.h>     /*标准函数库定义*/    
#include<unistd.h>     /*Unix 标准函数定义*/    
#include<sys/types.h>     
#include<sys/wait.h>       
#include<sys/stat.h>       
#include<fcntl.h>      /*文件控制定义*/    
#include<termios.h>    /*PPSIX 终端控制定义*/    
#include<errno.h>      /*错误号定义*/    
#include<string.h>
 
	  int fd = -1;           //文件描述符，先定义一个与程序无关的值，防止fd为任意值导致程序出bug    
 
int main(int argc, char **argv)    
{
    int err;               //返回调用函数的状态    
    int len;                            
    int i=1;    
 //   char rcv_buf[256];             
  //  char send_buf[256];
    pid_t  pid;


    if(argc != 2)    
    {    
        printf("Usage: %s /dev/ttySn 0      #(send data)\n",argv[0]);
        printf("Usage: %s /dev/ttySn 1      #1(receive data)\n",argv[0]);
        printf("open failure : %s\n", strerror(errno));
    
        return FALSE;    
    }    
     fd = UART0_Open(fd,argv[1]); //打开串口，返回文件描述符   
    //  fd=open("/dev/ttyUSB0", O_RDWR);
   // printf("fd=%d \n",fd);
     do  
    {    
        err = UART0_Init(fd,115200,0,8,1,'N');    
        printf("Set Port Exactly!\n"); 
        sleep(1);   
    }while(FALSE == err || FALSE == fd);    
/*
     send_buf[0]=0x01;
     send_buf[1]=0x02;
     send_buf[2]=0x03;
     send_buf[3]=0x04;
     send_buf[4]=0x05;
     send_buf[5]=0x06;
     send_buf[6]=0x0d;
     send_buf[7]=0x0a;
     while(i--)
     {
     send_massage_to_serial();
     }
*/

     /*
     init_memory();
     while(1)
     {
    if(!rec_massage_from_serial_temp())
    {
       rec_massage_from_serial();
    }
     }

*/

     /*
     pid=fork();
   if(pid==0)
    {
        fgets(send_buf,256,stdin);   //输入内容，最大不超过40字节，fgets能吸收回车符，这样pc收到的数据就能自动换行     
        for(i = 0;i < 2;i++)    
        {    
            len = UART0_Send(fd,send_buf,40);    
            if(len > 0)    
            {
                printf(" %d time send %d data successful\n",i,len);    
            }
            else    
                printf("send data failed!\n");    
            sleep(1);    
        }    
        UART0_Close(fd);                 
        exit(0);
    }     
    //else                            //开发板收到pc发送的数据的模式                 
     
    {                                          
        while (1) //循环读取数据    
        {   
            len = UART0_Recv(fd, rcv_buf,sizeof(rcv_buf));    
          //  len = UART0_Recv(fd, rcv_buf,5);    
            if(len > 0)    
            {    
                rcv_buf[len] = '\0';    
                printf(" rec_data is  %s\n",rcv_buf);    
            }    
            else    
            {    
                printf("cannot receive data\n");    
            }    
            sleep(1);    
        }                
        UART0_Close(fd);     
    }    
    */
   exit(0);
}    
