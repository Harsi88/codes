#include<stdio.h>
void swp(int *pta,int *ptb){
	int temp=*ptb;
	*ptb=*pta;*pta=temp;
	return;
}
void bsort(int *ptr){
	int i,flag=1;
	int *pt0,*pt1;
	while(flag!=0){
		flag=0;
		pt0=ptr;
		for (i=0;i<=8;i++){
			pt1=pt0+1;
			if (*pt0>*pt1){swp(&*pt0,&*pt1); flag=flag+1;}
			pt0++;
		}
	}
	return;
}
void quick(int *l,int *u)
{
	int *i;int *up;up=l;int *down;down=u;int *pvt;pvt=l;
	if(u==l){return;}
	while (pvt==l){
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
	int n;printf("enter number of elements in array\n");
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++){
		printf("enter a[%d]:",i);
		scanf("%d",&a[i]);
	}
	int j;
	printf("Enter your choice to sort an array 1)Bubblesort 2)Quicksort\n"); 
	scanf("%d",&j);
	if(j==1){bsort(&a[0]);}
	else if(j==2){quick(&a[0],&a[n-1]);}
	else{printf("enter valid choice");}
	printf("sorted array is:\n");
	for(i=0;i<n;i++){printf("%d ",a[i]);}
}
