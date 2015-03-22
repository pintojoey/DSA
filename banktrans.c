/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to create a linked list and to carry out various inset and delete operations on it
Assumptions:The data inserted in the node has to be an integer value
*/
#include<stdio.h>
#include</usr/include/string.h>
//functions
void entry(); //function to add an entry of a bank account
void lowbal();//function to print data of all accounts having balance less than Rs.100
void transaction();//function to carry out either deposit or withdraw
void enquiry();// function to print information about a particular account no.

int data=0;

struct bank //ADT for a bank account
{
float number;
char name[20];
float balance;
}account[200];

void main()
{
menu:
printf("Choose your operation \n 1.Data Entry \n 2.Low balance list \n 3. Transaction \n 4. Enquiry \n");
int option;
scanf("%d",&option);
switch (option)
{
case (1):
entry();
data++;
goto menu;
break;
case (2):
lowbal();
goto menu;
break;
case (3):
transaction();
goto menu;
break;
case(4):
enquiry();
goto menu;
break;
default:
goto menu;
break;
}
}
void entry()//Data entry for a new bank account
{

printf("\n Enter account number:");
scanf("%f",&account[data].number);
printf("\n Enter account holder name");
scanf("%s",account[data].name);
printf("\n Enter balance");
scanf("%f",&account[data].balance);
}
void lowbal()//to print information of all account holders with balance less than 100
{
printf("Customer with balance less than Rs.100 \n");
for(data=0;data<=200;data++)
{if (account[data].balance<100)
{printf("Name: %s account number: %f balance Rs.%f \n",account[data].name,account[data].number,account[data].balance);}
}
}
void transaction()// to carry out deposit or withdrawl of cash
{int data;
int code;
float acc,amt;
printf("Enter type of transaction:1.Deposit 2. Withdrawl");
scanf("%d",&code);
accnt:
printf("Enter account number");
scanf("%f",&acc);
data=0;
while(acc!=account[data].number) {data++;if (data>200) {printf("Incorrect account number");goto accnt;}};
printf("Enter amount:");
scanf("%f",&amt);
if (code==1) {account[data].balance+=amt;printf("Successful Transaction information \n account number:%f Amount:%f Code:1",account[data].number,amt);}
if ((code==2) &&(account[data].balance>amt)) {account[data].balance-=amt;printf("Successful Transaction information \n account number:%f Amount:%f Code:1",account[data].number,amt);}
if((code==2) && (account[data].balance<amt)) {printf("insufficient balance for withdrawl!");}
}
void enquiry()//to print account information of a specific account number 
{
int data=0;
float acc;
acnt:
printf("Enter account number");
scanf("%f",&acc);while(acc!=account[data].number) {data++;if (data>200) {printf("Incorrect account number");goto acnt;}}
printf("\n Account number:%f Account name:%s Current balance:%f",account[data].number,account[data].name,account[data].balance);
}
