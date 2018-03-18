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

// Each node contains an element and a pointer to the node behind in the queue (pNextNode)
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

    if(isEmpty()){
        head = pNewNode;
        tail = pNewNode;
    }else{
        tail->pNextNode = pNewNode;
        tail = pNewNode;
    }
}

void dequeue(){ // Dequeue element at the head
    struct node* tmp = head->pNextNode; // tmp points to the second node in the queue
    free(head); // Free memory from the first node.
    head = tmp; // Now the second node has become the first node.
}

// Prints the value of the front element, without dequeuing it.
void peek(){
    printf("The first element in the queue is: %c\n",head->element);
}

int quit(){
    free(head);
    free(tail);
    return 0;
}

bool isEmpty(){
    return (head == NULL && tail==NULL);
}



