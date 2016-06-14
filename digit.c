#include<stdio.h>
#include<math.h>
int main(){
int m,n,k;
printf("enter a number:");
scanf("%d",&m);
while (m!=0){
    n=m;
    k=0;
while (n>10){
n=n/10;
k=k+1;
}
printf("%d th digit is %d\n",k,n);
m=m-(n*(pow(10,k)));
}
}
