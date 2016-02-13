#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(void)
{
    x = 0;
    y = 0;
    relativex = 0;
    relativey = 0;
    polarAngle = -1.0;
    next = nullptr;
}

void Point::input(void)
{
    cout << endl << "Enter x coordinate : ";
    cin >> x;
    cout << endl << "Enter y coordinate : ";
    cin >> y;
}

void Point::output(void)
{
    cout << endl << "x = " << x;
    cout << endl << "y = " << y;
    cout << endl << "relative-x = " << relativex;
    cout << endl << "relative-y = " << relativey;
    cout << endl << "Tan of Polar angle = " << polarAngle;
}

void Point::shortOutput(void)
{
    cout << endl << "(" << x << "," << y << ")";
}

void Point::setPolarAngle(void)
{
    if (relativex == 0 && relativey == 0)
    {
        polarAngle = -1;
        return;
    }
    if (relativex == 0)
    {
        polarAngle = INF;
        return;
    }
    polarAngle = ((float)relativey) / ((float)relativex);
}

void Point::setRelativex(int t)
{
    relativex = t;
}

void Point::setRelativey(int t)
{
    relativey = t;
}

float Point::getPolarAngle(void)
{
    return polarAngle;
}

int Point::getx(void)
{
    return x;
}

int Point::gety(void)
{
    return y;
}