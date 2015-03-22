#include<stdio.h>
main()
{
int a[][2]={5,7,5,9,4,6,3,1,2,9,0,6};
int *p,i;
int (*q)[4];
p=a;
q=a;
for(i=0;i<=3;i++)
{printf("%u ,%d,%u ,%u \n",a+i,**(a+i),p,q);
p++;
q++;}
}

