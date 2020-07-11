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

#define  REC_MASSAGE_LENGTH_NB  30
#define  SEND_MASSAGE_LENGTH_NB 8 

#define  REC_MASSAGE_LENGTH_DEVICE  30
#define  SEND_MASSAGE_LENGTH_DEVICE 8 

extern int fd_nb;
extern int fd_device;

unsigned char *  gu_rec_massage_nb_temp;
unsigned char *  gu_rec_massage_nb;
int gu_rec_massage_length_nb;
unsigned char *  gu_send_massage_nb;

unsigned char *  gu_rec_massage_device_temp;
unsigned char *  gu_rec_massage_device;
int gu_rec_massage_length_device;
unsigned char *  gu_send_massage_device;



int  rec_massage_from_nb_temp();
void  rec_massage_from_nb_serial();
int  send_massage_to_nb();

int  rec_massage_from_device_temp();
void  rec_massage_from_device_serial();
int  send_massage_to_device();

void  init_memory();
void  free_memory();

#endif
