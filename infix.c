/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to convert a given infix expression  having +-/*%() operators to postfix and evaluate it
Assumptions:The data inserted int the expression must not have white spaces and have only single digit integers or +-/*%() operators
			Max size of the expression is 100
*/

#include<stdio.h>
#include<ctype.h>
#define MAX 100

typedef struct stack
{
 int data[MAX];
 int top;
}stack;

int priority(char);//return priority of an operator
void init(stack *);
int isempty(stack *);
int full(stack *);
char pop(stack *);
void push(stack *,char);
char top(stack *);
char postfix[40];
float evaluate();
int i=0;
float value=0;
void main()
{
stack s;
char x;
int token;
init(&s);
printf("Enter infix expression:");
  while((token=getchar())!='\n')
  {
    if(isalnum(token))
       {postfix[i]=token;i++;}
    else
       if(token == '(')
           push(&s,'(');
       else
       {
         if(token == ')')
             while((x=pop(&s))!='(')
             {postfix[i]=x;i++;}
         else
         {
         while(priority(token)<=priority(top(&s)) && !isempty(&s))//compare priority
             {
             x=pop(&s);
             {postfix[i]=x;i++;}
             }
         push(&s,token);
         }
       }
  }
  while(isempty(&s)==0)//emptying stack
    {
    x=pop(&s);
    {postfix[i]=x;i++;}
postfix[i]='\0';
printf("postfix expression");
puts(postfix);
value=evaluate();
printf("Value of expression is:%f \n",value);
    }


exit(1);
}

int priority(char x) //defining priotities of various operators
{
   if(x == '(')
 return(0);
   if(x == '+' || x == '-')
 return(1);
   if(x == '*' || x == '/' || x == '%')
 return(2);
   return(3);
}
 
void init(stack *s) // creating a new stack
{
   s->top=-1;
}
 
int isempty(stack *s)//checking empty stack
{
    if(s->top==-1)
 return(1);
    else 
 return(0);
}
 
int full(stack *s)// checking for full stack
{
    if(s->top==MAX-1)
 return(1);
    else 
 return(0);
}
 
void push(stack *s,char x)// add an element to the stack
{
  s->top=s->top+1;
  s->data[s->top]=x;
}
 
char pop(stack *s)// pop an operator from stack
{
   int x;
   x=s->data[s->top];
   s->top=s->top-1;
   return(x);
}
 
char top(stack * s)// return the topmost operator in stack
{
   return(s->data[s->top]);
}
 
float evaluate()// evaluate a postfix expression
{int j=0;int token;
int val=0,ans=0;
while(postfix[j]!='\0')
{
token=(int)postfix[j]; 
if (isalnum(token)) if (ans==0) ans=token-'0'; else val=token-'0';
else 
switch(postfix[j])
{case '+':
ans=ans+val;
break;
case '-':
ans=ans-val;
break;
case '*':
ans=ans*val;
break;
case '/':
ans=ans/val;
break;
case '%':
ans=ans%val;
break;
default:
printf("Unsupported character entered");
exit(1);
break;
}
j++;
}
return ans;
}
