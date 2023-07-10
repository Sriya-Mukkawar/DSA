/* Balance Parenthesis
Given an infix notation, check whether the input infix notation comprises of balanced parenthesis or not using stack. If the input expression contains balanced parenthesis, print "Balanced" else print "Unbalanced". write an algorithm and implement the same using C program.

Example:

Input: {(a+b)-[c/d]*e} 

Output: Balanced

Input Format:

Read infix string

Output Format:

Balanced or Unbalanced */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10000

struct stack {
    int top;
    char items[MAX];
}s;

void push(struct stack* s, char c){
    if(s->top == MAX-1){
        printf("Stack Overflow");
        return;
    }
    s->top++;
    s->items[s->top] = c;
}

char pop(struct stack* s){
    if(s->top == -1){
        printf("Stack Underflow");
        return -1;
    }
    char c = s->items[s->top];
    s->top--;
    return c;
}

int isOpening(char c){
	if(c == '(' || c == '{' || c == '[')
		return 1;
	return 0;
}

int isClosing(char c){
	if(c == ')' || c == '}' || c == ']')
		return 1;
	return 0;
}

int isMatching(char c1, char c2){
	if(c1 == '(' && c2 == ')')
		return 1;
	if(c1 == '{' && c2 == '}')
		return 1;
	if(c1 == '[' && c2 == ']')
		return 1;
	return 0;
}

int checkBalanced(char* str){
	s.top = -1;
	for(int i=0; i<strlen(str); i++){
		if(isOpening(str[i])){
			push(&s, str[i]);
		}
		else if(isClosing(str[i])){
			if(s.top == -1){
				return 0;
			}
			char c = pop(&s);
			if(!isMatching(c, str[i])){
				return 0;
			}
		}
	}
	if(s.top == -1){
		return 1;
	}
	return 0;
}

int main(){
	char str[MAX];
	scanf("%s", str);
	if(checkBalanced(str)){
		printf("Balanced");
	}
	else{
		printf("Unbalanced");
	}
	return 0;
}
