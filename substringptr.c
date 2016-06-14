#include<stdio.h>
#include<string.h>

int substring(char *s,char *t){
int flag=0,m=0,n=0,i,j,counter=0;
char *s1=s,*t1=t;
while(*s1 != '\0'){m+=1;++s1;}
while(*t1 != '\0'){n+=1;++t1;}
if(n>m){return -1;}
else{
for(i=0;i<=m-n;++i){
	counter+=1;
	flag = 1;
	s1 = s;
	s1 = s1+i;
	t1 = t;
	for(j=1;j<=n;++j){
		if(*s1 != *t1){flag=0;break;}
		++s1;++t1;
	}
	if(flag==1){break;}
}
if(flag==1){return counter;}
if(flag==0){return -1;}
}
}
main(){
char main[100],sub[100];
printf("Enter main string:");
scanf("%s",main);
printf("Enter sub string:");
scanf("%s",sub);
char *s,*t;
s=&main[0];
t=&sub[0];
int q=substring(s,t);
if(q==-1){printf("Not a substring\n");}
else{printf("%d\n",q);}
}
