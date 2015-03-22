/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to create a linked list and to carry out various inset and delete operations on it
Assumptions:The data inserted in the node has to be an integer value
*/

#include<stdio.h>
#include<stdlib.h>
struct node //ADT to store a linked list element
{
int data;
struct node *next;
};
int count=0;

//Functions
struct node *getnode(int x);                      //function to create a new node with data x
struct node *searchnode(int x);                   //function to search a particular element from the data
struct node *searchprevnode(int x);               //function to search a node previous to the one containing the desired data
void insertAtend(int x);                          //function to insert a node at the end of the linked list
void insertAtbegin (int x);                       //function to insert a node at the beginning of the linked list 
void insertAtprev(int x,int y);                   //function to insert a node previous to a node containing the data
void insertAtnext(int x,int y);                   //function to insert a node after a specified node
void deleteAtend();                               //function to delete a node at the end
void deleteAtbegin();                             //function to delete the first node
void traverse();                                  //function to display the contents of the linked list
void createnode();                                //function to create a new node
void modify(int x,int y);                         //function to modify a particular node
void delete(int x);                               //function to delete a particular node

struct node *start;                               
void main()
{int option,x,y;
printf("\n\nChoose an option to perform \n 1.Insert a node at the beginning\n2.Insert a node at the end\n3.Insert a node after specified note\n4.Insert a node before a specified note\n5.Delete node from beginning\n6.Delete a node from the end\n7.Delete a node having particular data\n8.Modify data of a particular node\n9.Traversing a linked list (display data)\n10.EXIT");
scanf("%d",&option);

switch(option)
{
case 1:
printf("Enter element to insert at the beginning:");
scanf("%d",&x);
insertAtbegin(x);
count++;
main();
break;
case 2:
printf("Enter element to insert at the end:");
scanf("%d",&x);
insertAtend(x);
count++;
main();
break;
case 3:
printf("Enter a node content after which to add a  node:");
scanf("%d",&x);
printf("Enter new node data:");
scanf("%d",&y);
insertAtnext(x,y);
main();
break;
case 4:
printf("Enter a node content to add data before:");
scanf("%d",&x);
printf("Enter new node data:");
scanf("%d",&y);
insertAtprev(x,y);
count++;
main();
break;
case 5:
deleteAtbegin();
main();
break;
case 6:
deleteAtend();
count--;
main();
break;
case 7:
printf("Enter node content to delete:");
scanf("%d",&x);
delete(x);
count--;
main();
break;
case 8:
printf("Enter node to modify:");
scanf("%d",&x);
printf("Enter new node data:");
scanf("%d",&y);

main();
break;
case 9:
traverse(start);
main();
break;
case 10:
exit(0);
main();
break;
default:
main();
break;
}
}


struct node *getnode(int x)
{
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
if (p==NULL) {printf("Memory short!");exit(0);}
p->data=x;
if (count==0) {start=p;printf("start made!");}
p->next=NULL;
return p;
}

void insertAtbegin(int x)
{
struct node *p;
p=getnode(x);
if (count!=0) {p->next=start;start=p;}
}

void insertAtend(int x)
{
struct node *p,*q;
q=start;
p=getnode(x);
while(q->next!=NULL)
{q=q->next;}
q->next=p;
}

void deleteAtend()
{
struct node *p,*q;
if (count!=1){
p=start;
while (p->next!=NULL)
{
q=p;
p=p->next;
}
free(p);
q->next=NULL;
p=NULL;
}
else {printf("Insufficient elements!");count++;}
}

void deleteAtbegin()
{
struct node *p;
if (count!=1){
p=start;
start=start->next;
free(p);
}
else {printf("Insufficient elements");count++;}
}

void traverse()
{
struct node *p;
p=start;
do{
printf("%d",p->data);
p=p->next;
}
while (p!=NULL);
}

struct node *searchnode(int x)
{
struct node *p;
p=start;
while (p->data!=x)
{p=p->next;if (p==NULL) {printf("Element not found");main();}}
return p;
}

struct node *searchprevnode(int x)
{
struct node *p,*q;
if (start->data==x) {q=getnode(0);q->next=start; return q;}
p=start;
while (p->next->data!=x)
{p=p->next;if (p->next==NULL) {printf("Element not found");main();}}
return p;
}

void insertAtnext(int x,int y)
{
struct node *p,*q;
p=searchprevnode(x)->next;
q=getnode(y);
q->next=p->next;
p->next=q;
}

void insertAtprev(int x,int y)
{
struct node *p,*q;
p=searchprevnode(x);
q=getnode(y);
q->next=p->next;
p->next=q;
if (q->next==start) start=q;
}

void delete(int x)
{
struct node *p,*q;
q=searchprevnode(x);
p=q->next;
q->next=p->next;
free(p);
}

void modify(int x,int y)
{
struct node *p;
p=searchnode(x);
p->data=y;
}
