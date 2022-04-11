/*
InfiniteInt.cpp - Srikar Chava 1/21/2022

The code in this file serves as implementations of the functions that were defined in InfiniteInt.h
The functions in this class will be used for arithmetic operations and other basic functions. There are also several
overloaded operators in this file.

*/
#include <iostream>
#include "InfiniteInt.h"

using namespace std;

// default constructor

InfiniteInt::InfiniteInt()  
{
    list_ = LinkedList();	 
}

//copy constructor
InfiniteInt::InfiniteInt(const InfiniteInt& other) 
{
    this->list_ = LinkedList(); //creating an empty list
    Node* temp = other.list_.getHead();  //getting the pointer of head

    while(temp != nullptr) { // traverse the list until the end of the list
      insertIntoList(temp->value);  //copying the value to the list
      temp = temp->next;        
    }
}

// destructor
InfiniteInt::~InfiniteInt() 
{
    Node* temp = list_.getHead(); // it will delete every space occupied by the list
	
    while(temp != nullptr) {
		Node* next = temp->next;
		temp = nullptr;
		temp = next;
	}
}

// parametrized Explicit constructor 
InfiniteInt::InfiniteInt(int a)
{
    if(a < 0) {    // if the number is less than 0, make the flag negeative
		a = a*-1;   
		list_.setFlag('-');	
	}
	
    if(a > 0) {  // if number is greater than 0
        while(a>0) {   // loop while number is greator than 0 
            int rem=a%10;   // getting the left most digit
            a=a/10;       
            list_.addNodeHead(rem);    // adding the digit to the list	
        }
    }
    else if(a==0) {      // if number is equal to 0 , insert only 0 to the list
        list_.addNodeHead(0);
    }

}

// converting the infiniteInt to int
InfiniteInt::operator int() const 
{
    int a = 0;
    int mul = 1;
    Node* temp = list_.getTail();    // getting the tail of the list

    while(temp != nullptr)     // travers the list until nullptr is found
    {
        a += temp->value * mul;     // adding the number to the int
        if(a < 0) {   
            cout << "There is an overflow" << endl;
            return a;
        }
        
        mul *= 10;   
        temp = temp->prev;
    }
    return a;

}

// getting the value of the number of digits
//pre- InfniteInt LinkedList post- number of nodes with values 
// returns the number of digits/nodes with values within the list
int InfiniteInt::numDigits() const    
{
    
    return list_.getNumDigits();
}

// displaying the list
//pre- InfniteInt LinkedList post- the LinkedList
// returns the printed output of the list
void InfiniteInt::display()  
{
    list_.printAll();
}

// will insert at the tail of the list
//parameter: integer
//pre- InfniteInt LinkedList post- Linked list with added node
// adds a node into list
void InfiniteInt::insertIntoList(int v)   
{
    list_.addNodeTail(v);
}

// will insert at the head of the list
//parameter: integer
//pre- InfniteInt LinkedList post- Linked list with added node
//adds a node into list
void InfiniteInt::insertIntoTail(int v)
{
    list_.addNodeHead(v);
}

// setting the value of the flag of the list
//parameter: char
//pre- InfniteInt LinkedList post- LinkedList with a flag value
void InfiniteInt::insertFlag(char f)   
{
	list_.setFlag(f);
}

//assignment operator
InfiniteInt& InfiniteInt::operator=(const InfiniteInt& other)  
{
    list_= other.list_;
    return *this;
}

