#include "serial_port.h"
#include "usart.h"


void  init_memory()
{
  rec_massage_nb_temp =arraylist_new(REC_MASSAGE_NB_TEMP);
  rec_massage_nb =arraylist_new(REC_MASSAGE_NB);
  rec_massage_over_sign_nb=0;


  nb_temp=(unsigned char * )malloc(100);
  device_temp=(unsigned char * )malloc(100);
}

void  free_memory()
{
  arraylist_free(rec_massage_nb_temp);
  arraylist_free(rec_massage_nb );
  free(nb_temp);
  free(device_temp);
}

void rec_from_nb()
{
     while(!rec_massage_over_sign_nb)

     {
       if(rec_massage_from_nb_temp())
       {
        printf("enter to pross\n");
        rec_massage_from_nb_pre();
       }
     }
      rec_massage_over_sign_nb=0;
}

void   rec_massage_from_nb_pre()
{
   static unsigned int i=0;
  //static unsigned int index=0;
  static unsigned char received=0;
        printf("temp length %d\n",rec_massage_nb_temp->length);
        printf("i is  %d\n",i);
    if(received)
    {
      goto received_sign;
    }
        while(i<(rec_massage_nb_temp->length-1)&&!rec_massage_over_sign_nb)
        {
         if( rec_massage_nb_temp->data[i]==0x05)
           {
            if(rec_massage_nb_temp->data[i+1]==0x0a)
              {
                received=1;
                i=2;
received_sign:
      printf("received_sign  \n");
                while(i<(rec_massage_nb_temp->length-1)&&!(rec_massage_nb_temp->data[i]==0x50&&rec_massage_nb_temp->data[i+1]==0xa0))
                {
      printf("select 1 \n");
                  arraylist_append(rec_massage_nb,rec_massage_nb_temp->data[i]);
                  i++;
                }
                if(i<(rec_massage_nb_temp->length-1)&&(rec_massage_nb_temp->data[i]==0x50&&rec_massage_nb_temp->data[i+1]==0xa0))
                  {
                    printf("over  \n");
                    rec_massage_over_sign_nb=1;
                    received=0;
                    i=0;
                    arraylist_clear(rec_massage_nb_temp);
                  }
              }
           }
         if(!rec_massage_over_sign_nb)
         i++;
        }
}

int   rec_massage_from_nb_temp()
{
  unsigned int len =uart_Recv(fd_nb,nb_temp,10);
  unsigned int i;
  if(len>0)
  {
    for( i=0;i<len;i++)
    {
      if(rec_massage_nb_temp->length<REC_MASSAGE_NB_TEMP-1)
      {
      arraylist_append(rec_massage_nb_temp,nb_temp[i]);
      printf("received temp  data is %x \n",rec_massage_nb_temp->data[i]);
      }
      else
      {
       arraylist_clear(rec_massage_nb_temp);
      //printf("temp is full  \n");
      }
    }
    return 1;
  }
  else
  {
    printf("cannot receive data");
    return 0;
  }
}

int  send_massage_to_nb(unsigned char *  send_massage,int data_len)
{ 
  int len;
  len =uart_Send(fd_nb,send_massage,data_len);
  if(len>0)
  {
    for(int i=0;i<len;i++)
    {
    printf(" send data is  %x\n",send_massage[i]);    
    }
    return 1;
  }
  else
  {
    printf(" send data failure  \n");    
    return 0;
  }
}

void  rec_massage_from_device()
{

}
int  send_massage_to_device()
{

}


