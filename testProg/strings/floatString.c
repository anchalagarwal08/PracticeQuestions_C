#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
  float num = 7.64;
  float decimal = num - (int)num;
  int a = (int)num;
  char buf[100]={0};
  char *res = (char*)malloc(10*sizeof(char));
  sprintf(res, "%d %c",a, '.'); 
  strcat(buf,res);
  // printf("%s \n", res);
  while(decimal>0)
  {
	decimal = decimal*10;
	char *res2 = (char*)malloc(10*sizeof(char));
	sprintf(res2, "%d",(int)decimal);
        strcat(buf, res2);
	decimal = decimal - (int)decimal;
	free(res2);
  }
 
 printf("%s \n", buf);

 return(0);	
}
