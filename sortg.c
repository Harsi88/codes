#include <stdio.h>
int qs(int a[],int i,int t)
{
if(i==t)
{a[i];}
else
{
int j,k,temp;
k=t;
for(j=i;j<=t;j++)
{if(a[j]>a[i])
{while(k!=j)
{if(a[k]<a[i])
{temp=a[k];
a[k]=a[i];
a[i]=temp;
k--;
break;}
k--;}}
if(k==j)
{temp=a[i];
a[i]=a[k];
a[k]=temp;
break;}

qs(a,i,k-1);
qs(a,k,t);
}}
for(i=0;i<10;i++)
printf("\n %d",a[i]);
return 0;}
int main()
{
int i,t,k;
int a[10]={1,23,33,44,55,66,98,24,46,50};
i=0;
t=9;
qs(a,i,t);


return 0;}
