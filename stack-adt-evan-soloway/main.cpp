/*
 * COSC 2436
 * Stacks Assignment
 * Do not modify this comment
 * 
 * You may modify this file ONLY where indicated below
 */

#include "main.h"

int main() {
    /**************************************************************/
    /* DO NOT MODIFY ANYTHING BETWEEN THIS LINE AND THE ONE BELOW */
    /**************************************************************/

    //this program uses rand, this is the seed (do this only once!)
    srand(time(NULL));

    // making 5 - 25 test cases
    int number_test_cases = rand() % (TEST_CASE_BASE + 1) + TEST_CASE_OFFSET;

    //making test case parallel arrays to hold test data
    int ids[number_test_cases];
    char *data[number_test_cases];
    for (int i = 0; i < number_test_cases; i++) {
        data[i] = new char[BUFFER_SIZE];
    }

    //filling arrays with test case data
    cout << "Making " << number_test_cases << " test cases..." << endl;
    make_test_cases(ids, data, number_test_cases);
    cout << "Test cases done" << endl << endl;
    display_test_cases(ids, data, number_test_cases);

    /**************************************************************/
    /* MODIFY THE FILE FROM HERE DOWN */
    /**************************************************************/

    /*
     * At this point you have two parallel arrays. A simple integer array (ids)
     * that holds random integers, and 2D character array (which is a 
     * 1D array of strings) holding 'dummy' strings. Compile and run the
     * program as-is and you will see the display of these two arrays.
     */
    
    // declare the stack
    Stack stack;
    
    /*****************************************
     * Perform your stack tests starting here
     *****************************************/
    
    /* first call isEmpty(), peek(), and pop() to show what happens when
     * you do that on an empty stack */

        cout << "\nEMPTY STACK:" << endl;
        
        Data object;

        cout << "isEmpty(): " << stack.isEmpty() << endl;
        cout << "peek(): " << stack.peek(&object) << endl;

        cout << "id Return of dummyPntr before allocation (should be compiler garbage): " << object.id << endl;
        cout << "data Return of dummyPntr before allocation (should be compiler garbage): " << object.data << endl;

        cout << "id Return after peek(): " << object.id << endl;
        cout << "data Return after peek(): " << object.data << endl;

        cout << "id Return after deletion following pop(): " << object.id << endl;
        cout << "data Return after deletion following pop(): " << object.data << endl;
        
        cout << "pop(): " << stack.pop(&object) << endl;

        cout << "id Return after pop(): " << object.id << endl;
        cout << "data Return after pop(): " << object.data << endl;

    /*
     * Now perform an exhaustive series of tests on your stack. Push all the
     * cases. Pop all the cases. Randomly push and pop cases. Test peek() and
     * isEmpty() randomly and throughout the other cases. Your tests must be
     * exhaustive! Show all possible ways your stack can be used and abused,
     * and that your stack will gracefully handle ALL cases. You must use
     * automated testing (no user input). Make sure you run your program
     * many times to see what happens when the test cases are bigger, smaller,
     * or the same size as the size of your stack.
     */

     // PUSHING TO STACK //

        cout << "\nPUSHING TO INDEX 0 ON STACK:" << endl;

        cout << "push(): " << stack.push(100, "erwer") << endl;

        cout << "peek(): " << stack.peek(&object) << endl;
        cout << "id Return after peek(): " << object.id << endl;
        cout << "data Return after peek(): " << object.data << endl;

        cout << "isEmpty(): " << stack.isEmpty() << endl;

        cout << "pop(): " << stack.pop(&object) << endl;

        cout << "id Return after pop(): " << object.id << endl;
        cout << "data Return after pop(): " << object.data << endl;

        cout << "isEmpty() after popping: " << stack.isEmpty() << "\n\n";

        cout << "\nPUSHING BAD DATA TO STACK:" << endl;
        cout << "Adding -1... ";
        if(stack.push(-1, "Jam")){
                cout << "success!";
                }

        else{
                cout << "failure.";
                }

        cout << "\n\n";

        // Loops //

        int index;
        int testCase;
        cout << "LOOPS:" << endl;

        cout << "\nFilling Stack:" << endl;

        for(index=0;index<STACK_SIZE;index++){ // fills stack

            testCase = rand() % number_test_cases;

        try{

            cout << "INDEX: " << index << endl;
            cout << "isEmpty(): " << stack.isEmpty() << endl;

            cout << "ID passed to stack: " << ids[testCase] << endl;
            cout << "data passed to stack: " << data[testCase] << endl;
            cout << "push(): " << stack.push(ids[testCase], data[testCase]) << endl;

            cout << "peek(): " << stack.peek(&object) << endl;
            cout << "id Return after peek(): " << object.id << endl;
            cout << "data Return after peek(): " << object.data << endl;

            }

        catch(int){
            cout << "ERROR WAS THROWN" << endl;
            }

        cout << "\n";

} 

cout << endl;

        cout << "\nEmptying Stack:" << endl;

        for(index=9;index>=0;index--){ // empties stack

            try{

                cout << "INDEX: " << index << endl;
                
                cout << "pop(): " << stack.pop(&object) << endl;
                cout << "id Return after pop(): " << object.id << endl;
                cout << "data Return after pop(): " << object.data << endl;

                cout << "peek(): " << stack.peek(&object) << endl;
                cout << "id Return after peek(): " << object.id << endl;
                cout << "data Return after peek(): " << object.data << endl;

                cout << "isEmpty(): " << stack.isEmpty() << endl;

                }

            catch(int){
                cout << "ERROR WAS THROWN" << endl;
                }

            cout << "\n";

            } 

            cout << endl;

            cout << "\nFilling past size (overflow):" << endl;

       for(index=0;index<15;index++){ // fills stack then tests overflow (should crash after index 9)

            if(index==10){
                cout << "\nINDEX IS NOW OUT OF RANGE:" << endl;
                }
            
            try{        

                testCase = rand() % number_test_cases;

                cout << "ID passed to stack at index [" << index << "]: " << ids[testCase] << endl;
                cout << "data passed to stack at index [" << testCase << "]: " << data[testCase] << endl;
                cout << "push(): " << stack.push(ids[testCase], data[testCase]) << endl;
                cout << "peek(): " << stack.peek(&object) << endl;
                cout << "id Return after peek(): " << object.id << endl;
                cout << "data Return after peek(): " << object.data << endl;
                cout << endl;

                }

            catch(int){
                cout << "ERROR WAS THROWN" << endl;
                }

            cout << "\n";

            }

    return 0;
}
