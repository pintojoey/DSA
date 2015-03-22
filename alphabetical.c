/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A pprogram to sort a list of words entered as a single string into alphabetical order
Assumptions:The data inserted has to be a single string
*/

#include<stdio.h>
#include<string.h>
void main()
{
int i=0,j=0,k=0,l=0,n,wmax=0,tem;
char text[80];
char sort[80];
char temp[20];
struct word // a structure to contain a single word and it's length
{
char text[10];
int length;
}word[20];

printf("Enter a line of text");
gets(text);
while(text[j]!='\0'){if(text[j]==' ') wmax++;j++;};
wmax=j;
for(i=0;i<j;i++)
{
if(text[i]==' '){word[k].text[l]='\0';k++;l=0;continue;}
word[k].text[l]=text[i];
word[k].length=l;
l++;

}
for(n=0;n<wmax;n++)
for(i=0;i<wmax;i++)
for(j=0;j<word[i].length;j++)
{
if(word[i].text[j]>word[i+1].text[j])
{
strcpy(temp,word[i].text);
strcpy(word[i].text,word[i+1].text);
strcpy(word[i+1].text,temp);
}
if(word[i].text[j]==word[i+1].text[j])continue;
if(word[i].text[j]<word[i+1].text[j]);break;
}



for(j=0;j<wmax;j++)
puts(word[j].text); 
}

