#ifndef  _USART_H
#define  _USART_H

//串口相关的头文件    
#include<stdio.h>      /*标准输入输出定义*/    
#include<stdlib.h>     /*标准函数库定义*/    
#include<unistd.h>     /*Unix 标准函数定义*/    
#include<sys/types.h>     
#include<sys/stat.h>       
#include<fcntl.h>      /*文件控制定义*/    
#include<termios.h>    /*PPSIX 终端控制定义*/    
#include<errno.h>      /*错误号定义*/    
#include<string.h>    

//宏定义    
#define FALSE  -1    
#define TRUE   0
int uart_Open(int fd, char*port);
void uart_Close(int fd) ; 
int uart_Set(int fd,int speed,int flow_ctrl,int databits,int stopbits,int parity);
int uart_Init(int fd, int speed,int flow_ctrl,int databits,int stopbits,int parity) ;
int uart_Recv(int fd, unsigned char *rcv_buf,int data_len);
int uart_Send(int fd, unsigned char *send_buf,int data_len);
int uart_Clear_rec_buf(int fd);
int uart_Clear_send_buf(int fd);
 
#endif
