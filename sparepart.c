/*S
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to create a ist of 200 data items called parts having a year,material and quantity parameter
Assumptions:The data inserted in the node has to be an integer value
            program to input data of a sparepart with name as 'AAx' to 'FFx' x being an integer from 0-9 
            sparepart name is taken as a single string input and enquiry prints information from a starting to an end point in list of spare parts 
			*/
#include<stdio.h>
#include<stdlib.h>
void main()
{
int op,i,j,c,w,l,m,x,y,z;
char a,b,u,v;
char in[3];
char out[3];

struct part // create a spare part item XXx eg. AA0 to FF9
{
int year;
char material[20];
int quantity;
}item[6][6][10];
menu:
printf("\nchoose your operation 1.Data Entry 2.Enquiry:");
scanf("%d",&op);
switch(op)
{
case 1: //Takes input of a single spare part
printf("\nEnter part serial number (Character,Character,no.):");
scanf("%s",in);
a=in[0];
b=in[1];
c=in[2];
c=c-'0'; //converting ASCII Value to integer index
x=a;
x=x-'A';//converting ASCII Value to integer index
y=b;
y=y-'A';//converting ASCII Value to integer index
printf("Enter Year of maunfacture:");
scanf("%d",&item[x][y][c].year);
printf("Enter name of material used:");
scanf("%s",item[x][y][c].material);
printf("Enter Quantity manufactured:");
scanf("%d",&item[x][y][c].quantity);
break;
case 2: //Prints the data of all elements within a particular range
printf("Enter part serial number from(Character,Character,no.) to (Character,Character,no.) :");
scanf("%s",in);
a=in[0];
b=in[1];
c=in[2];
c=c-'0';
x=a;
x=x-'A';//converting ASCII Value to integer index
y=b;
y=y-'A';//converting ASCII Value to integer index
printf("to");
scanf("%s",out);
u=out[0];
v=out[1];
w=out[2];
w=w-'0';
l=u;
l=l-'A';//converting ASCII Value to integer index
m=v;
m=m-'A';//converting ASCII Value to integer index
for(i=x;i<=l;i++)
for(j=y;j<=m;j++)
for(c=c;c<=w;c++)
printf("\nSerial no:%c%c%d Year:%d Material:%s Quantity:%d"
,x+'A',y+'A',c,item[i][j][c].year,item[i][j][c].material,item[i][j][c].quantity);
break;
default:
exit(1);
break;
}
goto menu;
}

