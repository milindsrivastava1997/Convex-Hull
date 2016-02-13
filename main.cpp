#include "Stack.h"
#include <iostream>
using namespace std;
#include <conio.h>

int main()
{
    int n = 0;

    do {
        cout << "Enter the number of points : ";
        cin >> n;
        cout << endl;
    } while (n < 3);

    Point* arrayOfPoint;
    arrayOfPoint = new Point[n];

    for (int i = 0; i < n; i++)
    {
        arrayOfPoint[i].input();
        //arrayOfPoint[i].output();
        cout << endl << "--------------------------";
    }

    int indexOfOrigin = 0;
    for (int i = 0; i < n; i++)//finding origin
    {
        if ((arrayOfPoint[i].getx() <= arrayOfPoint[indexOfOrigin].getx()) && (arrayOfPoint[i].gety() <= arrayOfPoint[indexOfOrigin].gety()))//if i_th element is to the bottom and left of origin, set i_th element as origin
        {
            indexOfOrigin = i;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i != indexOfOrigin)//setting coordinates of points relative to origin
        {
            arrayOfPoint[i].setRelativex(arrayOfPoint[i].getx() - arrayOfPoint[indexOfOrigin].getx());
            arrayOfPoint[i].setRelativey(arrayOfPoint[i].gety() - arrayOfPoint[indexOfOrigin].gety());
        }
    }
    arrayOfPoint[indexOfOrigin].setRelativex(0);
    arrayOfPoint[indexOfOrigin].setRelativey(0);

    for (int i = 0; i < n; i++)
    {
        arrayOfPoint[i].setPolarAngle();
        //arrayOfPoint[i].output();
        //cout << endl << "--------------------------";
    }

    for (int i = 0; i < n; i++)//sorting array according to polar angle, origin with value -1 is first element
    {
        int j = i;
        while (j > 0 && arrayOfPoint[j].getPolarAngle() <= arrayOfPoint[j - 1].getPolarAngle())
        {
            if (arrayOfPoint[j].getPolarAngle() == arrayOfPoint[j - 1].getPolarAngle())
            {
                if (arrayOfPoint[j].getx() < arrayOfPoint[j - 1].getx())//FIX
                {
                    Point temp;
                    temp = arrayOfPoint[j];
                    arrayOfPoint[j] = arrayOfPoint[j - 1];
                    arrayOfPoint[j - 1] = temp;
                    --j;
                    //continue;
                }
                else
                {
                    j--;
                }

            }
            else
            {
                Point temp;
                temp = arrayOfPoint[j];
                arrayOfPoint[j] = arrayOfPoint[j - 1];
                arrayOfPoint[j - 1] = temp;
                --j;
            }
        }
    }

    /*for (int i = 0; i < n; i++)
    {
        arrayOfPoint[i].output();
        cout << endl << "--------------------------";
    }*/

    Stack stackOfPoint;
    stackOfPoint.push(arrayOfPoint[0]);
    stackOfPoint.push(arrayOfPoint[1]);
    for (int i = 2; i < n; i++)
    {
        stackOfPoint.push(arrayOfPoint[i]);
        //cout << endl << "Count=" << stackOfPoint.getCount();
        if (stackOfPoint.checkCCW() == true)
        {
            //cout << "CCW" << endl;
            continue;
        }
        else
        {
            while (stackOfPoint.checkCCW() == false)
            {
                //cout << "CW" << endl;
                stackOfPoint.remove2ndElement();
            }
           
        }
    }
    //cout << "---Final---" << endl;
    stackOfPoint.output();

    _getch();
    return 0;
}