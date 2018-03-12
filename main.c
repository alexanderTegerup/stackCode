#include <stdio.h>
#include <stdlib.h>

#define SIZESTACK 16

void push(){
    printf("from push");
}


int main()
{
    int option;
    int exit = 1;
    while(exit){
        printf("1: Add an element to the stack\n 2: Delete an element on the stack\n 3: Print out all elements on the stack\n 4: Print out a single element\n 5: Exit\n");
        scanf("%d", &option);

            switch(option){
                case 1 : push();
                    break;
                case 2 : printf("Test\n");
                    break;
                case 3 : printf("Test\n");
                    break;
                case 4 : printf("Test\n");
                    break;
                case 5 : exit=0;
                    break;
                default : printf("You have to enter an integer between 1-5.\n");
            }
    }


    return 0;
}
