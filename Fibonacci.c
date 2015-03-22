/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to print a list of fibonacci numbers using recursion
Assumptions:The number of fibonacci numberts to print must be greater than 0
*/
#include<stdio.h>
int  fibonacci(int n);//function to print n'th fibonacci number
void main()
{
int n,i=0,c;
printf("Enter number of fibonacci no.s to print:");
scanf("%d",&n);
for(c=0;c<=n;c++)
{printf("%d \n",fibonacci(i)); i++;}

}
int fibonacci(int n)
{
if (n==0) return 0;
else if (n==1) return 1;
else return(fibonacci(n-1)+fibonacci(n-2));
}


