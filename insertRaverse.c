#include"Queue-1.c"
#include"Stack.c"
void print(Queue *Q)
{
	int i;
	for(i=Q->front;i<=Q->rear;i++)
		printf("[%d]\t",Q->arr[i]);
	printf("\n");
}
void insertInReverse(Queue *Q,int k)
{
	int i,element;
	struct Stack *S=createStack(k);
	Queue *Q1=createQueue(10);
	for(i=0;i<k&&!isEmpty(Q);i++)
	{
		push(S,deQueue(Q));
	}
	if(i==k){
		while(!isEmpty(Q)){
			enQueue(Q1,deQueue(Q));
		}
		while(!isUnderflow(S)){
			enQueue(Q,pop(S));
		}
		while(!isEmpty(Q1)){
			enQueue(Q,deQueue(Q1));
		}
	}
	else
		printf("k is greater than capacity");
}
int main()
{
	Queue *Q=createQueue(10);
	enQueue(Q,10);
	enQueue(Q,20);
	enQueue(Q,30);
	enQueue(Q,40);
	enQueue(Q,50);
	enQueue(Q,60);
	enQueue(Q,70);
	enQueue(Q,80);
	enQueue(Q,90);
	enQueue(Q,100);
	print(Q);
	insertInReverse(Q,3);
	print(Q);
	insertInReverse(Q,5);
	print(Q);
	insertInReverse(Q,7);
	print(Q);
	insertInReverse(Q,11);
}