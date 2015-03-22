/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to compute factorial of an integer from user input
Assumptions:The data inserted in the node has to be an integer value
*/
#include<stdio.h>

//
int  factorial(int n);
void main()
{
int n,c,y;
printf("Enter number to print factorial:");
scanf("%d",&n);
y=factorial(n);
printf("%d",y);

}
int factorial(int n)
{
int fact;
if (n==0) return 1;
else return n*factorial(n-1);
}


