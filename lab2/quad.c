#include <stdio.h>
#include <math.h>
int main()
{
float a,b,c;
printf("enter coefficients of equation:\n");
scanf("%f %f %f",&a,&b,&c);
float d;
d=b*b-4*a*c;
float x,y;
if (d==0){
x=-1*b/(2*a);
printf("equal roots are %f\n",x);
}
else if (d>0){
float D;
D=sqrt (d);
x=(-1*b+D)/(2*a);
y=(-1*b-D)/(2*a);
printf("real roots are %f & %f\n",x,y);
}
else if (d<0){
float k,l,D;
k=-1*b/(2*a);
D=sqrt (-d);
l=D/(2*a);
printf("imaginary roots are %f+(%f)i & %f+(%f)i\n",k,l,k,-l);
}
}



