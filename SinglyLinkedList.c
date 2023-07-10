#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node{
	int data;
	struct node *next;
};
struct node *newnode,*temp,*head,*prevnode,*nextnode,*currentnode;
void insbeg(){
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data");
	scanf("%d",&newnode->data);
	newnode->next = head;
	head = newnode;
}
void insend(){
	newnode = (struct node*)malloc(sizeof(struct node));
	printf("Enter the data");
	scanf("%d",&newnode->data);
	newnode->next = 0;
	temp = head;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = newnode;
}
void display(){
	while(temp!=NULL){
		printf("%d",temp->data);
		temp = temp->next;
	}
}
void delbeg(){
	temp = head;
	head = head->next;
	free(temp);
}
void delend(){
	struct node*next;
	temp = head;
	while(temp->next!=NULL){
		prevnode = temp;
		temp = temp->next;
	}
	if(temp==head){
		head = 0;
	}
	else{
		prevnode->next=0;
	}
	free(temp);
}
void delpos(){
	int pos,i=1;
	temp = head;
	printf("Enter the position");
	scanf("%d",&pos);
	while(i<pos-1){
		temp = temp->next;
		i++;
	}
	nextnode = temp->next;
	temp->next = nextnode->next;
	free(nextnode);
}
void getlength(){
	int count = 0;
	temp = head;
	while(temp!=NULL){
		count++;
		temp=temp->next;
	}
	printf("%d",count);
}
void reverse(){
	prevnode = 0;
	currentnode=nextnode=head;
	while(nextnode!=0){
		nextnode = nextnode->next;
		currentnode->next = prevnode;
		prevnode = currentnode;
		currentnode = nextnode; 
	}
	head = prevnode;
}

int main(){
	int choice;
	head = 0;
	newnode = (struct node*)malloc(sizeof(struct node));
	temp = newnode;
	while(1){
		printf("Enter data");
		scanf("%d",&newnode->data);
		newnode->next=0;
		if(head==NULL){
			head=temp=newnode;
		}
		else{
			temp->next=newnode;
			temp=newnode;
		}
		printf("Do you want to continue(0,1)?");
		scanf("%d",&choice);
	}
}
