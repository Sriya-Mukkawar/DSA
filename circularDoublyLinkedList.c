#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head,*tail,*newnode;
void createcdll(){
	head = 0;
	int choice=1;
	while(choice){
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter data");
	scanf("%d",&newnode->data);
	newnode->next=0;
	newnode->prev=0;
	if(head==NULL){
		head=tail=newnode;
	}
	else{
		tail->next=head;
		head->prev=tail;
	}
	printf("Do you want to continue?(0,1)");
	scanf("%d",&choice);
	}
}
void insbeg(){
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data");
	scanf("%d",&newnode->data);
	newnode->next=0;
	newnode->prev=0;
	if(head=NULL){
		head=tail=newnode;
	}
	else{
		newnode->next=head;
		head->prev=newnode;
		head=newnode;
	}
}
void insend(){
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data");
	scanf("%d",&newnode->data);
	newnode->next=0;
	newnode->prev=0;
	tail->next=newnode;
	newnode->prev=tail;
	newnode->next=head;
	tail=newnode;
}
void inspos(){
	int pos;
	int i=1;
	printf("Enter the position");
	scanf("%d",&pos);
	if(pos<1 || pos>count()){
		printf("Invalid position");
	}
	else if(pos==1){
		insbeg();
	}
	else{
		struct node *temp;
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the data");
		scanf("%d",&newnode->data);
		while(i<pos-1){
			temp=temp->next;
			i++;
		}
		newnode->prev=temp;
		newnode->next=temp->next;
		temp->next=newnode;
		newnode->next->prev=newnode;
	}
}
void insaftpos(){
	int pos;
	int i=1;
	printf("Enter the pos");
	scanf("%d",&pos);
	if(pos<1 || pos>count()){
		printf("Invalid position");
	}
	else{
		struct node *temp;
		newnode = (struct node*)malloc(sizeof(struct node));
		printf("Enter the data");
		scanf("%d",&newnode->data);
		while(i<pos){
			temp = temp->next;
			i++;
		}
		newnode->prev=temp;;
		newnode->next=temp->next;
		temp->next=newnode;
		newnode->next->prev=newnode;
	}
}
void count(){
	int count=0;
	struct node *temp;
	temp=head;
	while(temp!=last){
		temp=temp->next;
		count++;
	}
	printf("\ncount is %d",count);
	printf("\n");
}
void delbeg(){
	struct node *temp;
	if(head==0){
		printf("List is empty");
	}
	else{
		temp=head;
		head=head->next;
		head->prev=tail;
		free(temp);
	}
}
void delend(){
	struct node *temp;
	if(tail==0){
		printf("List is emoty");
	}
	else{
		temp=tail;
		tail->prev->next=head;
		tail=tail->prev;
		free(temp);
	}
}
void delpos(){
	int pos;
	int i=1;
	printf("Enter the position");
	scanf("%d",&pos);
	struct node *temp;
	temp=head;
	while(i<pos){
		temp=temp->next;
		i++;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	free(temp);
}
void reverse(){
	struct node *current,*newnode;
	current = head;
	while(current!=0){
	nextnode = current->next;
	current->next = current->prev;
	current->prev = nextnode;
	current = nextnode;
	}	
	current = head;
	head = tail;
	tail = current;
}
void display(){
	struct node *temp;
	temp=head;
	while(temp!=last){
		printf("%d",temp->data);
		temp=temp->next;
	}
}
void main(){
	createcdll();
	insbeg();
	insend();
	inspos();
	insaftpos();
	count();
	delbeg();
	display();
	delend();
	display();
	delpos();
	display();
}
