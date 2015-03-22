/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to implement push peep pop and change operations on a stack stored in the memory using array
Assumptions:The data inserted in the node has to be an integer value
            Maximum size of stack is 5
*/
#include<stdio.h>
#define MAX_SIZE 5
//Functions
void push(int);              //Push an integer onto the stack
int pop();                   //Pop an element from the stack to the output
int peep(int);               //Display n'th element from the top
void change(int,int);        //Change n'th element to another value
int isempty();               //Check if stack is empty
int isfull();                //Check if stack is full
int stack[MAX_SIZE];         
int top=-1;

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
if(isfull()==1) printf("Stack full! Stack Overflow!");
else push(x);
break;
case 2:
printf("popped element:");
if(isempty()==1) printf("Empty stack");
else printf("%d",pop());
break;
case 3:
printf("Enter element no. to peep");
scanf("%d",&x);
if (x>top) printf("Incorrect element! Stack underflow!");
else printf("%d element is: %d",peep(x));
break;
case 4:
printf("Enter element to change:");
scanf("%d",&x);
if (x>top||isempty()==1) {printf("Stack Underflow");break;}
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
{top++;
stack[top]=p;
}
int pop()  // return the top element and reduce stack size
{int e;
e=stack[top];
top--;
return e;
}
int isempty()//check if stack is empty
{
if (top==-1) return 1;
else return 0;
}
int isfull()// check if stack is full
{
if (top==4) return 1;
else return 0;
}
int peep(int n) // peep at 'n'th element from top
{
int i;
int p;
for(i=0;i<n;i++) p=pop();
return p;
}
void change(int n,int p)//change 'n' th element to 'p'
{
peep(n);
push(p);
}

