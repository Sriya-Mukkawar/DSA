#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define N 5
int queue[N];
int front = -1;
int rear = -1;
void enqueue(int x){
	if(rear==N-1){
		printf("Queue is Full");
		printf("\n");
	}
	else if(front==-1 && rear==-1){
		front = rear = 0;
		queue[rear]=x;
	}
	else{
		rear++;
		queue[rear]=x;
	}
}
void dequeue(){
	if(front==-1 && rear==-1){
		printf("Queue is empty");
		printf("\n");
	}
	else if(front==rear){
		front=rear=-1;
	}
	else{
		printf("%d\n",&queue[rear]);
		front++;
	}
}
void display(){
	int i;
	if(front==-1 && rear==-1){
		printf("Queue is empty");
		printf("\n");
	}
	else{
		for(i=front;i<rear+1;i++){
			printf("%d ",queue[i]);
		}
	}
}
void peek(){
	if(front==-1 && rear==-1){
		printf("Queue is empty");
		printf("\n");
	}
	else{
		printf("%d ",queue[front]);
	}
}
void main(){
	enqueue(2);
	enqueue(5);
	enqueue(-1);
	display();
	peek();
	dequeue();
	peek();
	display();
}
