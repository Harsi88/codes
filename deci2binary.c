#include<stdio.h>
int main(){
int n,k;
printf("enter number in decimal number system:");
scanf("%d",&n);
int a[100];
k=0;
while (n!=0){
a[k]=n%2;
if (n%2==0)
n=n/2;
else n=(n-1)/2;
k=k+1;
}
int i;
for(i=k,i>=0;i--;){
printf("%d",a[i]);
}
}
