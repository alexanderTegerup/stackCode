#include <stdio.h>
#include <stdlib.h>
#define SIZESTACK 16

int top = -1; // The top of the stack, initialized for an empty stack.
char stack[SIZESTACK];

void push(){
    char inputElm;
    printf("Please add an element to the stack: \n");
    scanf("%c",&inputElm);
    top++;
    stack[top] = inputElm;
}

void printAll(){
    if(top>=0){
        for(int i=0; i<top; i++){
            printf("Element %d: %c\n",i,*stack);
        }
    }else{
        printf("The stack is empty\n");
    }
}

void printElm(){
    if(top>=0){
        printf("Which element would you like to print out? Choose from to %d\n",top);
    } else{
        printf("The stack is empty\n");
    }
}


int main()
{
    int option;
    int exit = 1;
    push();

    while(exit){
        printf("1: Add an element to the stack\n 2: Delete an element on the stack\n 3: Print out all elements on the stack\n 4: Print out a single element\n 5: Exit\n");
        scanf("%d", &option);

            switch(option){
                case 1 : push();
                    break;
                case 2 : printf("Test\n");
                    break;
                case 3 : printAll();
                    break;
                case 4 : printElm();
                    break;
                case 5 : exit=0;
                    break;
                default : printf("You have to enter an integer between 1-5.\n");
            }
    }


    return 0;
}
