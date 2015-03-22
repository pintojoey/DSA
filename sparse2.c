/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to create one or two matrices in the memory and also outpu tthem to a file
Assumptions:The data inserted in the matrix has to be an integer value
			Maximum size of the matrix can be 10x10x10

*/
// program to input two matrices and outputting them to file
//created by Joey Pinto-IIITK
#include<stdio.h>
void main()
{
FILE *fp;
int option,c,d,e,f,i,j,x,y,temp,reg=1,cmp,k=0,l;
int a[10][10];
int b[10][10];
int m[10][10];
struct matrix  //ADT for a sparse matrix triplet representation 
{
int x;
int y;
int value;
}t[10],s[10],u[10];


printf("Choose operation to perform 1.Transpose 2.Add 3.Multiply:");
scanf("%d",&option);
printf("Enter dimensions of matrix 1:");
scanf("%d%d",&c,&d);
printf("Enter elements row-wise");
fp=fopen("matrix1.txt","w+");
for(i=0;i<c;i++)for(j=0;j<d;j++)
{fscanf(stdin,"%d",&a[i][j]);
fprintf(fp,"%d",a[i][j]);fseek(fp,1,1);}
fclose(fp);


fp=fopen("matrix1.txt","r");
for(i=0;i<c;i++)
for(j=0;j<d;j++)
{fscanf(fp,"%d",&temp);fseek(fp,1,1);
if (temp!=0)
{
t[reg].value=temp;
t[reg].x=i;
t[reg].y=j;
reg++;
}
}
t[0].value=reg-1;
t[0].x=c;
t[0].y=d;
fclose(fp);
//matrix 2
if(option==3||option==2)//second matrix input 
{

printf("Enter dimensions of matrix 2:");
scanf("%d%d",&e,&f);
printf("Enter elements row-wise");
fp=fopen("matrix2.txt","w+");
for(i=0;i<e;i++)for(j=0;j<f;j++)
{fscanf(stdin,"%d",&b[i][j]);
fprintf(fp,"%d",b[i][j]);fseek(fp,1,1);}
fclose(fp);


fp=fopen("matrix2.txt","r");
reg=1;
for(i=0;i<c;i++)
for(j=0;j<d;j++)
{fscanf(fp,"%d",&temp);fseek(fp,1,1);
if (temp!=0)
{
s[reg].value=temp;
s[reg].x=i;
s[reg].y=j;
reg++;
}
}
s[0].value=reg-1;
s[0].x=c;
s[0].y=d;
fclose(fp);
}
printf("Original matrix");
for(i=0;i<=t[0].value;i++) {printf("\n x=%d y=%d value=%d",t[i].x,t[i].y,t[i].value);}
switch(option)
{
case 1: // transposing first matrix

j=1,k=0,l;
l=t[i].value;
s[i].y=t[i].x;s[i].x=t[i].y;s[i].value=t[i].value;
while(l!=0)
{for(i=0;i<=reg;i++) 
{if (t[i].y==k) {s[j].x=t[i].y;s[j].y=t[i].x;s[j].value=t[i].value;j++;}}k++;l--;}
s[0].x=t[0].y;s[0].y=t[0].x;s[0].value=t[0].value;
printf("Transposed matrix:");
for(i=0;i<reg;i++) {printf("\n x=%d y=%d value=%d",s[i].x,s[i].y,s[i].value);}
break;
case 2: //adding two matrices
k=1;l=0;
u[0].x=t[0].x;u[0].y=t[0].y;u[0].value=t[0].value;
for(i=1;i<=t[0].value;i++)
{u[k].x=t[i].x;u[k].y=t[i].y;u[k].value=t[i].value;k++;}

for(j=1;j<=s[0].value;j++)
{
l=0;
for(i=1;i<=t[0].value;i++)
{
if(s[j].x==u[i].x && s[j].y==u[i].y){;u[i].value=(s[j].value+u[i].value);u[i].x=s[j].x;u[i].y=s[j].y;l=1;break;}
}
if (l=0) {u[k].x=s[j].x;u[k].y=s[j].y;u[k].value=s[j].value;u[0].value++;k++;}
}
printf("Summed Matrix:");
for(i=0;i<=u[0].value;i++) {printf("\n x=%d y=%d value=%d",u[i].x,u[i].y,u[i].value);}
break;
case 3:// multiplying two matrices
k=1;l=0;
for(i=0;i<e;i++)
for(j=0;j<f;j++)
{m[i][j]=0;
for(k=0;k<f;k++)
m[i][j]+=a[i][k]*b[k][j];}
printf("Product Matrix:\n");
for(i=0;i<c;i++)
for(j=0;j<f;j++)
if(m[i][j]!=0)printf("\n x=%d y=%d value=%d",i,j,m[i][j]);
break;

}

}
