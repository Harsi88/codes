#include<iostream>
#include<cmath>
using namespace std;


template <class t> class stck
{
	t stack[100];
	int top;
	int *ptr;
public:
	stck()
	{
		top=-1;
		ptr=&top;
	}
	void push(t n)
	{
		if(top==100) cout<<"STACK IS FULL";
		else 
		{
			(*ptr)++;
			stack[*ptr]=n;
		}
	}

	t pop()
	{
		if(top==-1) cout<<"STACK IS EMPTY";
		else
		{
			t a=stack[*ptr];
			stack[*ptr]=0;
			(*ptr)--;
			return a;
		}
	}
};

double pfevl(char ip[])
{
	stck<double> obj;
	int i=0,j;
	double number=0,num1,num2;
	while(ip[i]!='\0')
	{
		if(ip[i]=='<') ++i;
		if(ip[i]!='+' && ip[i]!='-' && ip[i]!='*' && ip[i]!='/' && ip[i]!='^' && ip[i]!='>' && ip[i]!='<')
		{
			number=number*10+(ip[i]-48);
		}
		else if(ip[i]=='>')
		{
			obj.push(number);
			number=0;
		}
		else if(ip[i]=='+' || ip[i]=='-' || ip[i]=='*' || ip[i]=='/' || ip[i]=='^')
		{
			num1=obj.pop();
			num2=obj.pop();
			if(ip[i]=='+') obj.push(num2+num1);
			else if(ip[i]=='-') obj.push(num2-num1);
			else if(ip[i]=='*') obj.push(num2*num1);
			else if(ip[i]=='/') obj.push(num2/num1);
			else if(ip[i]=='^') obj.push(pow(num2,num1));
			i++;
		}
		++i;
	}
	return obj.pop();
}

class arr
{
	char op[100];
	int op_iterator;
public:	
	arr()
	{
		op_iterator=0;	
	}
	void insert(char num)
	{
		op[op_iterator++]='<';
		op[op_iterator++]=num;
		op[op_iterator++]='>';
	}
}

arr inpost(char ip[])
{
	stck<char> obj;
	arr opobj;
	int loop_iterator=0;
	while(ip[loop_iterator]!='\0')
	{
		if(ip[loop_iterator]!='+' && ip[loop_iterator]!='-' && ip[loop_iterator]!='*' && ip[loop_iterator]!='/' && ip[loop_iterator]!='^')
		{
			opobj.insert(ip[loop_iterator]);
		}
		if(ip[loop_iterator]=='(')
		{		
			obj.push(ip[loop_iterator]);
		}
		if(ip[loop_iterator]==')')
		{	
			char stack_value=obj.pop();
			while(stack_value!='(')
			{
				opobj.insert(stack_value);
				stack_value=obj.pop();
			}
		}
		if(ip[loop_iterator]=='^') obj.push(ip[loop_iterator]);
		if(ip[loop_iterator]=='*' || ip[loop_iterator]=='/')
		{
			char top_value=obj.pop();
			while(top_value!='+' || top_value!='-' || top_value!='(')
			{
				opobj.insert(top_value);
				top_value=obj.pop();
			}
			obj.push(top_value);
		}
		if(ip[loop_iterator]=='+' || ip[loop_iterator]=='-')
		{
			char top_value=obj.pop();
			while(top_value!='(')
			{
				opobj.insert(top_value);
				top_value=obj.pop();
			}
			obj.push(top_value);
		}
		loop_iterator++;
	}
	return opobj;
}

int main()
{
	char array[100];
	//cout<<"enter postfix expression to evaluate:\n";//use (< >)as separator Eg.:5+3 = <5><3><+>
	cout<<"enter infix expression for conversion:\n";
	cin>>array;
	arr obj=inpost(array);
	int index=0;
	while(obj.a[index]!='\0')
	{
		cout<<obj.a[index];
		index++;
	}
	//float ans=pfevl(array);
	//cout<<ans<<"\n";
}		
