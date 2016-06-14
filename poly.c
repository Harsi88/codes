#include<stdio.h>
#include<stdlib.h>

typedef struct poly{
	int power;
	float coeff;
	struct poly *next;
}poly;

void print(poly *head){
	poly *cur=head;
	while(cur->next != NULL){
		printf("%d %f ",cur->power,cur->coeff);
		cur=cur->next;	
	}
	printf("\n");
}

poly *add(poly *p,poly *q){
	poly *cp=p,*cq=q,*cur,*add,*prev;
	int flag=1,lflag=1,oflag=1;
	while(lflag==1){
	if(cp->power >= cq->power){
		while(cp!=NULL){
			if(cp->power==cq->power){
				cur=(poly*)malloc(sizeof(poly));
				if(flag==0 && oflag==1){add->next=cur;oflag=0;}
				cur->power=cp->power;
				cur->coeff=cp->coeff + cq->coeff;
				prev=cur;
				if(flag==1){add=cur;flag=0;}
				cp=cp->next;
				cq=cq->next;
			}
			else{
				cur=(poly*)malloc(sizeof(poly));
				if(flag==0 && oflag==1){add->next=cur;oflag=0;}
				cur->power=cp->power;
				cur->coeff=cp->coeff;
				if(flag==1){add=cur;flag=0;}
				prev->next=cur;
				prev=cur;
			}
		}
		lflag=0;
	}
	else{
		poly *temp;
		temp=cp;cp=cq;cq=temp;
	}
	return add;
}
}

poly *sub(poly *p,poly *q){
	poly *cp=p,*cq=q,*sub;
	while(cq->next!=NULL){cq->coeff=-cq->coeff;cq=cq->next;}
	cq=q;
	if(cp->power >= cq->power){sub=add(cp,cq);}
	else{
		sub=add(cq,cp);
	}
	return sub;
}

poly *prod(poly *p,poly *q){
	
}


main(){
	poly *p,*q,*cur;
	char op;
	printf("Enter input:\n");
	scanf("%c",&op);
	int i=-2;
	float j;
	while(i!=-1){
		if(i==-2){
			p=(poly*)malloc(sizeof(poly));
			cur=p;
		}
		else{
			cur->next=(poly*)malloc(sizeof(poly));
			cur=cur->next;
		}
		scanf("%d",&i);
		if(i!=-1){
			cur->power=i;
			scanf("%f",&j);
			cur->coeff=j;
		}
	}
	i=-2;
	while(i!=-1){
		if(i==-2){
			q=(poly*)malloc(sizeof(poly));
			cur=q;
		}
		else{
			cur->next=(poly*)malloc(sizeof(poly));
			cur=cur->next;
		}
		scanf("%d",&i);
		if(i!=-1){
			cur->power=i;
			scanf("%f",&j);
			cur->coeff=j;
		}
	}
print(p);
print(q);
poly *ans=add(p,q);
//print(ans);
while(ans->next!=NULL){
	printf("%fx^%d ",ans->coeff,ans->power);
	ans=ans->next;
}
printf("%fx^%d \n",ans->coeff,ans->power);
}
