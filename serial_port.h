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
#include "arraylist.h"

#define  REC_MASSAGE_NB_TEMP  1000
#define  REC_MASSAGE_NB 50 

extern int fd_nb;
extern int fd_device;

int rec_massage_over_sign_nb;
ArrayList *  rec_massage_nb_temp;
ArrayList *  rec_massage_nb;

unsigned char * nb_temp;
unsigned char * device_temp;


int   rec_massage_from_nb_temp();
void   rec_massage_from_nb_pre();
void rec_from_nb();
int  send_massage_to_nb(unsigned char *  send_massage,int data_len);

void  rec_massage_from_device();
int  send_massage_to_device();

void  init_memory();
void  free_memory();


#endif
