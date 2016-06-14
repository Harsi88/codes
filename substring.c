#include<stdio.h>
#include<string.h>

main(){
char main[100],sub[100];
printf("Enter main string:");
scanf("%s",&main);
printf("Enter sub string:");
scanf("%s",&sub);
int a,i,j,m=strlen(main),s=strlen(sub),flag;
char main1[s];
for(i=0;i<=m-s;++i){
	flag=1;
	for(j=i;j<s+i;++j){
		main1[j-i]=main[j];
	}
	//main1[s]='\0';
	//if(strcmp(main1,sub)!=1)flag=1;break;
	for(a=0;a<s;++a){
		if(main1[a]!=sub[a]){flag=0;break;}
	}
	if(flag==1){break;}
}
if(flag==1){printf("yes\n");}
else{printf("no\n");}
}
