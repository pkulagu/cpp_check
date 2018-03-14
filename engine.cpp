#include<iostream>
#include"safety.h"
using namespace std;



int ignition_check()
{
    int ignition;
    cout<<"\n Press 1 to switch Igition ON 0 to Ignition OFF"<<endl;
    cin>>ignition;
    return ignition;
}
