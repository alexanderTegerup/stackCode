/*
 * alexQueue.c
 *
 *  Created on: Mar 17, 2018
 *      Author: ATESXB

In this queue data structure, an element is entering the queue at the tail and exit at the head.


 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

void enqueue();
void dequeue();
void peek();
bool isEmpty();


int main(){

    int option;
    int runProgram = 1;

    while(runProgram){

        printf(" 1: Enqueue\n 2: Dequeue\n 3: Peek\n 4: Exit\n");
        scanf("%d",&option);
        getchar();

            switch(option){
                case 1 : enqueue();
                    break;
                case 2 : dequeue();
                    break;
                case 3 : peek();
                    break;
                case 4 : runProgram=0;
                    break;
                default : printf("You have to enter an integer between 1-4.\n");
            }
    }
    return 0;

}


void enqueue(){ // Enqueue element at the tail

}

void dequeue(){ // Dequeue element at the head

}

void peek(){

}










