#include <stdio.h>
#include <stdlib.h>
#define SIZESTACK 16

int top = -1; // The top of the stack, initialized for an empty stack.
char stack[SIZESTACK];

void push(){
    if(top+1 >= SIZESTACK){
        printf("Can't add another element, because the stack is full\n");
    }else{
        char inputElm;
        printf("Please add an element to the stack: \n\n");
        scanf("%c",&inputElm);
        printf("Input element is: %c\n",inputElm);
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
        printf("The stack is empty\n");
    }
}

void printElm(){
    if(top>=0){
        int elm;
        printf("Which element would you like to print out? Choose from 0 to %d\n",top);
        scanf("%d",&elm);
        if(elm)
        printf("Element %d: %c",elm,stack[elm]);
    } else{
        printf("The stack is empty\n");
    }
}

void pop(){
    if(top>=0){
        top--;
    }else{
        printf("There are no elements to remove.\n");
    }
}

int main()
{
    int option;
    int runProgram = 1;

    while(runProgram){
        printf("1: Add an element to the stack\n 2: Delete an element on the stack\n 3: Print out all elements on the stack\n 4: Print out a single element\n 5: Exit\n");
        scanf("%d", &option);

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
