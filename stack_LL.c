/*
 * stack_LL.c
 *
 *  Created on: Mar 19, 2018
 *      Author: ATESXB
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>



void push();
void pop();
void printElement();
void printAll();

bool isEmpty();
bool oneElementLeft();
int quit();

struct node{
    char element;
    struct node* pNodeBelow;
};

struct node* top = NULL;

int main(){

    int option;
    int runProgram = 1;

    while(runProgram){

        printf(" 1: Add an element to the stack\n 2: Delete an element on the stack\n 3: Print out all elements on the stack\n 4: Print out a single element\n 5: Exit\n");
        scanf("%d",&option);
        getchar();

            switch(option){
                case 1 : push();
                    break;
                case 2 : pop();
                    break;
                case 3 : printAll();
                    break;
                case 4 : printElement();
                    break;
                case 5 : runProgram = quit();
                    break;
                default : printf("You have to enter an integer between 1-5.\n");
            }
    }

    return 0;
}

void push(){

    char elm;
    printf("Enter element on the stack: \n");
    scanf("%c",&elm);
    getchar();

    if(isEmpty()){
	top = (struct node*) malloc( sizeof(struct node) );
	top->element = elm;
        top->pNodeBelow = NULL;
    }else{
	struct node* pTopNode;
	pTopNode = (struct node*) malloc( sizeof(struct node) );

	pTopNode->element = elm;
	pTopNode->pNodeBelow = top;
	top = pTopNode;
    }

}

void pop(){

    if(isEmpty()){
	printf("Nothing to pop. The stack is empty.\n");
    }
    else if(oneElementLeft()){
	free(top);
	top=NULL;
    }
    else{
	struct node* tmp = top;
	top = tmp->pNodeBelow;
	free(tmp);
    }

}

void printElement(){

}

void printAll(){

    if(isEmpty()){
	printf("Stack is empty. Hence, nothing can be printed out.\n");
    }else{
        printf("Top element: %c\n",top->element);
    }
}

bool isEmpty(){
    return (top == NULL);
}

bool oneElementLeft(){
    return (top->pNodeBelow == NULL);
}

int quit(){
    free(top);
    return 0;
}

