#include<stdio.h>
void quick(int *l,int *u)
{
int *i;int *up;up=l;int *down;down=u;int *pvt;pvt=l;
if(u==l){return;}
while (pvt==l)
{
for(i=down;i>=l;i--){if((*i)<=(*pvt)){down=i; break;}}
for(i=up;i<=u;i++){if((*i)>(*pvt)){up=i; break;}}
if(up<down && down!=u && up!=l){int temp=*up; *up=*down; *down=temp;}
if(up>=down && down!=u && up!=l){int temp=*pvt; *pvt=*down; *down=temp; pvt=down; break;}
if(down==u && (*u)>(*pvt) && up!=l){pvt=l; break;}
if(down==u && (*u)<=(*pvt) && up!=l){int temp=*up; *up=*down; *down=temp;}
if(down==u && (*u)<(*pvt) && up==l){int temp=*up; *up=*down; *down=temp; pvt=u; break;}
if(up==l && down!=u){int temp=*up; *up=*u; *u=temp; pvt=u; break;}
if(up==l && down==u){int temp=*up; *up=*down; *down=temp;pvt=l; break;}
}
if(pvt==l){quick(l+1,u); return;}
if(pvt==u){quick(l,u-1); return;}
if(pvt==down){quick(l,pvt-1);quick(pvt+1,u);quick(pvt,pvt);return;}
}
int main(){
int a[10]={4,10,5,6,8,9,7,1,2,3};
quick(&a[0],&a[9]);
int i;
for (i=0;i<=9;i++){
printf("%d ",a[i]);
}
}
