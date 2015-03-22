/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to print the steps to solve a tower of Hanoi having specified number of pegs to screen and to file
Assumptions:There are three towers
*/

#include<stdio.h>
void toh(int,char,char,char,FILE *);
void main()
{ int n;
FILE *fp;
fp=fopen("Towers.txt","w+");

printf("Enter number of rings");
scanf("%d",&n);
printf("The moves to solve tower are:");
fprintf(fp,"The moves to solve tower are:");
toh(n,'A','C','B',fp);
fclose(fp);

}
void toh(int n,char frompeg,char topeg, char auxpeg,FILE *fp) //The classic tower of hanoii recursive function
{
if (n==1)
{
printf("\n Move ring 1 from peg %c to peg %c",frompeg,topeg);
fprintf(fp,"\n Move ring 1 from peg %c to peg %c",frompeg,topeg);
return;
}
toh(n-1,frompeg,auxpeg,topeg,fp);
printf("\n Move ring %d from peg %c to peg %c",n,frompeg,topeg);
fprintf(fp,"\n Move ring %d from peg %c to peg %c",n,frompeg,topeg);
toh(n-1,auxpeg,topeg,frompeg,fp);
}
