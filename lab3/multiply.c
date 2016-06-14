#include<stdio.h>
int f(int a,int b){
if (b==0||a==0)
return 0;
else 
if (b>a)
return f((a-1),b)+b;
else if(a>b)
return f((b-1),a)+a;
}
int main(){
int a,b;
printf("enter two numbers:\n");
scanf("%d %d",&a,&b);
int q=f(a,b);
printf("%d multiplies by %d is %d\n",a,b,q);
}
