#include <stdio.h>
int main()
{
int n;
int max;
printf("number of entries:\n");
scanf("%d",&n);
int i,a;
printf("enter first number:\n");
scanf("%d",&max);
for (i=0;i<n-1;i=i+1){
printf("enter next number:\n");
scanf("%d",&a);
if (a>=max){max=a;}
    }
    printf("maximum number is:%d",max);
}
