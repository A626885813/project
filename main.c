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
 
extern ArrayList *  rec_massage_nb;
extern int rec_massage_over_sign_nb;

 int fd_nb = -1;           //文件描述符，先定义一个与程序无关的值，防止fd为任意值导致程序出bug    
 int fd_device = -1;           //文件描述符，先定义一个与程序无关的值，防止fd为任意值导致程序出bug    


void init_all()
{
     init_memory();
}

 
int main(int argc, char **argv)    
{
    int err;               //返回调用函数的状态    
    if(argc != 2)    
    {    
        printf("Usage: %s /dev/ttySn 0      #(send data)\n",argv[0]);
        printf("Usage: %s /dev/ttySn 1      #1(receive data)\n",argv[0]);
        printf("open failure : %s\n", strerror(errno));
    
        return FALSE;    
    }    

     fd_nb = uart_Open(fd_nb,argv[1]); //打开串口，返回文件描述符   
     do  
    {    
        err = uart_Init(fd_nb,115200,0,8,1,'N');    
        printf("Set Port Exactly!\n"); 
        sleep(1);   
    }while(FALSE == err || FALSE == fd_nb);    
     /*

         printf("main_pid is  %d  \n",getpid());

      init_all();

      pid1=fork();

      if(pid1==0)
      {
         printf("pid1 is  %d  \n",getpid());
         while(1)
         {
          rec_from_nb();
           for(unsigned int h =0;h<rec_massage_nb->length;h++)
            {
             printf("final received data is %x  \n",rec_massage_nb->data[h]);
            }
          arraylist_clear(rec_massage_nb);
         }
          exit(0);
      }
      while(1){

      }
*/

     init_all();

     while(1)
     {
       rec_from_nb();
       
       for(unsigned int h =0;h<rec_massage_nb->length;h++)
       {
         printf("final received data is %x  \n",rec_massage_nb->data[h]);
       }
        arraylist_clear(rec_massage_nb);
     }


  uart_Close(fd_nb);     
}    

