/*
 * alexStack_testDriver.c
 *
 *  Created on: Mar 16, 2018
 *      Author: ATESXBi

 Function addTestElements(topElement, numberOfElements) adds an arbitrary number of elements to the stack.
 The first argument will be the character at the top of the stack and the second argument states how many
 elements should be added to the stack. All elements added by this method are generated randomly, exept for 
 the top element. 

*/


#include <stdio.h>
#include <stdlib.h>

//#include "alexStack.c"
#include "stack_LL.c"

void test_push();
void test_pop();


int main(){

    test_push();
    test_pop();

    return 0;
}



void test_push(){

    // *** Push to the stack ***   

    // Arrange

    makeStackEmpty();
    char inputChar;
    inputChar = 'a' + (rand()%26); //Inserting a random character from a-z. 

    //Act
    push(inputChar); //Push to the top of the stack.

    //Asert

    if( inputChar == getTop() ){
        printf("Push to stack: succeed\n");
    }else{
        printf("Push to stack: failed\n");
    }

    // Add to a full stack

}


void test_pop(){

    // *** Pop an element from a stack with two elements ***

    // Arrange
    makeStackEmpty();
    char inputChar;
    inputChar = 'a' + (rand()%26); //Inserting a random character from a-z.
    addTestElements(inputChar,1);
    addTestElements('a' + (rand()%26), 1);

    // Act
    pop();
    
    // Assert
    if(getTop() == inputChar){
        printf("Pop from stack: succeed\n");
    }else{
	printf("Pop from stack: failed\n");
    }

    // *** Pop an element from a stack with four elements ***

    // Arrange

    // --- Making 'inputChar' the element just below the top element on the stack ---
    addTestElements(inputChar,3); 
    addTestElements('a'+(rand()%26), 1);

    //Act
    pop();

    // Assert
    if(getTop() == inputChar){
        printf("Pop from stack: succeed\n");
    }else{
        printf("Pop from stack: failed\n");
    }

    // *** Don't pop an element from an empty stack ***    
    // Arrange
    makeStackEmpty();

    // Act
    pop();

    // Assert
    if( countElements() == 0 ){
        printf("Don't pop an element from an empty stack: succeed\n");
    }else{
        printf("Don't pop an element from an empty stack: failed\n");
    }


}







