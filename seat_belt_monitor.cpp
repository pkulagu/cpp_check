#include<iostream>
#include"safety.h"
using namespace std;
int seat_belt()
{
    int mode;
    cout<<"\nEnter 1 for seat_belt ON 0 for seat_belt OFF"<<endl;
    cin>>mode;
    return mode;
}
int seat_belt_distance()
{
    float option;
    cout<<"\nEnter the distance of seat belt from dashboard"<<endl;
    cin>>option;
    if (option>=0.2 && option<=1.0)
        return 1;
    else if(option>=1.1 && option<=1.6)
        return 2;
    else
        return 1;
}
