#include<stdio.h>
#include<math.h>
double f(double x){
return x*x*x+x;
}
double f_x(double x){
return 3*x*x+1;
}
int main(){
printf("enter initial approximation:\n");
double x,x1;
scanf("%lf",&x);
double w=f(x);
double r=f_x(x);
double q=w/r;
double tol=1e-7;
x1=x-q;
while (fabs(x-x1)>tol){
printf("working");
x=x1;
x1=x-q;
}
printf("root is:%lf",x);
}
