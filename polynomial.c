/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to add two polynomials using linked list
Assumptions:The data inserted in the coefficient part has to be an integer value
			Indices are assigned automatically in decending order and hence the user must input the coefficients in standard order
*/
#include<stdio.h>
#include<stdlib.h>
struct node //ADT to store a polynomial term in the memory
{
int coeff;
int index;
struct node *next;
};

struct node* first;
struct node* second;
struct node* third;

//Functions
struct node *getnode(int,int);                  //Function to create a new node in a polynomial have a specific coefficient and index
void display(struct node *start);               //Function to display the coefficients of a polynomial in standard format
void add(struct node *,struct node *);          //Function to add up two polynomials
int order1,order2,x,i;
struct node *p,*q;

void main()
{
printf("Enter order of first equation:");
scanf("%d", &order1);
printf("Enter coeff of first equation terms");
for(i=order1;i>=0;i--) {scanf("%d",&x);p=getnode(x,i);if(i==order1){first=p;q=first;}else{q->next=p;q=q->next;}}
printf("Enter order of second equation:");
scanf("%d", &order2);
printf("Enter coeff of second equation terms:");
for(i=order2;i>=0;i--){scanf("%d",&x);p=getnode(x,i);if(i==order2){second=p;q=second;}else{q->next=p;q=q->next;}}

add(first,second);
display(third);
}

struct node *getnode(int x,int i)// function to create a new node
{
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
if (p==NULL) {printf("Memory short!");exit(0);}
p->coeff=x;p->index=i;
return p;
}

void add(struct node *first, struct node *second) //function to add polynomial pointed by"first" with "second" and store into 
{int order3,i;
if (order1>order2) order3=order1; else order3=order2;
i=order3;
while(i>=0)
{
if(first->index==second->index)
{p=getnode(first->coeff+second->coeff,i);first=first->next;second=second->next;}
else if ((first->index)>(second->index))
{p=getnode(first->coeff,i);first=first->next;}
else if ((first->index<second->index))
{p=getnode(second->coeff,i);second=second->next;}
if(i==order3) {third=p;q=p;} else {q->next=p;q=q->next;}
i--;
}
}

void display(struct node *start)//display the contents of the polynomial
{
struct node *p;
p=start;
printf("Result:");
do{
printf("%d",p->coeff);
p=p->next;
}
while (p!=NULL);
}




