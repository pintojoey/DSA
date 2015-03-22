/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to calculate percentage of a student on the basis of marks in four subjects
Assumptions:The data inserted in marks has to be an integer value less than or equal to 100
*/

#include<stdio.h>
void main()
{int i;
struct student //A single object structure to store the data of a single student
{
char name[10];
int id;
int sub[5];
float total;
float percentage;
}joey;
printf("Enter student name:");
scanf("%s",joey.name);
printf("Enter student id:");
scanf("%d",&joey.id);
joey.total=0;
for(i=1;i<5;i++)
{
do{printf("Enter sub%d marks",i);
scanf("%d",&joey.sub[i]);}
while(joey.sub[i]<0||joey.sub[i]>100);
joey.total=joey.total+joey.sub[i];
}
joey.percentage=joey.total/4;
printf("student data:\n");
printf("Name:%10s",joey.name);
printf("\n id=%d \n percentage=%f\n",joey.id,joey.percentage);
}




