#include<stdio.h>
int f(int m,int n){
if (m==0||n==0)
return 1;
else
return f(m-1,n)+f(m,n-1);
}
int main(){
int m,n;
printf("enter co-ordinates m&n:");
scanf("%d %d",&m,&n);
int a=f(m,n);
printf("number of ways are:%d\n",a);
}
