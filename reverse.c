/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to reverse an input string
Assumptions:The input string can have a maximum size 20
*/

#include<stdio.h>
void main()
{
char *str,*str1,*str2;
int i,count=0;
str=(char*)malloc(20*sizeof(char));
str1=(char*)malloc(20*sizeof(char));
str2=(char*)malloc(20*sizeof(char));
str2=str1;
printf("Enter text:\n");
gets(str);
while (*str!='\0')
{str++;count++;}// getting length of string
for(i=0;i<count;i++)
{str--;*str1=*str;str1++;}
*str1='\0';
printf("Reversed string:");
puts(str2);
}
