#include<stdio.h>
int f(int a,int b){
if (a==0||b==0)
return 0;
else if (b==1)
return a;
else if(b%2==0)
return 2*f(a,b/2);
else if(b%2==1)
return (2*f(a,(b-1)/2)+a);
}
int main(){
int a,b;
printf("enter two numbers to be multiplied:\n");
scanf("%d %d",&a,&b);
int q=f(a,b);
printf("%d multiplies by %d is %d\n",a,b,q);
}

