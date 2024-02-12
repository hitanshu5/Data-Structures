#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#define MAX 100
char st[MAX];
int top = -1;
int getPriority(char ch)
{
	if(ch=='/'||ch=='*'||ch=='%'||ch=='^')
		return 1;
	else if(ch=='+'||ch=='-')
		return 0;
}
void push(char val)
{
	if(top == MAX-1)
	printf("Stack overflow");
	else
	st[++top] = val;
}
char pop()
{
	if(top == -1)
	{
		printf("Stack is empty");
		return -1;
	}
	else
	return st[top--];
}
void infixToPostfix(char source[],char target[])
{
	int i = 0,j = 0;
	char temp;
	strcpy(target, "");
	while(source[i] != '\0')
	{
		if(source[i]=='(')
		{
			push(source[i]);
			i++;
		}
		else if(source[i]==')')
		{
			while((top!=-1)&&(st[top]!='('))
			{
				target[j]=pop();
				i++;
			}
			if(top == -1)
			{
				printf("\nIncorrect Exp");
				exit(1);
			}
			temp = pop(st);
			i++;
		}
		else if(isdigit(source[i]) || isalpha(source[i]))
		{
			target[j]=source[i];
			j++;
			i++;
		}
		else if(source[i]=='+'||source[i]=='-'||source[i]=='*'||source[i]=='/'||source[i]=='%' ||source[i]=='^')
		{
			int prio_source = getPriority(source[i]);
			int prio_st = getPriority(st[top]);
			while((top!=-1) && (st[top]!='(') && (prio_st<prio_source))
			{ 
				target[j] = pop();
				j++;
			}
			push(source[i]);
			i++;
		}
		else
		{
			printf("\nInvalid element");
			exit(1);
		}
	}
	while((top!=-1) && (st[top]!='('))
	{
		target[j] = pop();
		j++;
	}
	target[j]='\0';
}
 
void main()
{
	char infix[MAX],postfix[MAX];
	printf("\nEnter an expression ");
	gets(infix);
	strcpy(postfix,"");
	infixToPostfix(infix,postfix);
	printf("\nThe postfix is ");
	puts(postfix);
}
