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
int quit();

// Each node contains an element and a pointer to the node behind in the queue
struct node{
    char element;
    struct node* pNextNode;
};


struct node *head = NULL;
struct node *tail = NULL;
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
                case 4 : runProgram=quit();
                    break;
                default : printf("You have to enter an integer between 1-4.\n");
            }
    }

    return 0;

}


void enqueue(){ // Enqueue element at the tail
    struct node* pNewNode;
    char inputElm;
    pNewNode = (struct node*) malloc( sizeof(struct node) );

    printf("Enter element to enqueue: \n");
    scanf("%c",&inputElm);
    getchar();

    pNewNode->element = inputElm;
    printf("Input: %c\n",inputElm);

    if(head == NULL && tail==NULL){
        head = pNewNode;
        tail = pNewNode;
        return;
    }
}

void dequeue(){ // Dequeue element at the head

}

void peek(){

}

int quit(){
    free(head);
    free(tail);
    return 0;
}





