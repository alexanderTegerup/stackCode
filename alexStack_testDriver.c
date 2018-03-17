/*
 * alexStack_testDriver.c
 *
 *  Created on: Mar 16, 2018
 *      Author: ATESXB
 */


#include <stdio.h>
#include <stdlib.h>

#include "alexStack.c"

void test_push();
void test_printAll();
void test_printElm();
void test_pop();
void test_isFull();
void test_isEmpty();

int main(){

    test_push();
    test_pop();
    test_isFull();
    test_isEmpty();

    return 0;
}


void test_push(){

    // *** Push to the stack ***   

    // Arrange
    char inputChar,returnedChar;
    inputChar = 'a' + (rand()%26);

    //Act
    returnedChar =  push(inputChar);

    //Asert
    if(inputChar == returnedChar){
        printf("Push to stack: succeed\n");
    }else{
        printf("Push to stack: failed\n");
    }



    // *** Don't add an element to a full stack ***

    // Arrange
    inputChar = '1';
    top = SIZESTACK-1; // Making the stack full

    // Act
    returnedChar =  push(inputChar);

    // Assert
    if(inputChar == returnedChar){
        printf("Don't add an element to a full stack: failed\n");
    }else{
        printf("Don't add an element to a full stack: succeed\n");
    }

}

void test_pop(){

    // *** Pop an element from the stack ***

    // Arrange
    char elm0, elm1;
    elm0 = 'a';
    elm1 = 'b';
    stack[0] = elm0;
    stack[1] = elm1;
    top = 1; 

    // Act
    pop();

    // Assert
    if(top==0 && stack[0]==elm0){
        printf("Pop from stack: succeed\n");
    }else{
	printf("Pop from stack: failed\n");
    }


    // *** Don't pop an element from an empty stack ***
    
    // Arrange
    top = -1;

    // Act
    pop();

    // Assert
    if(top==-1){
        printf("Don't pop an element from an empty stack: succeed\n");
    }else{
        printf("Don't pop an element from an empty stack: failed\n");
    }

}

void test_isFull(){

    //Arrange
    top = SIZESTACK-1; // Making the stack full
    bool full;

    // Act
    full = isFull();

    // Assert
    if(full){
	printf("Testing the function that returns true if the stack is full: succeed\n");
    }else{
	printf("Testing the function that returns true if the stack is full: failed\n");
    }

}

void test_isEmpty(){

    //Arrange
    top = -1; // Making the stack empty
    bool empty;

    // Act
    empty = isEmpty();

    // Assert
    if(empty){
        printf("Testing the function that returns true if the stack is empty: succeed\n");
    }else{
        printf("Testing the function that returns true if the stack is empty: failed\n");
    }

}




