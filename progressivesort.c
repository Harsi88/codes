#include<stdio.h>
int main(){
int a[10]={5,4,6,10,8,7,3,1,2,9};
int i,j,mv;
for (j=0;j<=8;j++){
mv=a[j];
for(i=j+1;i<=9;i++){
if (mv>a[i]){
mv=a[i];
int temp=a[j];
a[j]=mv;
a[i]=temp;
}
}
}
for (i=0;i<=9;i++){
printf("%d ",a[i]);
}
}
