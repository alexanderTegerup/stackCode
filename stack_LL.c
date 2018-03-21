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



void push(char);
void pop();
void printAll();

bool isEmpty();
bool oneElementLeft();
int quit();

struct node{
    char element;
    struct node* pNodeBelow;
};

struct node* top = NULL;

//Methods for testing
char getTopElement();
void makeStackEmpty();
void makeStackFull();
void addTestElements(char,int);
int countElements();
int getSizeStack();
void insertElement(char,int);
// --------------------

/*
int main(){

    int option;
    int runProgram = 1;

    while(runProgram){

        printf(" 1: Add an element to the stack\n 2: Delete an element on the stack\n 3: Print out all elements on the stack\n 4: Exit\n");
        scanf("%d",&option);
        getchar();

            switch(option){
                case 1 : push();
                    break;
                case 2 : pop();
                    break;
                case 3 : printAll();
                    break;
                case 4 : runProgram = quit();
                    break;
                default : printf("You have to enter an integer between 1-5.\n");
            }
    }
    return 0;
}
*/

void push(char testInput){ // Added argumnet for testing purposes

    char elm;
    elm = testInput; // Added for testing 
//    printf("Enter element on the stack: \n");
 //   scanf("%c",&elm);
  //  getchar();

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


void printAll(){

    if(isEmpty()){
	printf("Stack is empty. Hence, nothing can be printed out.\n");
    }else{
        while(!isEmpty()){
            printf("Top element: %c\n",top->element);
	    pop();
	}
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


// *** Testing inteface ***

char getTopElement(){ // Returns the element at the top of the stack 
    return top->element;
}

void makeStackEmpty(){ 
    struct node* tmp;
    while( top != NULL ){ 
        tmp = top;
        top = top->pNodeBelow;
        free(tmp);
    }
}

void addTestElements(char inputChar,int numNodes){

    for(int i=0; i<numNodes; i++){

        if(top == NULL){
            top = (struct node*) malloc( sizeof(struct node) );
	    top->element = 'a' + (rand()%26);
            top->pNodeBelow = NULL;
        }else{
	    // Creating a new node at each iteration:
	    struct node* newNode = (struct node*) malloc( sizeof(struct node) );
            newNode->element = 'a' + (rand()%26);
	    // Making the new node referencing to the node below in the stack, which is top:
            newNode->pNodeBelow = top; 

	    top = newNode; // Updating top
        }
    }
    top->element = inputChar;

}

int countElements(){ // Returns the number of elements on the stack.
    int numberElements = 0;
    struct node* tmp;
    while( top != NULL ){  
	tmp = top;
	top = top->pNodeBelow;
        free(tmp);
	numberElements++;
    }
    return numberElements;
}

int getSizeStack(){
    return LARGENUMBER;
}

void makeStackFull(){
    return;
}

void insertElement(char inputChar,int index){
    if(top!=NULL){
        top->element = inputChar;
    }
    return;
}


