/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to sort a list of integers using bubble sort algorithm
Assumptions:The data inserted has to be an integer value
*/
#include<stdio.h>
void main()
{
int size,i,j,temp;
printf("Enter size of array:");
scanf("%d",&size);
int a[size];
printf("Enter elements to sort:\n");
for(i=0;i<size;i++) scanf("%d",&a[i]);
for(j=0;j<size-1;j++)
for(i=0;i<size;i++)
if(a[i]>a[i+1]) {temp=a[i];a[i]=a[i+1];a[i+1]=temp;}

printf("Ascending order of elements is:");
for(i=0;i<size;i++) printf("%d ",a[i]);
}
