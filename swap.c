#include<stdio.h>
int swp(int a,int b){
return b,a;}
int main()
{
int a,b;
printf ("enter two numbers to be swapped:");
scanf("%d %d",&a,&b);
swp(a,b);
printf("%d %d",a,b);
}
