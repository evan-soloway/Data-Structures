/*********************
Name: Evan Soloway
Assignment: Hash Tables
File: main.cpp
Purpose: Tests Hashtable class.
**********************/

#include "main.h"

int main() {
    //seed the rand function
    srand(time(NULL));

    /*
     * This code makes test data of 6 - 25 entries
     * Note this guarantees at least one non unique id and one bad id
     * Do not modify this code from here to the next comment telling
     * you to "START HERE"
     */
    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    /*
     * Show test data
     */
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    /*
     * Now you have two parallel arrays with ids and strings for test data.
     * START HERE and create your hash table and use the test data to show
     * it works.
     */

    int tmpId;
    int IdArray [50];
    string tmpData;
    int count=0;
    int numDeletions=0;

    Hashtable NEWhashtable;

    cout << "Hashtable oject is empty:" << "\n\n";

    cout << "getCount() return value: " << NEWhashtable.getCount() << endl;
    cout << "printing table:" << endl;
    NEWhashtable.printTable();
    cout << endl;
    cout << "removeEntry() return value (id of 20 passed to method): " << NEWhashtable.removeEntry(20) << endl;
    cout << "getData(20) return value: " << NEWhashtable.getData(20) << endl;

    cout << "\n";

    int numNodes = 5 + (rand() % 20);

    cout << "Creating hashtable: " << endl;

    for(int i=0;i<testdatasize;i++){
        IdArray[i]=tmpId;
        tmpId=ids[i];
        tmpData=strs[i];
        cout << "Adding... " << tmpId << ", " << tmpData << " at index " << tmpId%HASH_TABLE_SIZE << "... ";

        if(NEWhashtable.insertEntry(tmpId,tmpData)){
            cout << "Success!"; count++;
            } 

        else{
            cout << "failed!";
            }

        cout << endl;
        }

    cout << "\n";
    cout << "Num elements in table according to main(): " << count << endl;
    cout << "Num elements in table according to hashtable.getCount(): " << NEWhashtable.getCount() << endl;

    cout << "\n" << "getting data from random IDs:" << endl;
    for(int i=0;i<10;i++){
        tmpId=rand()%100;
        cout << "Getting data at ID... " << tmpId << "... " << NEWhashtable.getData(tmpId);
        cout << endl;
        }

    cout << "\n" << "getting data from random IDs in list of initial table entries:" << endl;
    for(int i=0;i<10;i++){
        tmpId=IdArray[rand()%testdatasize];
        cout << "Getting data at ID... " << tmpId << "... " << NEWhashtable.getData(tmpId);
        cout << endl;
        }

    cout << "\n";
    cout << "Printing table with printTable() method: (NOTE: error has occurred if node's place in table != (ID % table size)+1)" << endl;
    NEWhashtable.printTable();

    cout << "\n" << "removing entries from random IDs:" << endl;
    for(int i=0;i<10;i++){
        tmpId=rand()%100;
        cout << "Data at ID " << tmpId << ": " << NEWhashtable.getData(tmpId) << endl;
        cout << "Removing entry at ID... " << tmpId << "... ";

        if(NEWhashtable.removeEntry(tmpId)){
            cout << "Success!"; 
            numDeletions++;
            }

        else{
            cout << "failure!";
            }

        cout << endl;
        }

    cout << "\n" << "removing entries from random IDs in list of initial table entries:" << endl;

    for(int i=0;i<5;i++){

        try{
            tmpId=IdArray[rand()%count];
            cout << "Data at ID " << tmpId << ": " << NEWhashtable.getData(tmpId) << endl;
            cout << "Removing entry at ID... " << tmpId << "... ";

            if(NEWhashtable.removeEntry(tmpId)){
                cout << "Success!"; 
                numDeletions++;
                }

            else{
                cout << "failure!";
                }
            }
        
        catch(int){
            cout << "ERROR";
            }

        cout << endl;
        }


    cout << "\n" << "Printing list after deletions:" << endl;
    NEWhashtable.printTable();

    cout << "\nNumber of Deletions: " << numDeletions << endl;
    cout << "getCount(): " << NEWhashtable.getCount() << "\n";

    cout << "\nAdding bad data: " << endl;
    cout << "Adding -1 and \"\"... ";
    if(NEWhashtable.insertEntry(-1,"")){
        cout << "success!";
        } 

    else{
        cout << "failure!";
        }

    cout << endl;

    cout << "getCount(): " << NEWhashtable.getCount() << endl; 

    return 0;
    }
