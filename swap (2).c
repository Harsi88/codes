#include<stdio.h>
int swp(int *pta,int *ptb){
int temp=*ptb;
*ptb=*pta;*pta=temp;
return;
}
int main()
{
int a,b;
printf ("enter two numbers to be swapped:");
scanf("%d %d",&a,&b);
swp(&a,&b);
printf("%d %d\n",a,b);
}
