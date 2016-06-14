#include<stdio.h>
#include<math.h>
int main(){
double x,x1,n;
printf("enter number:");
scanf("%lf",&n);
printf("enter initial approximation:");
scanf("%lf",&x);
if (x*x==n){
    printf("square root is %lf",x);
}
else {
double tol=1e-15;
x1=0.5*(x+n/x);
while (fabs(x-x1)>tol){
x=x1;
x1=0.5*(x+n/x);
}
printf("squareroot is %lf",x);
}
}
