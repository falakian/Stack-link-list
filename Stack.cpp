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


Stack::Stack()
{
    this->head= nullptr;
    this->tail= nullptr;
}

Stack::~Stack()
{
    delete this->head;
    this->head= nullptr;
    delete this->tail;
    this->head= nullptr;
}

void Stack::push(int x)
{
    StackNode *tmp = new StackNode;
    tmp->next = nullptr;
    tmp->data = x;
    if(this->isEmpty())
        this->head=this->tail=tmp;
    else
    {
        this->tail->next = tmp;
        this->tail = tmp;
    }
    return;
}

int Stack::pop()
{
    if(isEmpty())
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    else
    {
        int top = this->peek();
        if(this->head!=this->tail)
        {
            StackNode *tmp = this->head;
            while (tmp->next != this->tail)
                tmp = tmp->next;
            tmp->next = nullptr;
            delete this->tail;
            this->tail = tmp;
        }
        else
        {
            delete this->head;
            this->head =nullptr;
            this->tail =nullptr;
        }
        return top;
    }
}

int Stack::peek() const
{
    return tail->data;
}

bool Stack::isEmpty() const
{
    if (this->head==nullptr )
        return true;
    else
        return false;
}