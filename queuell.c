#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *front = 0;
struct node *rear = 0;
void enqueue(int x){
	struct node *newnode;
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data = x;
	newnode->next = 0;
	if(front==-1 && rear==-1){
		front = rear = newnode;
	}
	else{
		rear->next = newnode;
		rear = newnode;
	}
}
void dequeue(){
	struct node *temp;
	temp = front;
	if(front==0 && rear==0){
		printf("Queue is empty");
	}
	else{
		printf("%d",front->data);
		front = front->next;
		free(temp);
	}
}
void peek(){
	if(front==0 && rear == 0){
		printf("Queue is empty");
	}
	else{
		printf("%d",front->data);
	}
}
void display(){
	struct node *temp;
	if(front==0 && rear ==0){
		printf("Queue is empty");
	}
	else{
		temp = front;
		while(temp!=0){
			printf("%d",temp->data);
			temp = temp->next;
		}
	}
}
void main(){
	enqueue(5);
	enqueue(0);
	enqueue(-1);
	display();
	dequeue();
	peek();
}
