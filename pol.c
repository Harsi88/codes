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
	poly *pp=p,*qq=q,*head,*cur;
	head=(poly*)malloc(sizeof(poly));
	cur=head;
	while(1)
		{if((pp->next==NULL) && (qq->next==NULL))break;

			if(pp->power==qq->power)
			{
				cur->power=pp->power;
				cur->coeff=pp->coeff+qq->coeff;
				cur->next=(poly*)malloc(sizeof(poly));
				cur=cur->next;
				if(pp->next!=NULL)pp=pp->next;
				if(qq->next!=NULL)qq=qq->next;
			}
			else if(pp->power != qq->power)
			{
				if((pp->power > qq->power || qq->next==NULL) && pp->next!=NULL)
				{
					cur->power=pp->power;
					cur->coeff=pp->coeff;
					cur->next=(poly*)malloc(sizeof(poly));
					cur=cur->next;
					pp=pp->next;
				}
				else if((qq->power > pp->power || pp->next==NULL) && qq->next!=NULL)
				{
					cur->power=qq->power;
					cur->coeff=qq->coeff;
					cur->next=(poly*)malloc(sizeof(poly));
					cur=cur->next;
					qq=qq->next;
				}
			}

	}
	return head;
}

poly *sub(poly *p,poly *q){
	poly *cp=p,*cq=q,*sub;
	while(cq->next!=NULL){cq->coeff=-cq->coeff;cq=cq->next;}
	cq=q;
	sub=add(cp,cq);
	return sub;
}

poly *prod(poly *p,poly *q)
{
    short int flag=1;
    poly *pp=p,*qq=q,*head,*temphead,*cur;
    while(pp->next!=NULL)
    {
        //if(flag==0){free(temphead);}
        temphead=(poly*)malloc(sizeof(poly));
        cur=temphead;
        qq=q;
        while(qq->next!=NULL)
        {
            cur->power=pp->power + qq->power;
            cur->coeff=pp->coeff*qq->coeff;
            cur->next=(poly*)malloc(sizeof(poly));
            cur=cur->next;
            qq=qq->next;
        }
        {if(flag==1){head=temphead;flag=0;}
        else{head=add(temphead,head);}}
        pp=pp->next;
    }
    return head;
}

poly *divi(poly *p,poly *q)
{
    poly *pp=p,*qq=q,*head,*cur,*qtemp=qq;
    float cofactor;
    int powfactor;
    print(q);
    while(pp->power >= q->power)
    {   //printf("1111\n");
        qq=q;
        cofactor=pp->coeff/q->coeff;
        powfactor=pp->power-q->power;
        while(qq->next!=NULL)
        {   //printf("2222\n");
            qq->power=qq->power+powfactor;
            qq->coeff=qq->coeff*cofactor;
            qq=qq->next;
        }
        pp=sub(pp,qtemp);
        qq=q;
        while(qq->next!=NULL){qq->coeff=-qq->coeff;qq=qq->next;}
        qq=q;
        while(qq->next!=NULL)
        {   //printf("3333\n");
            qq->power=qq->power-powfactor;
            qq->coeff=qq->coeff/cofactor;
            qq=qq->next;
        }
        pp=pp->next;
    }
    return pp;
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
poly *ans;
//ans=add(p,q);
//print(ans);
//ans=sub(p,q);
//print(ans);
ans=add(p,q);
print(ans);
}
