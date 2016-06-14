#include<stdio.h>
double tn(double x){
if(x<0)
return -1*tn(-x);
else if(0<x<=0.00001){
return x;
}
else{
y=tn(x/2);
return (2*y)/(1-(y*y));
}
}
int main()
{
    double x;
    printf("enter arguments of tangent:\n");
    scanf("%lf",&x);
    double q=tn(x);
    printf("tangent of x is %lf",q);
}
