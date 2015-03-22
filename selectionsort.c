/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to sort the lsit of integer elements using a selection sort Algorithm
Assumptions:The data inserted has to be an integer value
            Array size is initialized dynamically
*/

#include<stdio.h> //program to sort a list of elements using Selection sort algorithm
void main()
{
int size,i,j,temp;
printf("Enter size of array:");
scanf("%d",&size);
int a[size];
printf("Enter elements to sort:\n");
for(i=0;i<size;i++) scanf("%d",&a[i]);

for(i=0;i<size;i++)             //Selection sort
for(j=i+1;j>=0;j--) 
{
if(a[j]>a[j+1]) 
{temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}



printf("Ascending order of elements is:");
for(i=0;i<size;i++) printf("%d ",a[i]);
}
