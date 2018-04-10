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

#define SIZESTACK 6

int top = -1; // The top of the stack, initialized for an empty stack.
char stack[SIZESTACK];

void push(char);
void printAll();
char pop();
bool isFull();
bool isEmpty();

//Methods for testing
char getTopElement(); //check
void makeStackEmpty(); // check
void makeStackFull(); // check
void pushTestElem(char); // check
int countElements(); // check
int getSizeStack(); // check
void setTopElement(char); //check
bool isEmpty_test(); // check

#define LARGENUMBER 10000000 //Ten milion
//--------------------------------

#if TEST != 1
int main() {
	int option;
	int runProgram = 1;
	char inputElm;
	char cPopedVal;

	while (runProgram) {

		printf(
				" 1: Add an element to the stack\n 2: Delete an element on the stack\n 3: Print out all elements on the stack\n 4: Exit\n");
		scanf("%d", &option);
		getchar();

		switch (option) {
		case 1:
			printf("Please add an element to the stack: \n");
        		scanf("%c",&inputElm);
        		getchar();
			push(inputElm);
			break;
		case 2:
			cPopedVal = pop();
			printf("Deleted value from the stack: %c\n",cPopedVal);
			break;
		case 3:
			printAll();
			break;
		case 4:
			runProgram = 0;
			break;
		default:
			printf("You have to enter an integer between 1-4.\n");
		}
	}
	return 0;
}
#endif

void push(char inputElm) { 

	if (isFull()) {
		printf("Can't add another element, because the stack is full\n");
	} else {
		printf("You inserted the element: %c\n", inputElm);
		top++;
		stack[top] = inputElm;
	}
}

void printAll() {
	if (isEmpty()) {
		printf("The stack is empty\n\n");
	} else {
		printf("The element%s in the stack %s:\n", top > 0 ? "s" : "",
				top > 0 ? "are" : "is");
	}
	while (!isEmpty()) {
		printf("%c\n", stack[top]);
		pop();
	}
}

char pop() {

	char popedValue;
	if (top >= 0) {
		popedValue = stack[top];
		top--;
		return popedValue;
	} else {
		printf("There are no elements to remove.\n\n");
		return ' ';
	}
}

bool isFull() {
	return (top + 1 >= SIZESTACK);
}

bool isEmpty() {
	return (top == -1);
}

// *** Testing inteface ***

char getTopElement() {
	if (top != -1) {
		return stack[top];
	} else {
		printf("TD: No elements on the stack. Returning 1\n");
		return '1';
	}
}

void makeStackEmpty() { // Makes the stack empty
	top = -1;
}

void pushTestElem(char elem) {

	if (top >= SIZESTACK - 1) {
		printf("TD: Stack is full\n");
	} else {
		top++;
		stack[top] = elem;
	}
	
}

int countElements() {
	int numberElements = top + 1;
	return numberElements;
}

int getSizeStack() {
	return SIZESTACK;
}

void makeStackFull() {
	top = SIZESTACK - 1;
	return;
}

void setTopElement(char inputChar) {
	stack[top] = inputChar;
	return;
}

bool isEmpty_test() {
	return (top == -1);
}
