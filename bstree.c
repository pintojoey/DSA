/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to create a Binary search tree in the memory and carry out basic operations on the nodes
Assumptions:The data inserted in the node has to be an integer value
*/

#include<stdio.h>
#include<stdlib.h>

struct node//ADT node for binary search tree
{
int data;
struct node *left,*right;
};
struct node* root;//pointer to root of tree;

//Functions:    
void insert(struct node* parent,int);                   //Function to insert a new node into the tree
struct node *getnode(int );  			                //Function to create a node with integer type data in the memory
void preorder(struct node *parent);                     //Function to traverse and print the binary search tree in preorder sequence
void postorder(struct node *parent);                    //Function to traverse and print the binary search tree in postorder sequence
void inorder(struct node *parent);                      //Function to traverse and print the binary search tree in inorder sequence
void search(struct node *key,int x,int level,int child);//Function to traverse and locate a particular element in the tree
void destroy(struct node *parent);                      //Function to destroy the tree and freee the memory
void delete(struct node *key,int x);                    //Function to search and delete a node having particular data from memory
int count=0;                                            //counter to count the current number of nodes in the tree;

void main()
{
int option,x;
printf("\nChoose an option:\n1.Insert a node \n2.Preordered data\n3.Postordered data\n4.Inorder data\n5.Search\n6.Delete\n7.Destroy\n10.EXIT");
scanf("%d",&option);
switch(option)
{
case 1:
printf("\nEnter data of node to insert:");
scanf("%d",&x);
insert(root,x);
count++;
main();
break;
case 2:
preorder(root);
main();
break;
case 3:
postorder(root);
main();
break;
case 4:
inorder(root);
main();
break;
case 5:
printf("Enter element to search:");
scanf("%d",&x);
search(root,x,0,0);
main();
case 6:
printf("Enter element to delete:");
scanf("%d",&x);
delete(root,x);
count--;
main();
break;
case 7:
if (isEmpty(root)==1) printf("Tree is already empty!");
else destroy(root);
count=0;
root=NULL;
main();
break;
case 10:
exit(1);
break;
default:
main();
break;
}
return;
}

struct node *getnode(int x)//function to create a new node
{
struct node *p;
p=(struct node*)malloc(sizeof(struct node));
if (p==NULL) {printf("Memory short!");exit(0);}
p->data=x;
if (count==0) {root=p;}
p->left=NULL;
p->right=NULL;
return p;
}

void insert(struct node *parent,int x)
{
 if(count!=0) 
        {if (x==parent->data) {printf("Element already exists!"); main();}
if(parent->left==NULL||parent->right==NULL)
                {
		struct node *new;new=getnode(x);
		if(parent->left==NULL)
			{if(x<parent->data)parent->left=new;
			 else if (parent->right==NULL)parent->right=new;
			 else insert(parent->right,x);
			}
		else if (x<parent->data)insert(parent->left,x);
		else parent->right=new;
		}
 		
	else  
		
		{
 		if (x<parent->data) {insert(parent->left,x);}
 		else insert(parent->right,x);
		}
	}
if (count==0){struct node *new;new=getnode(x);}
}

void preorder(struct node *parent)
{if (parent!=NULL)
 {printf(" %d",parent->data);
  preorder(parent->left);
  preorder(parent->right);
  }
}
void postorder(struct node *parent)
{if (parent!=NULL)
 {
  postorder(parent->left);
  postorder(parent->right);
  printf(" %d",parent->data);
  }
}

void inorder(struct node *parent)
{if (parent!=NULL)
 {inorder(parent->left);
  printf(" %d",parent->data);
  inorder(parent->right);
  }
}
void search(struct node *key,int x,int level,int child)
{if (key->data==x) {printf("Element %d found at level %d",x,level);if (child==0) printf(" on the left"); else printf(" on the right");}
 else
  {if (key->left!=NULL) {search(key->left,x,level+1,0); }
   if (key->right!=NULL){search(key->right,x,level+1,1);}
  }
}

int isEmpty(struct node *parent)
{if (parent==NULL) return 1;
 else return 0;}

void destroy(struct node *parent)
{if (parent->left!=NULL) destroy(parent->left);
 if (parent->right!=NULL)destroy(parent->right);
parent->left=NULL;parent->right=NULL;free(parent);parent=NULL;
}

void delete(struct node *key,int x)
{struct node *new;
if (key->data==x){if(key->left==NULL&&key->right==NULL)
			{printf("Reached");free(key);key=NULL;}
		  else if(key->left==NULL)
			{
			printf("Reached3");key->data=key->right->data;key->left=key->right->left;
			key->right=key->right->right;free(key);key=NULL;if(key==root){free(root);root=NULL;}
			}
		  else if(key->right==NULL)
			{
			printf("Reached4");key->data=key->left->data;key->left=key->left->left;key->right=key->left->right;free(key);key=NULL;
			}
		  else  {
			printf("Reached1");new=key->right;while(new->left!=NULL)new=new->left;new->left=key->left;
			key->data=key->right->data;key->left=key->right->left;new=key->right;key->right=key->right->right;free(new);new=NULL;
			}
		  
		 }

else
  	{ 
	if (key->left!=NULL) 
		if(key->left->data==x&&key->left->left==NULL&&key->left->right==NULL)
			{printf("Reached2");new=key->left;key->left=NULL;free(new);new=NULL;}
		else{delete(key->left,x);} 
   	if (key->right!=NULL)
		if(key->right->data==x&&key->right->left==NULL&&key->right->right==NULL)
			{printf("Reached5");new=key->right;key->right=NULL;free(new);new=NULL;}
		else{delete(key->right,x);}
  	}
}


