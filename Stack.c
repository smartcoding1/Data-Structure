#include<stdio.h>
#include<stdlib.h>
struct Stack
{
	int top;
	int capacity;
	int *arr;
};

struct Stack * createStack(int capacity)
{
	struct Stack *S=malloc(sizeof(struct Stack));
	S->capacity=capacity;
	S->top=-1;
	S->arr=malloc(sizeof(int)*capacity);
	return S;
}

int isOverflow(struct Stack *S)
{
	return S->top==(S->capacity-1);
}

int isUnderflow(struct Stack *S)
{
	return S->top==-1;
}

void push(struct Stack *S,char element)
{
	if(isOverflow(S))
	{
		printf("Stack is overflow\n");
		return ;
	}
	S->arr[++S->top]=element;
}

int pop(struct Stack *S)
{
	if(isUnderflow(S))
	{
		printf("Stack is underflow\n");
		return -1;
	}
	return S->arr[S->top--];
}
int peek(struct Stack *S)
{
	return S->arr[S->top];
}
/*int main()
{
	struct Stack *S=createStack(5);
	push(S,'a');
	push(S,'r');
	push(S,'b');
	push(S,'a');
	push(S,'z');
	push(S,'b');
	printf("%c",pop(S));
	printf("%c",pop(S));
	printf("%c",pop(S));
	printf("%c",pop(S));
	printf("%c\n",pop(S));
	printf("%c",pop(S));
	return 0;
}*/
