#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  FILE *fp,*fp1;
  char ptr[7]="",ptr1[7]="",eth0_state[10]="",wlan0_state[10]="";
  int i=0;
  fp=fopen("/sys/class/net/enp8s0/operstate","r");
  fp1=fopen("/sys/class/net/wlan0/operstate","r");
  fgets(ptr,7,fp);

  printf("............eth0_state=%s\n",ptr);
  if(fp1!=NULL)
  {
      fgets(ptr1,7,fp1);
      printf("............eth1_state=%s\n",ptr1);
  }


  for(i=0;i<strlen(ptr);i++)
    {
        if(ptr[i]!='\n')
           eth0_state[i]=ptr[i];
    }
     eth0_state[i]='\0';
    // printf("ptr length =%d\n",strlen(eth0_state));

   for(i=0;i<strlen(ptr1);i++)
    {
        if(ptr1[i]!='\n')
           wlan0_state[i]=ptr1[i];
     }
      wlan0_state[i]='\0';

             if((strcmp(eth0_state,"up"))==(strcmp(wlan0_state,"up"))&&(!((eth0_state[0]=='d')||(wlan0_state[0]=='d')))&&(!((eth0_state[0]=='\0')&&(wlan0_state[0]=='\0'))))

                  printf("both are up state ...............connected eth0......\n");
        
             else if(((eth0_state[0]=='u') && (wlan0_state[0]=='d')) || ((eth0_state[0]=='u') && (wlan0_state[0]=='\0')))
                 printf("only eth0 up state ........connected to eth0........\n");
                

             else if(((eth0_state[0]=='d') && (wlan0_state[0]=='u')) || ((eth0_state[0]=='\0') && (wlan0_state[0]=='u')))
                 printf("only eth1 up state..........connected to eth1 ............\n");
            
             else
                 printf("...........eth0 and eth1 not active state............\n");

}

