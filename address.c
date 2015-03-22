/*
Author     :Joey Pinto
Date       :20 March 2014
// created by JOEY PINTO-IIITK
Description:A program to calculate the memory address of an element in a two or three dimensional matrix
Assumptions:The data inserted in the node has to be an integer value
*/

#include<stdio.h>
#include<stdlib.h>
void getmatrix2(int,int);
void getmatrix3(int,int);
void getaddr2(void);
void getaddr3(void);

void main()
{ 
int order,size;
float base;
printf("Enter no. of dimensions of matrix(2/3):");
scanf("%d",&order);

printf("Enter size of data element");
scanf("%d",&size);
printf("Enter base address:");
scanf("%f",&base);
if(order==2)
getmatrix2(base,size);
if(order==3)
getmatrix3(base,size);
}

void getmatrix2(int base,int size)//two dimesnional matrix
{int x,y,l1,l2,u1,u2,alloc,i,j;
int address;
printf("Enter number of rows:");
scanf("%d",&x);
printf("Enter number of columns:");
scanf("%d",&y);
printf("Enter lowerbound of rows:");
scanf("%d",&l1);
printf("Enter upperbound of rows:");
scanf("%d",&u1);
printf("Enter lowerbound of columns:");
scanf("%d",&l2);
printf("Enter upperbound of columns:");
scanf("%d",&u2);
printf("Enter location of element to find address:");
scanf("%d %d",&i,&j);
printf("Choose type of allocation:1.Row-wise 2.Column-wise");
scanf("%d",&alloc);
switch(alloc)
{
case 1:
address=base+size *(((i-l1)*x)+(j-l2));
break;
case 2:
address=base+size *(((j-l2)*y)+(i-l1));
break;
}
printf("Address of element in memory is:%d",address);
}

void getmatrix3(int base,int size)//three dimensional matrix
{int x,y,l1,l2,u1,u2,alloc,i,j,k,ox,oy,ol1,ol2,ou1,ou2;
int address;
printf("Enter number of rows of inner matrix:");
scanf("%d",&x);
printf("Enter number of columns of inner matrix:");
scanf("%d",&y);
printf("Enter lowerbound of rows of inner matrix:");
scanf("%d",&l1);
printf("Enter upperbound of rows of inner matrix:");
scanf("%d",&u1);
printf("Enter lowerbound of columns of inner matrix:");
scanf("%d",&l2);
printf("Enter upperbound of columns of inner matrix:");
scanf("%d",&u2);

printf("Enter number of rows of outer matrix:");
scanf("%d",&ox);
printf("Enter number of columns of outer matrix:");
scanf("%d",&oy);
printf("Enter lowerbound of rows of outer matrix:");
scanf("%d",&ol1);
printf("Enter upperbound of rows of outer matrix:");
scanf("%d",&ou1);
printf("Enter lowerbound of columns of outer matrix:");
scanf("%d",&ol2);
printf("Enter upperbound of columns of outer matrix:");
scanf("%d",&ou2);

printf("Enter location of element to find address:");
scanf("%d %d %d",&i,&j,&k);
printf("Choose type of allocation:1.Row-wise 2.Column-wise");
scanf("%d",&alloc);
switch(alloc)
{
case 1:
address=base +(((i-ol1)*(u2-l2)*(u1-l1))+((j-l1)*(u1-l1))+(k-l2));
break;
case 2:
address=base +(((i-ol1)*(u1-l1)*(u2-l2))+((j-l2)*(u2-l2))+(k-l1));
break;
}
printf("Address of element in memory is:%d",address);
}


