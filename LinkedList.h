/*
LinkedList.h - Srikar Chava 1/21/2022

The code in this file serves as definitions of the functions and data types that need to be implemented within the
program. It inlcudes a struct called "Node" as well as data types such as head_ and tail_. It also includes several functions that
serve to manipulate Linked Lists such as addNodeHead and deleteNodeHead for reference.
*/
#pragma once
#include <iostream>
using namespace std;

struct Node {
    Node* next;
    Node* prev;
    int value;
};

class LinkedList {
public:
    //constructor
    LinkedList();

    //getters for list head and tail
    Node* getHead() const;
    Node* getTail() const;

    //list head and tail functions
    void addNodeHead(int val); 
    void addNodeTail(int val);  
    void deleteNodeHead();    
    void deleteNodeTail();  

    //flag getters and setters
    char getFlag() const;
    void setFlag(char f); //noticed that list needed flags, did not address this in design.

    //additional list functions
    int getNumDigits() const;
    bool isEmpty() const;
    void printAll();  
    void removeExtraZeros();

private:

    //node head, tail and flag
    Node* head_;
    Node* tail_;
    char flag_;
    int digits_;
};