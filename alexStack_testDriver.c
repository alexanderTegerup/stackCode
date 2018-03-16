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


int main(){

    test_push();

    return 0;
}


void test_push(){

    // *** Add an element to the stack ***   
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

    // *** Don't add an element if the stack is full ***
    // Arrange
    inputChar = 'a';
    top = SIZESTACK-1;
    returnedChar = 'b';

    // Act
    returnedChar =  push(inputChar);

    // Assert
    if(inputChar != returnedChar){
        printf("Check if stack is full: succeed\n");
    }else{
        printf("Check if stack is full: failed\n");
    }

}







