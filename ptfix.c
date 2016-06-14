#include<stdio.h>
#include<math.h>

int flag = -1;
int *ptr=&flag;
float stack[100];

void push(int n){
	++(*ptr);
	stack[flag] = n;
}

float pop(){
	float n = stack[(*ptr)];
	--(*ptr);
	return n;
}

float evaluate(char a[]){
	int i=0,j;float x=0,y=0;int z;
	int s[100];
	while(a[i] != '\0'){
	x=0;y=0;
	if(a[i]=='<'){
		++i;
		if(a[i]!='+' && a[i]!='-' && a[i]!='/' && a[i]!='*'){
			j=0;
			while(a[i] != '>'){++i;}
			--i;
			while(a[i] != '<'){
				z=(a[i]-48);
				x=x+(z*(pow(10,j)));
				--i;
				++j;
			}
			push(x);
			while(a[i] != '>'){++i;}
		}
		if(a[i]=='+'){
			x=pop();
			y=pop();
			x=x+y;
			push(x);
			++i;
		}
		if(a[i]=='-'){
			x=pop();
			y=pop();
			y=y-x;
			push(y);
			++i;
		}
		if(a[i]=='/'){
			x=pop();
			y=pop();
			y=y/x;
			push(y);
			++i;
		}
		if(a[i]=='*'){
			x=pop();
			y=pop();
			x=x*y;
			push(x);
			++i;
		}
		++i;
	}
}
x=pop();
return x;
}

int priority(char a)
{
    if(a=='-')return 1;
    else if(a=='+')return 2;
    else if(a=='*')return 3;
    else if(a=='/')return 4;
    else return 0;
}

char *intopost(char a[])
{
    char post[100];
    char st[50];
    char *pst=post;
    char b;
    int i=0,j=0,k=0,inprt,outprt;
    while(a[i]!='\0')
    {   printf("loop\n");
        if(a[i]!='+' && a[i]!='-' && a[i]!='*' && a[i]!='/')
        {   printf("1\n");
            post[j]='<'; ++j;
            post[j]=a[i]; ++j;
            post[j]='>'; ++j;
            printf("%c %c %c\n",post[j-3],post[j-2],post[j-1]);
        }
        if(a[i]=='+' || a[i]=='-' || a[i]=='*' || a[i]=='/')
        {   printf("2\n");
            outprt=priority(a[i]);
            if(*ptr==-1){printf("2.1\n");st[k]=a[i]; ++k;}
            else
            {   printf("2.2\n");
                --k;b=st[k];
                if(priority(b)<outprt){printf("2.2.1\n");st[k]=a[i]; ++k;}
                else
                {   printf("2.2.2\n");
                    while(priority(b)>=outprt)
                    {   printf("2.2.2 loop\n");
                        post[j]='<'; ++j;
                        post[j]=b; ++j;
                        post[j]='>'; ++j;
                        printf("%c %c %c\n",post[j-3],post[j-2],post[j-1]);
                        if(k==0)break;
                        --k;
                        b=st[k];
                    }
                    if(k!=0){st[k]=b;++k;}
                    st[k]=a[i];++k;
                }
            }
        }
        ++i;
    }
    char q;
    while(k != 0)
    {   printf("LOOP\n");
        --k;q=st[k];
        post[j]='<'; ++j;
        post[j]=q; ++j;
        post[j]='>'; ++j;
        printf("%c %c %c\n",post[j-3],post[j-2],post[j-1]);
    }
    return pst;
}

main(){
char array[100];
printf("enter postfix expression to evaluate:");//use (<>)as separator Eg.:5+3 = <5><3><+>
scanf("%s",array);
float ans=evaluate(array);
/*char *i;
for(i=ans;*i!='\0';++i){
printf("%c",*i);
}
while((*ans)=='\0')
{   printf("Enter");
    printf("\n%c",*ans);
    ++ans;
}*/
printf("%f",ans);
}
