/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to delete all instances of a particular word from an input string
Assumptions:The data inserted has to be a character value else numberic order will be taken into consideration
*/
#include<stdio.h>
void main()
{
int i=0,j=0,len=0,k=0,l=0,size=0;
char text[80];
char search[10];
char strng[40];
printf("Enter a sentence:");
gets(text);
printf("\n Enter word to delete:");
gets(search);
while(text[size]!='\0')size++;
while(search[len]!='\0')len++;
while(text[i]!='\0')
{l=0;
for(k=0;k<=len; k++) {if(text[i+k]==search[k]) l++;}
if (l==len){i=i+len;}
if (l==len && (text[i+len]==' '&&(i==0||text[i-1]==' ')))

{i=i+len;}
else {strng[j]=text[i];j++;i++;}
}

strng[j]='\0'; // output the string to the string
printf("output:");
puts(strng);

}
