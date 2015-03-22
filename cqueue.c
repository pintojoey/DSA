/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to to add and remove elements from a circular queue
Assumptions:The data inserted in the node has to be an integer value
*/
#include<stdio.h>
#include<stdlib.h> 
struct Node // create a node having a data and address part
{
        int Data;
        struct Node* next;
}*rear, *front; 


void delQueue() //delete an element from the queue
{
if (rear->next==front->next)
{printf("\nThe Circular Queue Empty");}
    else  { rear = rear->next;}
    
          
       
}
void enQueue(int value) // add an element to the queue
{
      struct Node *temp;
      temp=(struct Node *)malloc(sizeof(struct Node));
      temp->Data=value;
      if (front == NULL)
      {
           front=temp;
           front->next=NULL;
           rear=front;
      }
      else
      {
          front->next=temp;
          front=temp;
          front->next=rear;
      }
}
void display() //print the contents of the queue to screen
{
       struct Node *var=rear;
      if(var!=NULL)
      {
           printf("\nElements are as:  ");
            while(var!=front)
           {
                 printf("\t%d",var->Data);
                 var=var->next;
           }
           if(var==front)
           {
                printf("\t%d",var->Data);
           }
     printf("\n");
     }
     else
     printf("\nQueue is Empty");
}
void main() 
{
     int i=0;
     front=NULL;
     printf(" \n1. Push to Queue");
     printf(" \n2. Pop from Queue");
     printf(" \n3. Display Data of Queue");
     printf(" \n4. Exit\n");
     while(1)
     {
          printf(" \nChoose Option: ");
          scanf("%d",&i);
          switch(i)
          {
          case 1:
          {
          int value;
          printf("\nEnter a value to Equeue:");
          scanf("%d",&value);
          enQueue(value);
          break;
          }
          case 2:
          {

 if (rear!=NULL)  delQueue();
	  display();
          break;
          }
          case 3:
          {
          display();
          break;
          }
          case 4:
          {
          exit(0);
     }
     default:
     {
         printf("\nwrong choice for operation");
     }
   }
 }
} 
