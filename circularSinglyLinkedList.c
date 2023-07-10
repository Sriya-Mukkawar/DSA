#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *head,*newnode,*temp,*nextnode;
void createcll(){
	int choice;
	head = 0;
	newnode = (struct node*)malloc(sizeof(struct node));
	temp = newnode;
	while(choice){
		printf("Enter data");
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(head==NULL){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			temp->next=head;
		}
		printf("Do you want to continue(0,1)?");
		scanf("%d",&choice);
	}
}
void insbeg(){
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data");
	scanf("%d",&newnode->data);
	newnode->next=head;
	head=newnode;
}
void insend(){
	struct node *last,*temp;
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data");
	scanf("%d",&newnode->data);
	newnode->next=head;
	temp=head;
	while(temp->next!=0){
		temp=temp->next;
	}
	last = temp;
	last->next=newnode;
}
void delbeg(){
	struct node *temp,*last;
	temp=head;
	while(temp->next!=0){
		temp=temp->next;
	}
	last = temp;
	head=head->next;
	free(temp);
}
void delend(){
	struct node *temp,*last,*prev;
	temp =head;
	while(temp->next!=0){
		prev = temp;
		temp=temp->next;
	}
	prev->next=head;
	free(temp);
}
void delpos(){
	struct node *temp,*last,*prev;
	int pos,i=1;
	printf("Enter the position");
	scanf("%d",&pos);
	temp=head;
	while(i<pos-1){
		temp = temp->next;
		i++;
	}
	nextnode=temp->next;
	temp->next=nextode->next;
	free(nextnode);
}
void length(){
	int count = 0;
	temp = head;
	while(temp!=last){
		count++;
		temp=temp->next;
	}
	printf("%d",count);
}
void display(){
	temp=head;
	while(temp!=last){
		printf("%d",temp->data);
		temp=temp->next;
	}
}
//void reverse(){
//	struct node *temp,*last,*prev,*current,*nextnode;
//	prev = 0;
//	current =  nextnode = head;
//	while(nextnode!=0){
//		nextnode = nextnode->next;
//		current->next=prev;
//		prev = current;
//		current = next;
//	}
//}
void main(){
	createcll();
	insbeg();
}
