#include <iostream>
#include "safety.h"

using namespace std;

float sensordata;
int yaw_rate()
{
    float sensordata;

    cout << "\nEnter yaw rate sensor value:" << endl;
    cin >> sensordata;

    try
    {

    if(sensordata<0)
    {
        sensordata=-sensordata;
    }
    if(sensordata>=0 && sensordata<=0.13)
    {
        cout << "The vehicle is stationary"<<endl;
        return 0;
    }
    else if(sensordata>0.14 && sensordata<1.7)
    {
        cout << "Driving smooth"<<endl;
        return 0;
    }
    else if(sensordata>=1.71 && sensordata<=1.869)
    {
        return 1;
    }
    else
    {
        throw 1;
    }
    }catch(int e)
    {
        cout << "Invalid value"<<endl;
    }

}

