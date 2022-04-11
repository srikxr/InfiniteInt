/*
InfiniteInt.h - Srikar Chava 1/21/2022

The code in this file serves as definitions of the functions and data types that need to be implemented within the
program. It inlcudes friend definitions of operator overloads and a data type called list_, which is a LinkedList type.
*/

#pragma once
#include <iostream>
#include "LinkedList.h"

class InfiniteInt {
public:

    //constructors
    InfiniteInt();
    InfiniteInt(const InfiniteInt&);
    ~InfiniteInt();

    explicit InfiniteInt(int a);
    explicit operator int() const;

    //other functions
    int numDigits() const;
    void display();
    void insertIntoList(int v);
    void insertIntoTail(int v);
    void insertFlag(char f);

	InfiniteInt& operator=(const InfiniteInt& other); 
    
    //friend operator overloads for the program
    friend bool operator==(const InfiniteInt& one,const InfiniteInt& two);
    friend InfiniteInt operator+(const InfiniteInt& one,const InfiniteInt& two);
	friend InfiniteInt operator*(const InfiniteInt& one,const InfiniteInt& two);
	friend InfiniteInt operator-(const InfiniteInt& one,const InfiniteInt& two);
	friend bool operator>(const InfiniteInt& one,const InfiniteInt& two);
	friend bool operator<(const InfiniteInt& one,const InfiniteInt& two); 
    
    //stream operators
	friend ostream &operator<<(ostream& output,const InfiniteInt& other); 
	friend istream &operator>>(istream& input,InfiniteInt& other); 

private:
    LinkedList list_;
};