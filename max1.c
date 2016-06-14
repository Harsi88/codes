#include <stdio.h>
int main()
{
int n;
int max;
printf("number of entries:\n");
scanf("%d",&n);
int i,a,smax;
printf("enter first number:\n");
scanf("%d",&max);
printf("enter second number:\n");
scanf("%d",&smax);
if (smax>max){int temp;
temp=max;
max=smax;
smax=temp;
}
for (i=0;i<n-2;i=i+1){
printf("enter next number:\n");
scanf("%d",&a);
if (a>=max){smax=max;
max=a;
}
else if (smax<=a<max){
smax=a;
}
    }
    printf("max. numbers are:%d %d",max,smax);
}
