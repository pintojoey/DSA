/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to implement various opeartions on a doubly linked list
Assumptions:The data inserted in the node has to be an integer value
*/

#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *prev;
struct node *next;
};
int count=0;
struct node *getnode(int x);						//function to create a new node with data x
struct node *searchnode(int x);						//function to search a particular element from the data
struct node *searchprevnode(int x);					//function to search a node previous to the one containing the desired data
void insertAtend(int x);							//function to insert a node at the end of the linked list
void insertAtbegin (int x);							//function to insert a node at the beginning of the linked list
void insertAtprev(int x,int y);						//function to insert a node previous to a node containing the data
void insertAtnext(int x, int y);					//function to insert a node after a specified node
void deleteAtend();									//function to delete a node at the end
void deleteAtbegin();								//function to delete the first node
void traverse();									//function to display the contents of the linked list
void reverse();										//function to display the contents of the linked list in reverse
void createnode();									//function to create a new node
void modify(int x, int y);	                        //function to modify a particular node
void delete(int x);									//function to delete a particular node
struct node *start;
struct node *last;
void main()
{int option,x,y;
printf("\n\nChoose an option to perform \n1.Insert a node at the beginning\n2.Insert a node at the end\n3.Insert a node after specified note\n4.Insert a node before a specified note\n5.Delete node from beginning\n6.Delete a node from the end\n7.Delete a node having particular data\n8.Modify data of a particular node\n9.Traversing a linked list (display data\n10.Reverse traversing a linked list (display data)\n11.EXIT\n");
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
count++;
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
modify(x,y);
main();
break;
case 9:
traverse();
main();
break;
case 10:
reverse();
main();
break;
case 11:
exit(0);
main();
break;
default:
main();
break;
}
}

struct node *getnode(int x)// function to create a new node
{
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
if (p==NULL) {printf("Memory short!");exit(0);}
p->data=x;
if (count==0) {start=p;last=p;}
p->prev=NULL;
p->next=NULL;
return p;
}

void insertAtbegin(int x)// insert a node with given data at the beginning of list
{
struct node *p;
p=getnode(x);
if (count!=0){start->prev=p;p->next=start;}start=p;
}

void insertAtend(int x)// insert a node with given data at the end of list
{
struct node *p;
p=getnode(x);
last->next=p;
p->prev=last;
last=p;
}

void deleteAtend()// delete a node at the end of list
{
struct node *p;
if (count!=1){
p=last;
last=p->prev;
last->next=NULL;
free(p);
p=NULL;
}
else {printf("Insufficient elements!");count++;}
}

void deleteAtbegin()// delete the node at the beginning of list
{
struct node *p;
if (count!=1){
p=start;
start=start->next;
start->prev=NULL;
free(p);
}
else {printf("Insufficient elements");count++;}
}

void traverse()//display the contents of the list
{
struct node *p;
p=start;
printf("List:");
do
{
printf("%d",p->data);
p=p->next;
}while (p->next!=NULL);
printf("%d",p->data);
}

void reverse()//display the contents of the list in reverse
{
struct node *p;
p=last;
printf("List:");
do {
printf("%d",p->data);
p=p->prev;
}while (p->prev!=NULL);
printf("%d",p->data);
}

struct node *searchprevnode(int x) // search the node previous to a node having particular data
{
struct node *p,*q;
if (start->data==x) {q=getnode(0);q->next=start; return q;}
p=start;
while (p->next->data!=x)
{p=p->next;if (p->next==NULL) {printf("Element not found");main();}}
return p;
}

void insertAtnext(int x,int y) // insert a node with given data after a particular node
{
struct node *p,*q;
p=searchprevnode(x)->next;
q=getnode(y);
q->next=p->next;
q->prev=p;
p->next=q;
}

void insertAtprev(int x,int y) // insert a node with given data before a particular node
{
struct node *p,*q;
p=searchprevnode(x)->next;
q=getnode(y);
q->prev=p->prev;
q->next=p;
p->prev=q;
if (q->next==start) start=q;
}

void delete(int x) // delete a node with particular data
{
struct node *q;
q=searchprevnode(x)->next;
q->prev->next=q->next;
q->next->prev=q->prev;
free(q);
q=NULL;
}

void modify(int x,int y) // modify a particular node to have new data
{
struct node *p;
p=searchprevnode(x)->next;
p->data=y;
}
