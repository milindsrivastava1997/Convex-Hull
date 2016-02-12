#include "Point.h"
#include <iostream>
using namespace std;

Point::Point(void)
{
    x = 0;
    y = 0;
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
    cout << endl << "Polar angle = " << polarAngle;
}

void Point::setPolarAngle(void)
{
    if (x == 0 && y == 0)
    {
        polarAngle = -1;
        return;
    }
    if (x == 0)
    {
        polarAngle = INF;
        return;
    }
    polarAngle = ((float)y) / ((float)x);
}

void Point::setx(int t)
{
    x = t;
}

void Point::sety(int t)
{
    y = t;
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