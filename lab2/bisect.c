#include<stdio.h>
#include<math.h>
#include<conio.h>
double f(double x){
return x*x*x-3;
}
int main(){
double a,b;
printf("enter initial aproximation:");
scanf("%lf,%lf",&a,&b);
double A=f(a),B=f(b);
double tol=0.00000001;
double q;
while(fabs(a-b)>tol){
double c=(a+b)/2,C=f(c);
if (C==0){
q=c;
break;
}
else if (C*A>0){
a=c;
q=a;
}
else if (C*B>0){
b=c;
q=b;
}
}
printf("root is %lf\n",q);
}
