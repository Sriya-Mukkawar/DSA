#include<stdio.h>
#include<stdlib.h>
struct node{
	int info;
	struct node *ptr;
};
struct node *top,*top1,*temp;

int topelt();
void push(int data);
void pop();
void empty();
void display();
void destroy();
void stack_count();
void create();

int count = 0;

void main(){
	int no,ch,e;
	
	printf("\n 1 is push");
	printf("\n 2 is pop");
	printf("\n 3 is Top");
	printf("\n 4 is Empty");
	printf("\n 5 is Exit");
	printf("\n 6 is Display");
	printf("\n 7 is Stack count");
	printf("\n 8 is Destroy stack");
	
	create();
	while(1){
		
		printf("\n Enter the choice");
		scanf("%d",&ch);
		
		switch(ch){
			case 1:
				printf("Enter the data");
				scanf("%d",&no);
				push(no);
				break;
			case 2:
				pop();
				break;
			case 3:
				if(top==NULL){
					printf("Stack is empty");
				}
				else{
				e = topelt();
				printf("Top element is %d",e);
				}	
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
				stack_count();
				break;
			case 8:
				destroy();
				break;
			default:
				printf("Invalid output");
				break;
		}
	}	
}
void create(){
	top=NULL;
}

void stack_count(){
	printf("Number of elements in the stack is %d",count);
}

void push(int data){
	if(top==NULL){
		top=(struct node*)malloc(1*sizeof(struct node));
		top->ptr = NULL;
		top->info = data;
	}
	else{
		temp=(struct node*)malloc(1*sizeof(struct node));
		temp->info=data;
		temp->ptr=top;
		top=temp;
	}
	count++;
}

void pop(){
	top1=top;
	if(top1==NULL){
		printf("Stack is already empty");
		return;
	}
	else
		top1=top1->ptr;
		printf("Popped out element is %d",top->info);
		free(top);
		top=top1;
		count--;
}

void display(){
	top1=top;
	if(top==NULL){
		printf("Stack is empty");
	}
	else{
		while(top1!=NULL){
			printf("%d",top1->info);
			top1 = top1->ptr;
		}
	}
}

int topelt(){
	return(top->info);
}

void empty(){
	if(top==NULL){
		printf("Stack is empty");
	}
	else{
		printf("Stack is not empty with %d elements",count);
	}
}

void destroy(){
	top1 = top;
	while(top1!=NULL){
		top1=top1->ptr;
		free(top);
		top=top1;
		top1=top1->ptr;
	}
	free(top1);
	top=NULL;
	
	printf("stack is destroyed");
	count=0;
}
