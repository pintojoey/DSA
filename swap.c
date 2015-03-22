/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to created to swap values reffering to objects using pointers
Assumptions:The data inserted in the node has to be an integer value
*/
#include<stdio.h>
void swap (int*, int*);
void swap(int *c,int *d)//Function to swap two elements using pointers
{
int temp;
temp=*c;
*c=*d;
*d=temp;
}

void main()
{
int a,b;
printf("Enter two numbers to swap");
scanf("%d %d",&a,&b);
swap(&a,&b);                               // Swap Function Call
printf("Swapped numbers are %d %d",a,b);
}
