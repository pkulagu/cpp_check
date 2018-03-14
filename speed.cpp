#include <iostream>
#include "safety.h"
using namespace std;
float speed1=0;
float speed2=0;
int speed()
{
    cout<<"\nEnter the speed of car"<<endl;
    cin>>speed2;
    if(speed2==speed1)
        {cout<<"Car traveling at constant speed";
        return 0;}
    else if(speed2>speed1)
    {
        cout<<"Car accelerated at "<<speed2-speed1<<endl;
        speed1=speed2;
        return 0;
    }
    else if(speed2<speed1)
    {
        float speed_change=speed1-speed2;
        if(speed_change>20)
            return 1;
        else
            {
                cout<<"Car decelerated at "<<speed_change<<endl;
                speed1=speed2;
                return 0;
            }

    }
    return 1;
}


