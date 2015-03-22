#include<stdio.h>
main()
{
static int i=5;
if(--i)
{main();printf("%d",i);
}
}
