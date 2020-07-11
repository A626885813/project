#include "serial_port.h"

void  init_memory()
{
  gu_rec_massage_temp=  (unsigned char *) malloc(8);
  gu_rec_massage=  (unsigned char *) malloc(REC_MASSAGE_LENGTH);
  gu_send_massage=  (unsigned char *) malloc(SEND_MASSAGE_LENGTH);
  gu_rec_massage_length=0;
}

int  rec_massage_from_serial_temp()
{
  int len=UART0_Recv(fd,gu_rec_massage_temp,1);
  if(len>0)
  {
    if((gu_rec_massage_length+len)<REC_MASSAGE_LENGTH)
    {
    memcpy(gu_rec_massage+gu_rec_massage_length,gu_rec_massage_temp,len);
    gu_rec_massage_length+=len;
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

void  rec_massage_from_serial()
{
    gu_rec_massage[gu_rec_massage_length]='\0';
    printf(" receive data is  %s\n",gu_rec_massage);    
}

int  send_massage_to_serial()
{
  int len;
  len =UART0_Send(fd,gu_send_massage,SEND_MASSAGE_LENGTH);
  if(len>0)
  {
    for(int i=0;i<len;i++)
    {
    printf(" send data is  %x\n",gu_send_massage[i]);    
    }
    memset(gu_send_massage,0x00,SEND_MASSAGE_LENGTH);
    return 0;
  }
  else{
    printf(" send data failure  \n");    
    return 1;
  }
}

void  free_memory()
{
  free(gu_rec_massage);
  free(gu_rec_massage_temp);
  free(gu_send_massage);
}
