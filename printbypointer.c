/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to print a list of user input elements merely by accessing the starting address using pointers
Assumptions:The data inserted in the node has to be an integer value
			Array size is intitialized dynamically
*/
#include<stdio.h>
void main()
{
int size,i;
printf("Enter array size:");
scanf("%d",&size);
int array[size];
printf("Enter data elements");
for (i=0;i<size;i++)
scanf("%d",&array[i]);
int *begin;
begin=&array;
printf("The array is \n");
for (i=0;i<size;i++)
{printf("%d",*begin);
begin++;}
}

