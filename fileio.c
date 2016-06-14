#include<stdio.h>

int main(int an,char *ab[])
{
//printf("%d %s\n",an,ab[0]);
if(an<2){printf("supply the target\n");return;}
FILE *fp,*fp1;
short int chr=0,line=0,para=0,c,q;
int a;
fp=fopen(ab[1],"r");
if(fopen==0){printf("error opening\n");return;}
printf("Do you want to copy this file to some other file:\n1)yes 2)no\n");
scanf("%d",&a);
if(a==1){
    fp1=fopen('newfile.txt',"w");
}
while((c=getc(fp))!=EOF){
    chr+=1;
    if(c=='.'){line+=1;}
    if(c=='\n'){para+=1;}
if(a==1){putc(fp1,c);}
printf("%c",c);
}
fclose(fp);
fclose(fp1);
printf("no. of characters are %d\nno. of lines are %d\nno. of paragraphs are %d\n",chr,line,para);
}
