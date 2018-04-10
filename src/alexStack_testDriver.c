/*
 * alexStack_testDriver.c
 *
 *  Created on: Mar 16, 2018
 *      Author: ATESXBi

 Function addTestElements(numberOfElements) adds an arbitrary number of elements to the stack.
 All elements added by this method are generated randomly. The elements are added above previously added elements. 

*/


#include <stdio.h>
#include <stdlib.h>

#define LARGENUMBER 10000000 //Ten milion

#include "alexStack.c"
//#include "stack_LL.c"


void test_push();
void test_pop();


int main(){


    test_push();
    test_pop();

    return 0;
}



void test_push(){

    // *** Push to an empty stack ***   
    // Arrange
    makeStackEmpty();
    char inputChar;
    inputChar = 'a' + (rand()%26); //Inserting a random character from a-z. 

    //Act
    push(inputChar); //Push to the top of the stack.

    //Asert
    if( inputChar == getTopElement() ){
        printf("TD: Push to an empty stack: succeed\n");
    }else{
        printf("TD: Push to an empty stack: failed\n");
    }


    // *** Push to a stack with three elements already ***

    //Arrange
    makeStackEmpty();
    int numberElem = 3;
    for(int i=0; i<numberElem; i++){
	inputChar = (char) (i+'a');
        pushTestElem(inputChar);
    }

    // Act
    inputChar = (char) (numberElem + 'a');
    push(inputChar);

    // Assert
    if( inputChar == getTopElement() ){
        printf("TD: Push to stack with three elements already: succeed\n");
    }else{
        printf("TD: Push to stack with three elements already: failed\n");
    }


    // *** Don't add to a full stack ***
    // Arrange
    int sizeStack = getSizeStack();
    char topElement = 'T';
    inputChar = 'i';
    makeStackFull();
    setTopElement(topElement); //Adding a known element to the top of the stack

    // Act
    push(inputChar);

    // Assert
    if(sizeStack >= LARGENUMBER){
	printf("TD: Don't add to a full stack: (practically) no memory limitation with this implementation of the stack\n\n");
    }
    else if( countElements() == sizeStack && getTopElement() != inputChar ){
	printf("TD: Don't add to a full stack: succeed\n\n");
    }else{
	printf("TD: Don't add to a full stack: failed\n\n");
    }

}


void test_pop(){

    // *** Pop an element from a stack with one element ***

    // Arrange
    makeStackEmpty();
    char inputChar, popedChar;
    int numberElm;
    inputChar = 'a' + (rand()%26); //Inserting a random character from a-z.
    pushTestElem(inputChar);

    // Act
    pop();

    // Assert
    if(isEmpty_test()){
        printf("TD: Pop from a stack with one element: succeed\n");
    }else{
        printf("TD: Pop from a stack with one element: failed\n");
    }

    // *** Pop an element from a stack with two elements ***

    // Arrange
    numberElm = 2;
    makeStackEmpty();
    for(int i=0; i<numberElm; i++){
	inputChar = (char) (i+'a');
	pushTestElem(inputChar);
    }
    inputChar = (char) ('a' + numberElm); 
    pushTestElem(inputChar);

    // Act
    popedChar = pop();
    
    // Assert
    if(popedChar == inputChar){
        printf("TD: Pop from a stack with two elements: succeed\n");
    }else{
	printf("TD: Pop from a stack with two elements: failed\n");
    }


    // *** Pop an element from a stack with four elements ***

    // Arrange
    numberElm = 4;
    makeStackEmpty();
    for(int i=0; i<numberElm; i++){
        inputChar = (char) (i+'a');
        pushTestElem(inputChar);
    }
    inputChar = (char) ('a' + numberElm);
    pushTestElem(inputChar);

    // Act
    popedChar = pop();

    // Assert
    if(popedChar == inputChar){
        printf("TD: Pop from a stack with four elements: succeed\n");
    }else{
        printf("TD: Pop from a stack with four elements: failed\n");
    }



    // *** Don't pop an element from an empty stack ***    

    // Arrange
    makeStackEmpty();

    // Act
    pop();

    // Assert
    if( countElements() == 0 ){
        printf("TD: Don't pop an element from an empty stack: succeed\n");
    }else{
        printf("TD: Don't pop an element from an empty stack: failed\n");
    }
}







