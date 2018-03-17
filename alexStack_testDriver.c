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







