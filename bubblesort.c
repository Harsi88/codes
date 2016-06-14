#include<stdio.h>
int main(){
int a[10]={4,10,5,6,8,9,7,1,2,3};
int i,flag=1;
while(flag!=0){
    flag=0;
for (i=0;i<=8;i++){
if (a[i]>a[i+1]){
int temp=a[i];
a[i]=a[i+1];
a[i+1]=temp;
flag=flag+1;
}
}
}
for (i=0;i<=9;i++){
printf("%d ",a[i]);
}
}
