#include"Queue-1.c"
typedef struct Stack{
	Queue *Q1;
	Queue *Q2;
}Stack;

Stack *createStack(int capacity){
	Stack *S=(Stack*)malloc(sizeof(Stack));
	S->Q1=createQueue(capacity);
	S->Q2=createQueue(capacity);
}

void push(Stack *S,int element){
	if(isFull(S->Q1)||isFull(S->Q2)){
		printf("Stack is OVERFLOW\n");
		return;
	}
	if(!isEmpty(S->Q1)){
		enQueue(S->Q1,element);
	}
	else{
		enQueue(S->Q2,element);
	}
}

int pop(Stack *S){
	int element,i;
	if(isEmpty(S->Q1)&&isEmpty(S->Q2)){
		printf("Stack is UNDERFLOW\n");
		return -1;
	}
	if(!isEmpty(S->Q1)){
		while(!isEmpty(S->Q1))
		{
			element=deQueue(S->Q1);
			if(isEmpty(S->Q1))
				return element;
			enQueue(S->Q2,element);
		}
	}
	else{
		while(!isEmpty(S->Q2))
		{
			element=deQueue(S->Q2);
			if(isEmpty(S->Q2))
				return element;
			enQueue(S->Q1,element);
		}
	}
}

int main(){
	Stack *S=createStack(5);
	push(S,10);
	push(S,20);
	push(S,30);
	push(S,40);
	printf("[%d]\n",pop(S));
	printf("[%d]\n",pop(S));
	printf("[%d]\n",pop(S));
	printf("[%d]\n",pop(S));
	printf("[%d]\n",pop(S));
	push(S,50);
	push(S,60);
	push(S,70);
	push(S,80);
	push(S,90);
	push(S,100);
	printf("[%d]\n",pop(S));
	printf("[%d]\n",pop(S));
	printf("[%d]\n",pop(S));
	printf("[%d]\n",pop(S));
	printf("[%d]\n",pop(S));
}