/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to create a queue using linked list in the memory and carry out operations enqueue sequeue and display
Assumptions:The data inserted in the node has to be an integer value
*/
#include<stdio.h>
#include<stdlib.h>
int count=0;
//Functions
struct node *getnode(int);         //Create a node with an integer data in the linked list
void enqueue(int);                 //Function to enqueue an integer element in the queue
int dequeue();                     //Function to dequeue an integer from the queue
void display();                    //Function to display the contents of the queue

struct node                        //ADT to store a node in a linked queue
{
struct node* next;
int data;
}*front,*rear;
void main()
{
int option,x;
printf("\nChoose an option \n1.Enqueue\n2.Dequeue\n3.Display\n4.exit:");
scanf("%d",&option);
switch(option)
{
case 1:
printf("Enter number to enqueue:");
scanf("%d",&x);
enqueue(x);
break;
case 2:
printf("Dequeued element is:%d\n",dequeue());
break;
case 3:
display();
break;
case 4:
exit(1);
break;
default:
main();
break;
}
main();
}

struct node *getnode(int x)// function to create a new node
{
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
if (p==NULL) {printf("Memory short!");exit(0);}
p->data=x;
if (count==0) {front=p;rear=p;}
p->next=NULL;
return p;
}

void enqueue(int x) //function to enqueue an element x into the list
{struct node *p;
 p=getnode(x);
 rear->next=p;
 rear=p;;
 count++;
}

int dequeue() //function to dequeue an element from the list and return it
{int x;
 struct node *p;
 p=front;
 x=p->data;
 front=front->next;
 free(p);
 p=NULL;
count--;
return x;
}

void display()// Display the queue
{
if(count==0) {printf("Empty queue!");main();return;}
struct node *p;
p=front;
do
{printf("\n%d",p->data);p=p->next;}while(p!=NULL);
}


