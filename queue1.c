#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *ptr;
};
struct node *front,*front1,*rear,*temp;

int frontelt();
void enq(int data);
void deq();
void display();
void empty();
void create();
void queuesize();
int count=0;

void main(){
	int no,ch,e;
	printf("\n 1 is Enqueue");
	printf("\n 2 is Dequeue");
	printf("\n 3 is Front element");
	printf("\n 4 is Empty");
	printf("\n 5 is Exit");
	printf("\n 6 is Display");
	printf("\n 7 is Queue size");
	
	create();
	
	while(1){
	printf("\nEnter the choice: ");
	scanf("%d",&ch);
	
	switch(ch){
		case 1: 
			printf("\nEnter the data: ");
			scanf("%d",&no);
			enq(no);
			break;
		case 2:
			deq();
			break;
		case 3:
			e = frontelt();
			if(e!=0)
				printf("\nFront element is : %d",e);
			else
				printf("\nNo element in the queue as queue is empty");
			break;
		case 4:
			empty();
			break;
		case 5:
			exit(0);
		case 6:
			display();
			break;
		case 7:
			queuesize();
			break;
		default:
			printf("\nInvalid choice");
		}
	}		
}

void create(){
	front=rear=NULL;
}

void queuesize(){
	printf("\nSize of the queue is %d",count);
}

void enq(int data){
	if(rear==NULL){
		rear=(struct node*)malloc(1*sizeof(struct node));
		rear->ptr=NULL;
		rear->info=data;
		front=rear;
	}
	else{
		temp=(struct node*)malloc(1*sizeof(struct node));
		rear->ptr=temp;
		temp->info=data;
		temp->ptr=NULL;
		rear = temp;
	}
	count++;
}

void display(){
	front1 = front;
	if((front1==NULL) && (rear==NULL)){
		printf("\nQueue is empty");
		return;
	}
	while(front1!=rear){
		printf("\n%d",front1->info);
		front1=front1->ptr;
	}
	if(front1==rear){
		printf("\n%d",front1->info);
	}
}

void deq(){
	front1=front;
	if(front1==NULL){
		printf("\nQueue is empty");
	}
	else
		if(front->ptr!=NULL){
			front1=front1->ptr;
			printf("\nDequeued element is: %d ",front->info);
			free(front);
			front=front1;
		}
		else{
			printf("Dequeued element is: %d ",front->info);
			free(front);
			front=NULL;
			rear=NULL;
		}
	count--;
}

int frontelt(){
	if((front==NULL) && (rear==NULL))
		return(front->info);
	else
		return 0;
}

void empty(){
	if((front==NULL) && (rear==NULL))
		printf("\n Queue is empty");
	else
		printf("\n Queue is consisting of %d values",count);
}



