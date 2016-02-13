#pragma once
#include <limits.h>

const int INF = INT_MAX;
class Point
{
private:
    int x;
    int y;
    int relativex;
    int relativey;
    float polarAngle;

    
    //int sortIndex;

public:
    Point* next;

    Point(void);

    void input(void);
    void output(void);
    void shortOutput(void);

    void setPolarAngle(void);
    void setRelativex(int);
    void setRelativey(int);
    //void setSortIndex(int);

    float getPolarAngle(void);
    int getx(void);
    int gety(void);
    //int getSortIndex(void);
};