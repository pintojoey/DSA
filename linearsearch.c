/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to search for a specified element using linear search algorithm
Assumptions:The data inserted has to be an integer value
*/

#include<stdio.h>
void main()
{
int size,i,x,loc;
printf("Enter size of array:");
scanf("%d",&size);
int a[size];
printf("Enter elements:\n");
for(i=0;i<size;i++) scanf("%d",&a[i]);

printf("Enter element location to search:");
scanf("%d",&x);
for(i=0;i<size;i++) if(x==a[i]) {loc=i;break;}
printf("Element found at position:%d",loc+1);
}
