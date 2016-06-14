#include<stdio.h>
void quick(int a[],int l,int u)
{
int i,up=l,down=u,pvt=l;
if(u==l){return;}
while (pvt==l)
{
for(i=down;i>=l;i--){if(a[i]<=a[pvt]){down=i; break;}}
for(i=up;i<=u;i++){if(a[i]>a[pvt]){up=i; break;}}
if(up<down && down!=u && up!=l){int temp=a[up]; a[up]=a[down]; a[down]=temp;}
if(up>=down && down!=u && up!=l){int temp=a[pvt]; a[pvt]=a[down]; a[down]=temp; pvt=down; break;}
if(down==u && a[u]>a[pvt] && up!=l){pvt=l; break;}
if(down==u && a[u]<=a[pvt] && up!=l){int temp=a[up]; a[up]=a[down]; a[down]=temp;}
if(down==u && a[u]<a[pvt] && up==l){int temp=a[up]; a[up]=a[down]; a[down]=temp; pvt=u; break;}
if(up==l && down!=u){int temp=a[up]; a[up]=a[u]; a[u]=temp; pvt=u; break;}
if(up==l && down==u){int temp=a[up]; a[up]=a[down]; a[down]=temp;pvt=l; break;}
}
if(pvt==l){quick(a,l+1,u); return;}
if(pvt==u){quick(a,l,u-1); return;}
if(pvt==down){quick(a,l,pvt-1);quick(a,pvt+1,u);quick(a,pvt,pvt);return;}
}
int main(){
int a[10]={10,4,5,5,8,1,1,-12,48,10};
quick(a,0,9);
int i;
for (i=0;i<=9;i++){
printf("%d ",a[i]);
}
}
