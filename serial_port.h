#ifndef  _SERIAL_PORT_H
#define  _SERIAL_PORT_H

#include<stdio.h>      /*标准输入输出定义*/    
#include<stdlib.h>     /*标准函数库定义*/    
#include<unistd.h>     /*Unix 标准函数定义*/    
#include<sys/types.h>     
#include<sys/stat.h>       
#include<fcntl.h>      /*文件控制定义*/    
#include<termios.h>    /*PPSIX 终端控制定义*/    
#include<errno.h>      /*错误号定义*/    
#include<string.h>    
#include<pthread.h>    
#include "usart.h"

#define  REC_MASSAGE_LENGTH  30
#define  SEND_MASSAGE_LENGTH 8 
extern int fd;

unsigned char *  gu_rec_massage_temp;
unsigned char *  gu_rec_massage;
int gu_rec_massage_length;

unsigned char *  gu_send_massage;


int  rec_massage_from_serial_temp();
void  rec_massage_from_serial();

int  send_massage_to_serial();

void  init_memory();
void  free_memory();

#endif
