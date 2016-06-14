#include<stdio.h>
#include<string.h>
int main(){
    char*q;int n;
    char a[100];
printf("enter a string:");
scanf("%[^\n]s",&a);
q=&a[0];
for(n=0;*q!='\0';q++){
n++;}
printf("%d",n);
}
