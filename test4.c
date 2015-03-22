#include<stdio.h>
main()
{
char *s[]={"ice","green","cone","please"};
char **ptr[]={s+3,s+2,s+1,s};
char ***p=ptr;
printf("%s",**(++p));
printf("%s",*--*++p+1);
int a[][2]={151,223,244};
printf("%u     %u    %u",&a[0][0],&a[0][1],&a[1][0]);
int *t=a;
t++;
printf("%d",*t);
}
