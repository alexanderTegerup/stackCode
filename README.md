# stackCode

TODO:

    - Fix bug in getTopElement(), if the stack is empty. 

    - Make test case where I push to a stack that already contains a few elements.

    - Verify that all of my test functions work as they should. 

// *** Tests I wrote for the testing functions themsefs ***

    addTestElements('a',1);
    addTestElements('b',7);
    addTestElements('c',1);
    setTopElement('Q');

    printf("Top elm: %c\n",getTopElement());
    printf("Number of elements: %d\n",countElements());
    printAll();
    makeStackEmpty();
    printAll();

    addTestElements('a',2);
    printf("Top elm: %c\n",getTopElement());
    printf("Number of elements: %d\n",countElements());

    printAll();

    makeStackFull();
    printf("Number of elements: %d\n",countElements());

    printf("Size stack: %d\n",getSizeStack());


    if( isEmpty_test() ){
        printf("True\n");
    }else{
        printf("False\n");
    }

    makeStackEmpty();
    if( isEmpty_test() ){
        printf("True\n");
    }else{
        printf("False\n");
    }

    printf("Test of test functions ends here!\n\n\n");

    test_push();
    test_pop();

