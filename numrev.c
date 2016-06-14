#include<stdio.h>
#include<math.h>

int main()
{
    int x,y=0,temp,prev,q,i=0;
    scanf("%d",&x);
    temp = x;
    while(temp>0)
    {
        printf("loop 1\n");
        i+=1;
        temp=temp/10;
    }
    printf("%d\n",i);
    temp = x;
    while(temp>0)
    {
        printf("loop 2\n");
        --i;
        prev=temp;
        temp/=10;
        temp*=10;
        q=prev-temp;
        y+=pow(q,10*i);
        temp/=10;
    }
    printf("%d\n",y);
}
