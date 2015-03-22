/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to sort a lost of entered elements into descending order using insertion sort algorithm
Assumptions:The data inserted has to be an integer value
			The output will be achieved in descending order
*/
#include<stdio.h>
void main()
{
int size,i,j,min,temp;
printf("Enter size of array:");
scanf("%d",&size);
int a[size];
printf("Enter elements to sort:\n");
for(i=0;i<size;i++) scanf("%d",&a[i]);

for(i=0;i<size;i++)
{
min=i;
for(j=i+1;j<size;j++) 
{
if(a[min]>a[j]) {min=j;}
temp=a[min];
a[min]=a[j];
a[j]=temp;
}	

}

printf("Descending order of elements is:");
for(i=0;i<size;i++) printf("%d ",a[i]);
}
