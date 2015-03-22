/*
Author     :Joey Pinto
Date       :20 March 2014
Description:A program to to sort a list of elements using the quicksort algorithm
Assumptions:The data inserted in the node has to be an integer value
*/
#include <stdio.h>
//Functions
void quicksort(int *,int,int);//Function to quicksort an array ranging from one element to another
int partition(int *,int ,int);//To partition an array getting the pivot element into it's correct position in the list
int size;
void main()
{
 int k;
 printf("Enter size of array");
 scanf("%d",&size);
 int a[size];
 for(k=0;k<size;k++)
 scanf("%d",&a[k]);
 quicksort(a,0,size-1);
printf("Sorted array:");
for(k=0;k<size;k++) printf("%d ",a[k]);
}

void quicksort(int *a,int i,int j)//quicksorting function
{
int p;
 if (j>i)
  {
  p=partition(a,i,j);
  quicksort(a,i,p-1);
  quicksort(a,p+1,j);
  }
}

int partition(int *a,int p,int r)//partition and return pivot element
{
int i,j,temp,P;
P=a[p];
i=p+1;
j=r;

while (i<=r) {
      while (a[i]<P && i<r) i++;
     while (a[j]>P) j--;
      if (j<=i)break;
      temp=a[i];a[i]=a[j];a[j]=temp;
            }
temp=a[p];
a[p]= a[j];
a[j]=temp;

return j;
}
