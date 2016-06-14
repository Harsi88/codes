#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

void print(node *head){
	node *cur=head;
	while(cur->next != NULL){
		printf("%d ",cur->data);
		cur=cur->next;
	}
	printf("%d",cur->data);
	printf("\n");
}

node* add(node *head,int pos){
	//pos=0 add before head
	//pos=-1 append at last
	//pos=1,2,3..... add after link 1,2,3...
	node *cur,*cur1;
	int i;
	if(pos==0){
		cur=(node*)malloc(sizeof(node));
		cur->next = head;
		return cur;
	}
	if(pos==-1){
		cur=head;
		cur1=(node*)malloc(sizeof(node));
		while(cur->next != NULL){
			cur=cur->next;
		}
		cur->next = cur1;
		return head;
	}
	else{
		node *curnext;
		cur = head;
		curnext=cur->next;
		cur1=(node*)malloc(sizeof(node));
		for(i=1;i<pos;++i){
			cur=cur->next;
			curnext=cur->next;
		}
		cur->next=cur1;
		cur1->next=curnext;
		return head;
	}
}

node* del(node *head,int pos){
	//pos=1,2,3,4.....delete link 1,2,3,4......
	//pos=-1 delete last link
	node *cur,*cur1;
	int i;
	if(pos==1)
	{	cur=head->next;
		free(head);
		return cur;
	}
	if(pos==-1)
	{	cur=head;
		while(cur->next != NULL){
			cur1=cur;
			cur=cur->next;
		}
		cur1->next=NULL;
		free(cur);
		return head;
	}
	else
	{	node *curnext;
		cur = head;
		curnext=cur->next;
		cur1=(node*)malloc(sizeof(node));
		for(i=1;i<pos;++i){
			cur1=cur;
			cur=cur->next;
			curnext=cur->next;
		}
		cur1->next=curnext;
		free(cur);
		return head;
	}
}

node *reverse_iterative(node *head)
{
	node *cur=head->next,*prev=head,*nxt;
	while(cur->next != NULL)
	{
		nxt = cur->next;
		cur->next = prev;
		prev = cur;
		cur = nxt;
	}
	cur->next=prev;
	head->next=NULL;
	head = cur;
	return head;
}

void reverse_recursive(node *head)
{
	node *last=head,*slast;
	if(head->next==NULL)
	{
		return;
	}

	else
	{
	while(last->next!=NULL)
	{
		slast=last;
		last=last->next;
	}
	slast->next=NULL;
	last->next=slast;
	reverse_recursive(head);
	}
	return;
}


main(){
int m,i;
node *head,*cur;
printf("Enter no. of strings to start:");
scanf("%d",&m);
for(i=1;i<=m;++i){
	if(i==1){
		head = (node*)malloc(sizeof(node));
		cur = head;
	}
	else{
		cur->next = (node*)malloc(sizeof(node));
		cur = cur->next;
	}
	printf("enter data:");
	scanf("%d",&cur->data);
}
cur->next=NULL;
print(head);
node *rhead=reverse_iterative(head);
//while(rhead->next!=NULL)rhead=rhead->next;
//print(head);
//reverse_recursive(head);
print(rhead);
/*head=add(head,-1);
print(head);
head=del(head,1);
print(head);*/
}
