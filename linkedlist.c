// created by JOEY PINTO-IIITK
// program to implement operations on a linked list of integers
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct node *next;
};


int count=0;
struct node *pee;
struct node *getnode(int x);
struct node *searchnode(int x);
struct node *searchprevnode(int x);
void insertAtend(int x);//
void insertAtbegin (int x);
void insertAtprev(int x,int y);
void insertAtnext(int x,int y);
void deleteAtend();
void deleteAtbegin();
void traverse();
void createnode();
void modify(int x,int y);
void delete(int x);
struct node *start;
void main()
{int option,x,y;
printf("\n\nChoose an option to perform \n1.Insert a node at the beginning\n2.Insert a node at the end\n3.Insert a node after specified note\n4.Insert a node before a specified note\n5.Delete node from beginning\n6.Delete a node from the end\n7.Delete a node having particular data\n8.Modify data of a particular node\n9.Traversing a linked list (display data)\n10.EXIT\n");
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
modify(x,y);
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
case 11:
pee=start->next->next;printf("\n1.Start=%d,pee=%d",start->next->data,pee->data);
start->next=pee->next->next;printf("\n2.Start=%d,pee=%d",start->next->data,pee->data);
pee->next->next->next=pee;printf("\n3.Start=%d,pee=%d,p-l-l-l=%d",start->next->data,pee->data,pee->next->next->data);
printf("%d",start->next->next->next->data);printf("\n4.Start=%d,pee=%d",start->next->data,pee->data);
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
if (count==0) {start=p;}
p->next=NULL;
return p;
}

void insertAtbegin(int x)// insert a node with given data at the beginning of list
{
struct node *p;
p=getnode(x);
if (count!=0) {p->next=start;start=p;}
}

void insertAtend(int x)// insert a node with given data at the end of list
{
struct node *p,*q;
q=start;
p=getnode(x);
while(q->next!=NULL)
{q=q->next;}
q->next=p;
}

void deleteAtend()// delete a node at the end of list
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

void deleteAtbegin()// delete the node at the beginning of list
{
struct node *p;
if (count!=1){
p=start;
start=start->next;
free(p);
}
else {printf("Insufficient elements");count++;}
}

void traverse()//display the contents of the list
{
struct node *p;
p=start;
printf("List:");
do{
printf("%d",p->data);
p=p->next;
}
while (p!=NULL);
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
p->next=q;
}

void insertAtprev(int x,int y) // insert a node with given data before a particular node
{
struct node *p,*q;
p=searchprevnode(x);
q=getnode(y);
q->next=p->next;
p->next=q;
if (q->next==start) start=q;
}

void delete(int x) // delete a node with particular data
{
struct node *p,*q;
q=searchprevnode(x);
p=q->next;
q->next=p->next;
free(p);
}

void modify(int x,int y) // modify a particular node to have new data
{
struct node *p;
p=searchprevnode(x)->next;
p->data=y;
}
