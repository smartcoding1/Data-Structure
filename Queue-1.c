#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
enum bool{false,true};

struct Queue
{
	int rear;
	int front;
	int capacity;
	int *arr;
};

struct Queue typedef Queue;

Queue * createQueue(int capacity)
{
		Queue *Q=malloc(sizeof(Queue));
		if(Q==NULL){
			printf("Memory Overflows");
			return ;
		}
		Q->capacity=capacity;
		Q->arr=malloc(sizeof(int)*capacity);
		if(Q->arr==NULL){
			printf("Memory Overflows");
			return ;
		}
		Q->front=Q->rear=-1;
		return Q;
}

enum bool  isEmpty(Queue *Q)
{
	return (Q->rear==-1)&&(Q->front==-1);
}

enum bool isFull(Queue *Q)
{
	return (Q->front==(Q->rear+1)%Q->capacity); 
}

enum bool enQueue(Queue *Q,int data)
{
	/*if(isFull(Q)){
		printf("Queue is overflow\n");
		return false;
	}*/
	if(isEmpty(Q)){
		Q->front++;
	}
	Q->rear= (Q->rear+1)%Q->capacity;
	Q->arr[Q->rear]=data;
	return true;
}

int deQueue(Queue *Q)
{
	/*if(isEmpty(Q)){
		printf("Queue is undeflow\n");
		return -1;
	}*/

	int elem=Q->arr[Q->front];
	if(Q->rear==Q->front)
		Q->rear=Q->front=-1;
	else
		Q->front=(Q->front+1)%Q->capacity;
	return elem;
}
int getFront(Queue *Q)
{
	return Q->arr[Q->front];
}

