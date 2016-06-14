#include<stdio.h>
int f(int r,int c){
if (c==1)
return 1;
else if (c==r)
return 1;
else
return f(r-1,c-1)+f(r-1,c);
}
int main(){
int r,c,a;
printf("enter row no. and coloumn no.:");
scanf("%d %d",&r,&c);
a=f(r,c);
printf("%d\n",a);
}
