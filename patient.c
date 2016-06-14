#include<stdio.h>
#include<string.h>
typedef struct{

	char name[30];
	char gender;
	float age,ht,wt;
} patient;

void bs(float a[]){
int i,flag=1;
while(flag!=0){
    flag=0;
	for (i=0;i<=8;i++){
		if (a[i]>a[i+1]){
		int temp=a[i];
		a[i]=a[i+1];
		a[i+1]=temp;
		flag=flag+1;
		}
	}
}
return;
}
float mean(float a[],int n){
int m;float sum=0;
for (m=0;m<=n-1;m++){sum=sum+a[m];}
return sum/n;
}
float mode(float a[],int n){
int m,inc=0,pos,freq1=1,freq2=1;
bs(a);
if(n==1){return 1.11;}
else{
	while(m<=n-2){
		if(a[m]=a[m+1]){inc=inc+1;freq1=inc;}
		else{inc=0;
			if(freq1>freq2){pos=m;freq2=freq1;}
			if(freq1==freq2){freq2=freq1;}
		}
	}
return a[pos];}
}

float median(float a[],int n){
bs(a);
if (n%2==1){return a[(n+1)/2];}
if (n%2==0){return 0.5*(a[n/2]+a[(n/2)+1]);}
}

int main(){
	patient p[50]; int n,i,x,y,z;
	printf("enter no. of patients:\n");
	scanf("%d",&n);
	for (i=0;i<n;i++){
		printf("enter patient's name:\n");
		scanf("%s",&p[i].name); 
		printf("enter patient's gender:\n");
		scanf("%s",&p[i].gender);
		printf("enter patient's age:\n");
		scanf("%f",&p[i].age);
		printf("enter patient's height:\n");
		scanf("%f",&p[i].ht);
		printf("enter patient's weight:\n");
		scanf("%f",&p[i].wt);
		}
	printf("enter choice 1) median 2) mode 3) mean\n");
	scanf("%d",&x);
	if (x!=1 && x!=2 && x!=3){printf("enter correct choice");}
	printf("enter choice 1) male 2) female 3)all\n");
	scanf("%d",&y);
	if (y!=1 && y!=2 && y!=3){printf("enter correct choice");}
	printf("enter choice 1) age 2) weight 3) height\n");
	scanf("%d",&z);
	if (z!=1 && z!=2 && z!=3){printf("enter correct choice");}
	int s=0;float q[50];
	
	if (y==1 && z==1){
		for (i=0;i<n;i++){
			if (p[i].gender=='m'){q[s]=p[i].age;  s=s+1;}
		}
	}
	if (y==1 && z==2){
		
		for (i=0;i<n;i++){
			if (p[i].gender=='m'){q[s]=p[i].wt;  s=s+1;}
		}
	}
	if (y==1 && z==3){
		
		for (i=0;i<n;i++){
			if (p[i].gender=='m'){q[s]=p[i].ht;  s=s+1;}
		}
	}
	if (y==2 && z==1){
		
		for (i=0;i<n;i++){
			if (p[i].gender=='f'){q[s]=p[i].age;  s=s+1;}
		}
	}
	if (y==2 && z==2){
		
		for (i=0;i<n;i++){
			if (p[i].gender=='f'){q[s]=p[i].wt;  s=s+1;}
		}
	}
	if (y==2 && z==3){
		
		for (i=0;i<n;i++){
			if (p[i].gender=='f'){q[s]=p[i].ht;  s=s+1;}
		}
	}
	if (y==3 && z==1){
		
		for (i=0;i<n;i++){
			q[s]=p[i].age;  s=s+1;}
		}
	
	if (y==3 && z==2){
		
		for (i=0;i<n;i++){
			q[s]=p[i].wt;  s=s+1;}
		}
	
	if (y==3 && z==3){
		
		for (i=0;i<n;i++){
			q[s]=p[i].ht;  s=s+1;}
		}
	
	if (x==1){
		float m1;
                m1=median(q,s);
		printf("median is %f \n",m1);
	}
	if (x==3){
		float m3;
		m3 =mean(q,s);
		printf("mean is %f \n",m3);
	}
	if (x==2){
		if(s==1){printf("no mode pesent");}
		else{
			float m2;
			m2=mode(q,s);
			printf("mode is %f \n",m2);
		}
	}
}

