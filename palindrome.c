#include<stdio.h> 
#include<string.h>

main(){
printf("input string:");
char str[100],revstr[100];
scanf("%s",&str);
int i,n=strlen(str),flag=0;
for(i=0;i<n;++i){
	revstr[n-1-i]=str[i];
}
for(i=0;i<n;++i){
	if(revstr[i]!=str[i]){flag=1;break;}
}
//if(strcmp(str,revstr)==0){flag=1;}
if(flag==1){printf("no\n");}
else{printf("yes\n");}
}
