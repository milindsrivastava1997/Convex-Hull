#pragma once
#include <limits.h>

const int INF = INT_MAX;
class Point
{
private:
    int x;
    int y;
    float polarAngle;

    
    //int sortIndex;

public:
    Point* next;

    Point(void);

    void input(void);
    void output(void);

    void setPolarAngle(void);
    void setx(int);
    void sety(int);
    //void setSortIndex(int);

    float getPolarAngle(void);
    int getx(void);
    int gety(void);
    //int getSortIndex(void);
};