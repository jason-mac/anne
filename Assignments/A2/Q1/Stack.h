/*
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Jason Mac, and Jagyjot Parmar
 * Date: May 2024
 */
#ifndef STACK_H
#define STACK_H
 
class Stack {

  private:
    
    // Description:  Nodes for a singly-linked list - Do not modify!
    class StackNode {
      public:
        int data;
        StackNode * next;
    };
/* Put your code here! */       
    StackNode* head = nullptr;
  public:
/* Put your code here! */   

    
    // Description: Constructor
    // Postcondition: Stack has no elements
    Stack();

    // Description: Destructor
    // Postcondition: All nodes are deallocated from heap
    ~Stack();

    // Description: Adds a new element to the top of this Stack. Returns true
    //              if element is pushed, false otherwise
    // Postcondition: newElement is inserted at top of the stack
    // Time Efficiency: O(n) 
    bool push(int newElement);

    // Description: Removes the top element of this Stack. Returns true 
    //              if element is popped, false otherwise
    // Precondition: The Stack is not empty.
    // Postconditon: Element at top of the stack is removed
    // Time Efficiency: O(n) 
    bool pop();
  
    // Description: Removes all elements from this Stack.
    // Precondition: Stack is not empty
    // Postcondition: Stack is in same state as when constructed.
    // Time Efficiency: O(n) 
    void popAll();

    // Description: Returns the top of this Stack.
    // Precondition: The Stack is not empty.
    // Postcondition: This Stack is unchanged.
    // Time Efficiency: O(n) 
    int peek() const;

    // Description: Returns true if this Stack is empty, otherwise false.
    // Postcondition: This Stack is unchanged.
    // Time Efficiency: O(1) 
    bool isEmpty() const;

};

#endif
