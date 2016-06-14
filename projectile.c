#include<stdio.h>
#include<math.h>
int main() {
double g=9.8;
double h,v,z;
printf("enter h,v,z:");
scanf("%lf,%lf,%lf",&h,&v,&z);
double a=(z*22)/(7*180);
double V=sqrt(2*g*h-v*v*(sin(a)*sin(a)));
double t=(V+v)/(2*g);
double D=v*cos(a)*t;
double H=h+(v*v*(sin(a)*sin(a)))/(2*g);
printf("H D V are %lf %lf %lf",H,D,V);
}
