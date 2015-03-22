/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to implement a circular queue using array
Assumptions:The data inserted in the array has to be an integer value
	        Maximum size of the queue is 5
*/

#include<stdio.h>
#include<stdlib.h>
#define MAX 5
void enqueue(int);
int dequeue();
void display();
int rear=-1,front=-1;
int a[MAX];
void main()
{
int option,x;
printf("\nChoose operation:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
scanf("%d",&option);
switch(option)
{
case 1:
printf("Enter element to enqueue");
scanf("%d",&x);
enqueue(x);
main();
break;
case 2:
printf("Element dequeued is %d",dequeue());
main();
break;
case 3:
display();
main();
break;
case 4:
exit(1);
break;
default:
main();
break;
}
}
void enqueue(int x)
{
if ((rear==front-1) || (front==0&&rear==MAX-1))
{printf("Stack full\n");main();}
else
{if(rear==-1) {front=0;rear=0;}
else {if(rear==MAX-1) rear=0;
      else rear++;
     }
a[rear]=x;}
}

int dequeue()
{int x;
if (rear==-1) {printf("Empty stack");main();}
else{x=a[front];
     if(front==rear) {front=-1;rear=-1;}
     else {if (front==MAX-1) front=0;
	   else front++;
          }
return x;
    }
}

void display()
{int i=front;
if (front==rear==-1) {printf("Empty Stack:");}
else
do
  {printf("%d",a[i]);
	if(i==MAX-1) i=0;
        else i++;
  }while(i!=rear);
printf("%d",a[rear]);
}

