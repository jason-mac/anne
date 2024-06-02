// clang-format off
/* 
 * Stack.h
 *
 * Description: Implementation of a linked list-based Stack ADT class - SHSL list
 * Class Invariant: LIFO order
 *                  Top of Stack located at the back of SHSL list.
 *
 * Author: Jason Mac
 * Date: May 2024
 */
 
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
    unsigned int elementCount;
  public:
/* Put your code here! */   

    
    Stack();
    ~Stack();

    // Description: Adds a new element to the top of this Stack.
    // Exception: Throws PushFailedException if push unsuccessful.
    // Time Efficiency: O(n)
    void push(int);

    // Description: Removes the top element of this Stack.
    // Precondition: The Stack is not empty.
    // Exception: Throws EmptyStackException if this Stack is empty.
    // Time Efficiency: O(n)
    void pop();
  
    // Description: Removes all elements from this Stack.
    // Postcondition: Stack is in same state as when constructed.
    void popAll();

    // Description: Returns the top of this Stack.
    // Precondition: The Stack is not empty.
    // Postcondition: This Stack is unchanged.
    // Exceptions: Throws EmptyStackException if this Stack is empty. ???????
    // Time Efficiency: O(n)
    int peek() const;

    // Description: Returns true if this Stack is empty otherwise false.
    // Postcondition: This Stack is unchanged.
    // Time Efficiency: O(1)
    bool isEmpty() const;

};

// clang-format on
