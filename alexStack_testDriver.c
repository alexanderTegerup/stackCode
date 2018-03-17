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
    test_printAll();
    test_printElm();

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

void test_printAll(){

    printf("Testing the printAll function ...\n");

    // *** Printing out two elements ***

    //Arrange
    char elm0, elm1;
    elm0 = 'a';
    elm1 = 'b';
    stack[0] = elm0;
    stack[1] = elm1;
    top = 1;

    //Act
    printAll();

    //Assert
    printf("'printAll' works if '%c' and '%c' is printed out above this text\n",elm1,elm0);


    // *** Printing out an empty stack ***

    //Arrange
    top = -1;

    //Act
    printAll();

    //Assert
    printf("'printAll' works if a message saying that the stack is empty is printed out above.\n");

}


void test_printElm(){

    printf("Testing the printElm function ...\n");

    // *** Printing out element two out of three elements ***

    //Arrange
    char elm0, elm1, elm2;
    elm0 = 'a';
    elm1 = 'b';
    elm2 = 'c';

    int testIndex=1;
    stack[0] = elm0;
    stack[1] = elm1;
    stack[2] = elm2;
    top = 2;

    //Act
    printElm(testIndex);

    //Assert
    if(top == testIndex){
        printf("'printElm' works if '%c' is printed out above this text\n",elm1);
    }else{ printf("Error in printElm\n"); }


    // *** If the user enters an index greater than the top of the stack ***

    //Arrange
    top = 2;
    testIndex = top+1;

    //Act
    printElm(testIndex);

    //Assert
    printf("'printElm' works if an error message is given above.\n");


    // *** If the user enters an index less than zero ***

    //Arrange
    top = 2;
    testIndex = -1;

    //Act
    printElm(testIndex);

    //Assert
    printf("'printElm' works if an error message is given above.\n");

    
    // *** If the stack is empty ***

    //Arrange
    top = -1;
    testIndex = 1;

    //Act
    printElm(testIndex);

    //Assert
    printf("'printElm' works if a message saying that the stack is empty is given above.\n");


}






