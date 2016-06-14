#include<stdio.h>
int main(){
int n,k;
printf("enter number in binary number system:");
scanf("%d",&n);
int sum=0;
k=0;
while (n>0){
int m=n;
    n=n/10;
    int s=m-10*n;
sum=sum+s*(pow(2,k));
k=k+1;
}
printf("%d",sum);
}
