#include "Stack.h"
#include <iostream>
using namespace std;

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
    count--;
    return tempObj;
}

bool Stack::checkCCW(void)
{
    if (count < 3)
    {
        return true;
    }

    Point temp1, temp2, temp3;
    temp1 = *(top->next->next);
    temp2 = *(top->next);
    temp3 = *(top);

    int det = (temp1.getx()*(temp2.gety() - temp3.gety())) + (temp2.getx()*(temp3.gety() - temp1.gety())) + (temp3.getx()*(temp1.gety() - temp2.gety()));

    if (det >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Stack::remove2ndElement(void)
{
    Point backToStack, temp;
    backToStack = pop();
    temp = pop();
    push(backToStack);
    cout << "Ousted : " << endl;
    temp.shortOutput();
}

int Stack::getCount(void)
{
    return count;
}

void Stack::output(void)
{
    Point* temp;
    temp = top;
    while (temp != nullptr)
    {
        temp->shortOutput();
        temp = temp->next;
    }
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