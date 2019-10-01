/**
 * File: stack.h
 * Chris Anthony
 * Course: CMPS 1063 - Fall 2019
 * Description:
 *    Definition of our stack class.
 */

class Stack
{
  private:
    int *A;         // container of items (could make it a list)
    int Top;        // keep track of top
    int Size;
    int count;       // Arrays need a size
    
  public:
    
    Stack();        // Default constructor
    
    Stack(int);     // overloaded constructor
    bool Push(int); // Push value onto stack
    int Pop();      // Remove item from top of stack
    void Print();   // Help inspect values
    bool Empty();   // Is stack empty
    bool Full();    // is stack full
    void Enlarge();
    void Reduce();
    void checkResize;
};