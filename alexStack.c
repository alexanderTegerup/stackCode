/*
 * alexStack.c
 *
 *  Created on: Mar 15, 2018
 *      Author: ATESXB
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define SIZESTACK 4

int top = -1; // The top of the stack, initialized for an empty stack.
char stack[SIZESTACK];

void push();
void printAll();
void printElm();
void pop();
bool isFull();
bool isEmpty();


int main()
{
    int option;
    int runProgram = 1;

    //printf(" 1: Add an element to the stack\n 2: Delete an element on the stack\n 3: Print out all elements on the stack\n 4: Print out a single element\n 5: Exit\n");
    //scanf("%d\n",&option);
    //fgets(option,1,stdin);
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
                case 4 : printElm();
                    break;
                case 5 : runProgram=0;
                    break;
                default : printf("You have to enter an integer between 1-5.\n");
            }
    }
    return 0;
}


void push(){

    if(isFull()){
        printf("Can't add another element, because the stack is full\n");
    }else{
        char inputElm;
        printf("Please add an element to the stack: \n");
        scanf("%c",&inputElm);
        getchar();
        printf("You inserted the element: %c\n\n",inputElm);
        top++;
        stack[top] = inputElm;
    }
}


void printAll(){
	if(isEmpty()){
	        printf("The stack is empty\n\n");
	    }
	while(!isEmpty()){
		printf("Element: %c\n",stack[top]);
		pop();
	}
}


void printElm(){

    if(!isEmpty()){
        int index;
        printf("Choose the index of the element would you like to print out? Choose an index between 0 to %d:\n",top);
        scanf("%d",&index);
        getchar();
        if(index > top || index < 0){
            printf("Index is out of bounds. You must choose an index from 0 to %d.\n\n",top);
        }else{
	    while(top!=index){
	        pop();
	    }
	    printf("Element %d: %c\n\n",index,stack[index]);
	}
    }else{
        printf("The stack is empty\n\n");
    }
}


void pop(){

    if(top>=0){
        top--;
    }else{
        printf("There are no elements to remove.\n\n");
    }
}

bool isFull(){
    return (top+1 >= SIZESTACK);
}

bool isEmpty(){
    return (top<0);
}



