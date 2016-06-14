#include<stdio.h>
int denom(int k){
if (k==5)
return 50;
if (k==4)
return 25;
if (k==3)
return 10;
if (k==2)
return 5;
if (k==1)
return 1;
}
int coin(int n,int m){
if ((n-denom(m))>=0){
if (n==0)
return 1;
else if (m==1 || n<denom(2))
return 1;
else
return coin(n-denom(m),m)+coin(n,m-1);
}
else
return coin(n,m-1);
}
int main(){
int n,m=5;
printf("enter n:");
scanf("%d",&n);
int q=coin(n,m);
printf("%d",q);
}