//operator overloading  == checking if equal
bool operator==(const InfiniteInt& one,const InfiniteInt& two) 
{
    if(one.list_.getFlag() != two.list_.getFlag()) {
        return 0;
    }

	if (one.list_.getNumDigits() == two.list_.getNumDigits()) {
		Node* temp1 = new Node;
		Node* temp2 = new Node;
		
		temp1 = one.list_.getHead();
		temp2 = two.list_.getHead();

		while(temp1 != nullptr) {
			if (temp1->value != temp2->value) { // if values do not match
				return false;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}

		return true;
	}
	return false;
	
}

//addition operator overloading
InfiniteInt operator+(const InfiniteInt& one,const InfiniteInt& two)  //operator overload for adding
{
    if (one.list_.isEmpty()) {
		return two;
	}
	else if(two.list_.isEmpty()) {
		return one;
	}
	else {

        if((one.list_.getFlag() == '-' && two.list_.getFlag() == '+') || (one.list_.getFlag() == '+' && two.list_.getFlag()=='-')) { 
			InfiniteInt temp;
			temp = one - two;
			return temp;
		}		

		InfiniteInt temp;
		temp.list_= LinkedList(); //create an empty list
		
		if((one.list_.getFlag() == '-' && two.list_.getFlag() == '-')) { 
			temp.list_.setFlag('-');
		}

		Node* oneList = one.list_.getTail();
		Node* twoList = two.list_.getTail();
		int carry=0;

		if(one.numDigits() == two.numDigits()) { // if both list have equal length
		
			while(oneList != nullptr) {  // traversing until end is found
				int a = oneList->value + twoList->value;  // add both values
				int aftercarry = a + carry; // if there is carry add the carry
				temp.list_.addNodeHead(aftercarry%10); // insert the value to resultant list
				
				carry = aftercarry/10;
				
				oneList = oneList->prev;
				twoList = twoList->prev;
			}
			if(carry > 0) {// if carry reamains add to the head
				temp.list_.addNodeHead(carry);
			}	
		}
		else if(one.numDigits() > two.numDigits()) { // if one is greator than second
			while(twoList != nullptr) {	
				int a = oneList->value + twoList->value;  // add both
				int aftercarry = a + carry; //add carry
				temp.list_.addNodeHead(aftercarry % 10); // insert to the list
				
				carry = aftercarry/10;
				
				oneList = oneList->prev;
				twoList = twoList->prev;
			}
			if(carry==0)  {
				while(oneList != nullptr) {
					temp.list_.addNodeHead(oneList->value);  // copy the numbers to resultant
					oneList = oneList->prev;
				}
			}
			if(carry > 0) { 
				while(oneList != nullptr) {
					int a = oneList->value + carry; // add the carry
					temp.list_.addNodeHead(a % 10); // add to head 
					carry = a/10;   
					oneList = oneList->prev;	
				}
				if (carry > 0) {
                    // if carry remains add to the start
					temp.list_.addNodeHead(carry);
				}
			}
		}
		else if(one.numDigits() < two.numDigits()) {// if two is greator than one
			return two + one; // recursion to the same 
		}
		return temp;	
		
	}
}

//operator overload for multiplying
InfiniteInt operator*(const InfiniteInt& one, const InfiniteInt& two)  
{
	if (one.list_.isEmpty() || two.list_.isEmpty()) {  // if one list is empty
		cout << "Error, one of the list is empty";
		return one;
	}
	else {
		InfiniteInt temp[one.numDigits()];    // creating array of InfiniteInt
	
		Node* oneList = one.list_.getTail();
		Node* twoList = two.list_.getTail();
		int carry = 0;
			
		int iter = 0;	
			
		while(oneList != nullptr) {
			for(int i = 0; i < iter; i++) { // add 0 to the tail 
				temp[iter].list_.addNodeHead(0);
			}
			
			int addedCarry = 0;
			twoList = two.list_.getTail();   
			while(twoList != nullptr) {   // traversing until the end is found
				int a = oneList->value * twoList->value;    //multiplying both values
				int addedCarry = a + carry;   //adding the carry
				
				temp[iter].list_.addNodeHead(addedCarry % 10);   // adding the product to the resultant list
		
				carry = addedCarry / 10;    //dividing the carry by 10
				twoList = twoList->prev;	
			}
			if(carry > 0) {  // if carry remains, add to the head of the list
				temp[iter].list_.addNodeHead(addedCarry % 10);	
			}
			iter++;
			
			
			oneList=oneList->prev;
		}
		
	InfiniteInt newtemp;
	for (int i = 0; i < one.numDigits(); i++) {  // adding the array of infiniteInts together
		newtemp = newtemp + temp[i];	
	}	
	if(one.list_.getFlag() == '-' && two.list_.getFlag() == '-') { // if both have - sign, make the sign +
		newtemp.list_.setFlag('+');
	}
	if((one.list_.getFlag() == '-' && two.list_.getFlag() == '+') || (one.list_.getFlag() == '+' && two.list_.getFlag() == '-')) {
		newtemp.list_.setFlag('-');
	} 

    newtemp.list_.removeExtraZeros();  

	return newtemp;
		
	}
	
}

//subtracting two infiniteInt by operater overloading
InfiniteInt operator-(const InfiniteInt & one, const InfiniteInt& two)   
{
	if (one.list_.isEmpty() || two.list_.isEmpty()) {   // if one of the list is empty
		cout << "One of the list is empty" << endl;
	}
	else {
		InfiniteInt oneList = one; 
		InfiniteInt twoList = two;

		while(oneList.numDigits() > twoList.numDigits()) { 
			twoList.list_.addNodeHead(0);
		}
		while(oneList.numDigits() < twoList.numDigits()) { 
            // if 2 list is greator than 1, append 0 to the head of the list
			oneList.list_.addNodeHead(0);
		}

		if(oneList == twoList) {   // if both the lists have same length
			InfiniteInt temp(0);
			return temp;
		}
		else {  // if both do not have same length
            if(oneList > twoList) {
				
			    int borrow = 0;
				InfiniteInt temp;
				
				if(oneList.list_.getFlag() == '-')   // if the greater list has - sign, assign - to the resultant 
				{
					temp.list_.setFlag('-');
				}
				
				Node* tempOne = oneList.list_.getTail();   // getting the tail of the lists
				Node* tempTwo = twoList.list_.getTail();

				while(tempOne != nullptr) { // traverse until end is found  
					if(borrow == 1) {
						tempOne->value--;   // decrement the number
						borrow = 0;
					}	
					if(tempOne->value < tempTwo->value) {
						tempOne->value += 10; // add 10 to the number
						borrow = 1;     // set the borrow to 1
					}
					temp.list_.addNodeHead(tempOne->value - tempTwo->value); // insert the result of the subtractiom
					tempOne = tempOne->prev;
					tempTwo = tempTwo->prev;
				}

      
				return temp;

			}
			else {
				InfiniteInt temp;   
				temp = twoList - oneList;    // recursively call the same function
				temp.list_.setFlag('-'); 
				return temp;
			}
		}

	}
  InfiniteInt temp(0);  
  return temp;

}

// comparsion operator overloading
bool operator>(const InfiniteInt& one,const InfiniteInt& two) 
{
    if(one.list_.getFlag()=='+' && two.list_.getFlag()=='-') {
        return true;
    }
    else if (one.list_.getFlag()=='-' && two.list_.getFlag()=='+') {
        return false;
    }
    else {

        if(one.numDigits() > two.numDigits())   // if num of digits are not same
        {
            return true;	
        }	
        else if(one.numDigits() < two.numDigits())
        {
            return false;
        }
        else {   // if the number of digits are same
            Node* oneList = one.list_.getHead();
            Node* twoList = two.list_.getHead();
      
            while(oneList != nullptr) {   // traversing until the end is found
                if(oneList->value > twoList->value) {  //checking if one has greator value than other
                    return true;
                }
                else if(oneList->value < twoList->value) {
                    return false;
                }
                
                oneList = oneList->next;
                twoList = twoList->next;
        
            }
            cout << "Both are equal" << endl;
        }
        return true;
    }   
}

// comparsion operator overloading
bool operator<(const InfiniteInt& one,const InfiniteInt& two)  
{
    if(one.list_.getFlag() == '+' && two.list_.getFlag() == '-') {
        return false;
    }
    else if (one.list_.getFlag() == '-' && two.list_.getFlag() == '+') {
        return true;
    }

    else {
        if(one.numDigits() < two.numDigits()) { // if num of digits is greator than other
            return true;	
        }	
        else if(one.numDigits() > two.numDigits()) {
            return false;
        }
        else {   // if both have same num of digits
            Node* oneList = one.list_.getHead();
            Node* twoList = two.list_.getHead();
      
            while(oneList != nullptr) {   // traversing the list until the end
                if(oneList->value < twoList->value) {  // checking if one has greater value than other
                    return true;
                }
                else if(oneList->value > twoList->value) {
                    return false;
                }
                oneList = oneList->next;
                twoList = twoList->next;
        
            }
            cout << "Both are equal" << endl;
        }
        return true;
    }
}

// operater overloading for output <<
ostream &operator<<(ostream& output,const InfiniteInt& other) 
{
    Node* temp = new Node;
    temp = other.list_.getHead();

    if (other.list_.getFlag() == '-') {
        cout << other.list_.getFlag();
    }
    
    int firstNonZero = 0;
	while(temp != nullptr) {
		cout << temp->value;   
        temp = temp->next;
	}
    cout << " ";
    return output;
}

//operator overloading >>
istream& operator>>(istream& input,InfiniteInt& other) 
{
    other.list_ = LinkedList();
	int first = 0; 
   
	int a;
    cin >> a;
    if(a < 0) {  // if the number is less than 0, make the flag negeative
        a = a* - 1;   
        other.insertFlag('-');	
    }
    
    if(a > 0) { // if number is greator than 0
        while(a > 0) {   // loop while number is greator than 0 
            int rem = a % 10;   // getting the left most digit
            a = a / 10;       
            other.insertIntoTail(rem);    // adding the digit to the list	
        }
    }
    else if(a == 0) {     // if number is equal to 0 , insert only 0 to the list
        other.insertIntoTail(0);
    }
    return input;
}