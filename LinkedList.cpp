/*
LinkedList.cpp - Srikar Chava 1/21/2022

The code in this file serves as implementations of the functions that were defined in LinkedList.h
This file serves as the main LinkedList file and will create a doubly Linked List to store the InfiniteInt types.
*/
#include <iostream>
#include "LinkedList.h"
using namespace std;

// constuctor
LinkedList::LinkedList()    
{
    head_ = nullptr;
    tail_ = nullptr;
    digits_ = 0;
    flag_ = '+';
}

// getter for the head
Node*LinkedList::getHead() const   
{
    return head_;
}

// getter for the tail
Node* LinkedList::getTail() const 
{
    return tail_;
}

// add to the head of the list
void LinkedList::addNodeHead(int val)   // add to the head of the list
{
    Node* temp = new Node;
    temp->value = val;
    temp->prev = nullptr;
    
    if (isEmpty() == 1) {  // if the list is empty, add node to the head
        head_ = new Node();
        tail_= new Node();
        
        temp->next = nullptr;
        temp->prev = nullptr;
        tail_= temp;
        
        head_= tail_;   
    }
    else {  // if list is not empty 
        temp->next = head_;
        head_->prev = temp;
        head_=temp;
        head_->prev = nullptr;
    }
    digits_++;
}

// adding to the tail of the list
void LinkedList::addNodeTail(int val)
{
    if (isEmpty() == 1) { 
        
        // if it is empty, make new head and tail and add the node
        head_ = new Node();
        tail_ = new Node();

        tail_->value = val;
        tail_->next = nullptr;
        tail_->prev = nullptr;
        head_ = tail_;
    }
    else { 
        
        // if list is not empty, add to the tail of the list
        Node* extra = new Node;
        extra->value = val;
        extra->next = nullptr;
        extra->prev = tail_;
        tail_->next = extra;
        tail_ = extra;
    }
    
    digits_++; // increment the number of digits

}

 // deleting the node from the head
void LinkedList::deleteNodeHead()
{
    if(isEmpty() == 0) { // if list is not empty
    
        head_ = head_->next;  // make the head point to next 
        head_->prev = nullptr;
        digits_--; // decrement the number of digits
    }
    else {
        cout << "List is empty" << endl;
    }
}

// delete from the tail
void LinkedList::deleteNodeTail() // delete from the tail
{
    if (isEmpty() == 0) {  

        tail_ = tail_->prev;  //make the tail point to previous
        tail_->next = nullptr;
        
        digits_--; // decrement num of digits
    }
    else {
        cout << "List is empty" << endl;
    }

}

// getter for the flag
char LinkedList::getFlag() const  
{
    return flag_;
}

// setter for the flag
void LinkedList::setFlag(char f)    
{
    flag_ = f;
}

// getting the number of digits
int LinkedList::getNumDigits() const
{
    return digits_;  
}

// check to see if the list is empty
bool LinkedList::isEmpty() const
{
    if (head_ == nullptr && tail_ == nullptr) {
        return 1;
    }
    return 0;
}

//printing the list
void LinkedList::printAll() 
{
    if(isEmpty() ==0 ) {
        cout << flag_;   
        Node* temp = new Node;
        temp = head_;
        while(temp != nullptr)   // travere the list until end is found
        {
            cout << temp->value << " ";
            temp = temp->next;
        }

        cout << endl;
    }
    else {
        cout << "List is empty" << endl;
    }
}

//removing extra zeros
void LinkedList::removeExtraZeros()
{
  while(head_->value == 0)
  {
    head_= head_->next;
    digits_--;
  }
}