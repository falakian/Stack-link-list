/* 
 * Stack.cpp
 *
 * Description: Implementation of an int sequence with push/pop ...
 * Class Invariant: ... in a LIFO order
 *
 * Author:
 * Date:
 */
 
#include <cstddef>  // For NULL
#include <iostream>
#include "Stack.h"

using namespace std;

// Constructor of the stack class in which we null the head and tail values
Stack::Stack()
{
    this->head= nullptr;
    this->tail= nullptr;
}
// Destructive stack class in which we remove dynamic memory
Stack::~Stack()
{
    while(!this->isEmpty()) // It clears all members until the stack is empty
    {
        StackNode *tmp = this->head;
        head=head->next;
        delete tmp;
        tmp=nullptr;
    }
    this->tail= nullptr;
}
// Add data to the end of the stack class
void Stack::push(int x)
{
    StackNode *tmp = new StackNode;
    tmp->next = nullptr;
    tmp->data = x;
    if(this->isEmpty())  // If the stack was empty
        this->head=this->tail=tmp;
    else
    {
        this->tail->next = tmp;
        this->tail = tmp;
    }
    return;
}
// The function to remove the last element of the stack and return its value
int Stack::pop()
{
    if(isEmpty()) // If the stack was empty
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else
    {
        int top = this->peek(); // The value of the last element of the stack
        if(this->head!=this->tail)
        {
            StackNode *tmp = this->head;
            while (tmp->next != this->tail)
                tmp = tmp->next;
            tmp->next = nullptr;
            delete this->tail;
            this->tail = tmp;
        }
        else // If we had only one element in the stack
        {
            delete this->head;
            this->head =nullptr;
            this->tail =nullptr;
        }
        return top;
    }
}
// The value of the last element of the stack
int Stack::peek() const
{
    return tail->data;
}
// Check if the stack is empty
bool Stack::isEmpty() const
{
    if (this->head==nullptr )
        return true;
    else
        return false;
}