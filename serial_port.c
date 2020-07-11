#include "serial_port.h"

void  init_memory()
{
  gu_rec_massage_nb_temp=  (unsigned char *) malloc(8);
  gu_rec_massage_nb=  (unsigned char *) malloc(REC_MASSAGE_LENGTH_NB);
  gu_send_massage_nb=  (unsigned char *) malloc(SEND_MASSAGE_LENGTH_NB);
  gu_rec_massage_length_nb=0;
}

int  rec_massage_from_nb_temp()
{
  int len=uart_Recv(fd_nb,gu_rec_massage_nb_temp,1);
  if(len>0)
  {
    if((gu_rec_massage_length_nb+len)<REC_MASSAGE_LENGTH_NB)
    {
    memcpy(gu_rec_massage_nb+gu_rec_massage_length_nb,gu_rec_massage_nb_temp,len);
    gu_rec_massage_length_nb+=len;
    }
    else
    {
    printf("the receive_buf is full\n");
    }
    return 0;
  }
  else
  {
    printf("cannot receive data\n");    
    return 1;
  }
  sleep(1);
}

void  rec_massage_from_nb()
{
    gu_rec_massage_nb[gu_rec_massage_length_nb]='\0';
    printf(" receive data is  %s\n",gu_rec_massage_nb);    
}

int  send_massage_to_nb()
{
  int len;
  len =uart_Send(fd_nb,gu_send_massage_nb,SEND_MASSAGE_LENGTH_NB);
  if(len>0)
  {
    for(int i=0;i<len;i++)
    {
    printf(" send data is  %x\n",gu_send_massage_nb[i]);    
    }
    memset(gu_send_massage_nb,0x00,SEND_MASSAGE_LENGTH_NB);
    return 0;
  }
  else{
    printf(" send data failure  \n");    
    return 1;
  }
}


int  rec_massage_from_device_temp()
{
  int len=uart_Recv(fd_device,gu_rec_massage_device_temp,1);
  if(len>0)
  {
    if((gu_rec_massage_length_device+len)<REC_MASSAGE_LENGTH_DEVICE)
    {
    memcpy(gu_rec_massage_device+gu_rec_massage_length_device,gu_rec_massage_device_temp,len);
    gu_rec_massage_length_device+=len;
    }
    else
    {
    printf("the receive_buf is full\n");
    }
    return 0;
  }
  else
  {
    printf("cannot receive data\n");    
    return 1;
  }
  sleep(1);
}

void  rec_massage_from_device()
{
    gu_rec_massage_device[gu_rec_massage_length_device]='\0';
    printf(" receive data is  %s\n",gu_rec_massage_device);    
}

int  send_massage_to_device()
{
  int len;
  len =uart_Send(fd_device,gu_send_massage_device,SEND_MASSAGE_LENGTH_DEVICE);
  if(len>0)
  {
    for(int i=0;i<len;i++)
    {
    printf(" send data is  %x\n",gu_send_massage_device[i]);    
    }
    memset(gu_send_massage_device,0x00,SEND_MASSAGE_LENGTH_DEVICE);
    return 0;
  }
  else{
    printf(" send data failure  \n");    
    return 1;
  }
}

void  free_memory()
{
  free(gu_rec_massage_device);
  free(gu_rec_massage_device_temp);
  free(gu_send_massage_device);
}
