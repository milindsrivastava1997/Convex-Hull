#pragma once
#include "Point.h"

class Stack
{
private:
    Point* top;
    int count;

public:
    Stack(void);
    void push(Point);
    Point pop(void);

    bool checkCCW(void);
    void remove2ndElement(void);

    int getCount(void);

    void output(void);

    ~Stack(void);
};