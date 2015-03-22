/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to implememt push peep pop and change operations on a stack using linked list
Assumptions:The data inserted in the stack has to be an integer value
*/
#include<stdio.h>
#include<stdlib.h>
struct node //ADT to store the content of a singly linked list
{struct node *next;
int data;}*top;
int size=0;
//Functions
int isempty();                  //Function to check if the stack is empty
int isfull();					//Function to check if the stack is full
int pop();						//Function to pop an element from the stack
int peep(int);					//Function to view n'th element from the top
void push(int);					//Function to push an integer element onto the stack
void change(int,int);			//Function to modify the n'th element of the stack
void main()
{int option,x,y;
while(1)
{printf("Choose your operation :\n 1.Push \n2.Pop \n3.Peep \n4.change");
scanf("%d",&option);
switch(option)
{
case 1:
printf("Enter element to push:");
scanf("%d",&x);
push(x);
size++;
break;
case 2:
printf("popped element:");
if(isempty()==1) printf("Empty stack");
else printf("%d",pop());
size--;
break;
case 3:
printf("Enter element no. to peep");
scanf("%d",&x);
if (isempty()==1||x>size) {printf("Stack Underflow");exit(1);}
printf("%d element is: %d",x,peep(x));
break;
case 4:
printf("Enter element to change:");
scanf("%d",&x);
if (isempty()==1) {printf("Stack Underflow");break;}
printf("Enter new element");
scanf("%d",&y);
change(x,y);
break;
default:
exit(1);
break;
}
}
}
void push(int p)// add an element to top of stack
{struct node *new;
new=(struct node*)malloc(sizeof(struct node));
if (new==NULL) {printf("Stack overflow");exit(1);}
new->data=p;
new->next=NULL;
if (size!=0)new->next=top;
top=new;
}

int pop() // pop an element from the stack
{int e;
struct node* old;
old=top;
e=top->data;
top=top->next;
free(old);
old=NULL;
return e;
}
int isempty()//check if stack is empty
{
if (top==NULL) return 1;
else return 0;
}

int peep(int n) // peep at 'n'th element from top
{
int i=0;
int p;
struct node *peak;
peak=top;
while(i<n&&peak->next!=NULL) {peak=peak->next;i++;}
return peak->data;
}
void change(int n,int p)//change 'n' th element to 'p'
{struct node *change;
change=top;
while(n!=1){change=change->next;n--;}
change->data=p;
}

