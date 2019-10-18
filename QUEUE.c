#include<stdio.h>
#include<stdlib.h>
typedef struct Queue
{
	int front;
	int rear;
	int capacity;
	int *arr;
}Queue;
enum bool{false,true};
Queue *createQueue(int capacity)
{
	Queue *Q=NULL;
	Q=(Queue*)malloc(sizeof(Queue));
	if(Q==NULL)
	{
		printf("Memory Overflow\n");
		return NULL;
	}
	Q->front=-1;
	Q->rear=-1;
	Q->capacity=capacity;
	Q->arr=(int*)malloc(sizeof(int)*capacity);
	return Q;
}
enum bool isEmpty(Queue *Q)
{
	return (Q->front==-1||(Q->front==Q->rear+1));
}
enum bool isFull(Queue *Q)
{
	return Q->rear==Q->capacity-1;
}
enum bool insertion(Queue *Q,int element)
{
	if(isFull(Q))
	{
		printf("Queue is Overflow\n");
		return false;
	}
	if(isEmpty(Q))
	{
		Q->front=0;
	}
	Q->arr[++Q->rear]=element;
	return true;
}
int deletion(Queue *Q)
{
	if(isEmpty(Q))
	{
		printf("Queue is Underflow\n");
		Q->front=-1;
		Q->rear=-1;
		return false;
	}
	return Q->arr[Q->front++];

}
int main()
{
	Queue *Q=createQueue(5);
	insertion(Q,10);
	insertion(Q,20);
	insertion(Q,30);
	//insertion(Q,40);
	//insertion(Q,50);
	//insertion(Q,60);
	printf("[%d]\n",deletion(Q));
	printf("[%d]\n",deletion(Q));
	printf("[%d]\n",deletion(Q));
	printf("[%d]\n",deletion(Q));
	//printf("[%d]\n",deletion(Q));
	//printf("[%d]\n",deletion(Q));
	insertion(Q,100);
	insertion(Q,300);
	insertion(Q,400);
	insertion(Q,500);
	insertion(Q,600);
	printf("[%d]\n",deletion(Q));
	printf("[%d]\n",deletion(Q));
	printf("[%d]\n",deletion(Q));
	printf("[%d]\n",deletion(Q));
	printf("[%d]\n",deletion(Q));
	printf("[%d]\n",deletion(Q));
}