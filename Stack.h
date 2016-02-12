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

    int getCount(void);

    ~Stack(void);
};