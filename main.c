#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZESTACK 4

int top = -1; // The top of the stack, initialized for an empty stack.
char stack[SIZESTACK];

void push();
void printAll();
void printElm();
void pop();


int main()
{
    int option;
    int runProgram = 1;

    while(runProgram){
        printf("1: Add an element to the stack\n 2: Delete an element on the stack\n 3: Print out all elements on the stack\n 4: Print out a single element\n 5: Exit\n");
        scanf(" %d", &option);

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
    if(top+1 >= SIZESTACK){
        printf("Can't add another element, because the stack is full\n");
    }else{
        char inputElm;
        printf("Please add an element to the stack: \n");
        scanf(" %c",&inputElm);
        printf("Input element is: %c\n\n",inputElm);
        top++;
        stack[top] = inputElm;
    }
}

void printAll(){
    if(top>=0){
        for(int i=0; i<=top; i++){
            printf("Element %d: %c\n",i,stack[i]);
        }
    }else{
        printf("The stack is empty\n\n");
    }
}

void printElm(){
    if(top>=0){
        int index;
        printf("Which element would you like to print out? Choose from 0 to %d\n",top);
        scanf(" %d",&index);
        if(index > top){
            printf("No such element. There %s only %d element%c\n\n", (top!=0) ? "are":"is", top+1, (top!=0) ? 's':' ');
        }else{
            printf("Element %d: %c\n\n",index,stack[index]);
        }
    }else{
        printf("The stack is empty\n\n");
    }
}

void pop(){
    if(top>=0){
        top--;
        printf("The top element deleted.\n\n");
    }else{
        printf("There are no elements to remove.\n\n");
    }
}

