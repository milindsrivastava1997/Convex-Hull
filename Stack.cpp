#include "Stack.h"

Stack::Stack(void)
{
    top = nullptr;
    count = 0;
}

void Stack::push(Point toBeAdded)
{
    if (top == nullptr)
    {
        top = new Point;
        *top = toBeAdded;
        top->next = nullptr;
    }
    else
    {
        Point* temp = new Point;
        *temp = toBeAdded;
        temp->next = top;
        top = temp;
    }
    count++;
}

Point Stack::pop(void)
{
    Point tempObj;
    tempObj = *(top);
    Point* tempPtr = top;
    top = top->next;
    delete tempPtr;
    return tempObj;
}

bool Stack::checkCCW(void)
{

}

int Stack::getCount(void)
{
    return count;
}

Stack::~Stack(void)
{
    Point* tempPtr;
    tempPtr = top;
    while (top != nullptr) 
    {
        top = top->next;
        delete tempPtr;
        tempPtr = top;
    }
}