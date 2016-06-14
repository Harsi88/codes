#include<stdio.h>
int main(){
int n;
int marks[11];
printf("enter no. of students:");
scanf("%d",&n);
int i;
for (i=0;i<11;i++){
marks[i]=0;}
for(i=0;i<n;i++){
int x;
printf("enter marks of student no. %d:",i+1);
scanf("%d",&x);
marks[x]=marks[x]+1;
}
for (i=0;i<=10;i++){
printf("students having marks %d are %d\n",i,marks[i]);
}
}
