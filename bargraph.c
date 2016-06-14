#include<stdio.h>

int main()
{
    printf("Enter no. of Data:\n");
    int i,j,n,max;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;++i)
    {
        scanf("%d",&a[i]);
        if(i==0)max=a[i];
        if(i>0)
        {
            max = a[i]>a[i-1]?a[i]:max;
        }
    }

    for(j = 0; j < max; ++j)
    {
        for(i = 0 ; i < n ; ++i)
        {
            if(a[i] >= max - j)printf("* ");
            else printf("  ");
        }
        printf("\n");
    }
}
