#include <iostream>
#include <iomanip>
#include "safety.h"


using namespace std;


int defangle=90;
int prevspeed=0;

class Airbag_Control_Unit
{
private:
    int ab_deploy;
public:
    Airbag_Control_Unit()
    {
        ab_deploy=0;
    }
    int evaluate()
    {
        int type;
        int mode=seat_belt();
        int case1=speed();
        int case2;
        if(case1==1)
        {
            if(mode==1)
            ab_deploy=1;
            else
                cout<<"\nSeat belt is OFF"<<endl;
        }
        else
            {
                case2=yaw_rate();
                if(mode==1)
                ab_deploy=(case2==1)?1:0;
                else
                    cout<<"\nSeat belt is OFF"<<endl;
            }

        if(1==ab_deploy)
        {
            type=seat_belt_distance();
            if(type==1)
                this->inflator();
            else
                this->inflator(1);
            return 1;
        }
        else
            return 0;
    }
    void inflator();
    void inflator(int x);

};
void Airbag_Control_Unit ::inflator()
{
        cout<<"    -"<<endl;
        cout<<"  -   -"<<endl;
        cout<<"-      -"<<endl;
        cout<<"  -   -"<<endl;
        cout<<"    -"<<endl;
        cout<<"\nAirbag type1 Deployed"<<endl;
}
void Airbag_Control_Unit::inflator(int x)
{
        cout<<"       -"<<endl;
        cout<<"     -    -"<<endl;
        cout<<"   -       -"<<endl;
        cout<<" -         -"<<endl;
        cout<<"   -       -"<<endl;
        cout<<"     -    -"<<endl;
        cout<<"        -"<<endl;
        cout<<"\nAirbag type2 Deployed"<<endl;

}

class drowsiness
{
public:
    int currentspeed=0;

    void buzzer()
    {
        cout<<"WARNING! STAY AWAKE\n";
    }

    int reducespeed(int currentspeed)
    {
        cout<<"Actual Speed: "<<currentspeed<<"\n";
        currentspeed=currentspeed-5;
        if(currentspeed>0)
        {
        cout<<"Speed Reduced!\n";
        cout<<"Current Speed: "<<currentspeed<<"\n";
        }
        else
        {
            cout<<"Actual Speed: 0\n";
        }
    }

    int steering_angle()
    {
        int prevangle, currentangle, diff;
        cout<<"\nEnter the current angle:";
        cin>>currentangle;
        prevangle=defangle;
        diff=prevangle-currentangle;
        if(diff<0)
        {
            diff=-diff;
        }
        if(diff>45)
        {
            buzzer();
        }
        if(currentangle<0 || currentangle>180)
        {
            cout<<"Invalid Input\n";
        }
        defangle=currentangle;
    }

    int driving_speed()
    {
        int currentspeed, diff;
        cout<<"\nEnter the current speed:";
        cin>>currentspeed;
        diff=prevspeed-currentspeed;
        if(diff<0)
        {
            diff=-diff;
        }
        if(diff>10)
        {
            buzzer();
            reducespeed(currentspeed);
        }
        prevspeed=currentspeed;
        return currentspeed;
    }

    int camera()
    {
        char n;
        cout<<"Press 'n' if the eye movement seems to be drowsy";
        cin>>n;
        if(n=='n')
        {
            buzzer();
        }
    }
};


int main()
{

    Airbag_Control_Unit *ob,a;
    ob=&a;
    int i=0,deploy;
    while(i==0)
    {
        if(ignition_check())
        deploy=(*ob).evaluate();
        else
        {
            cout<<"\nEngine is OFF"<<endl;
            i=1;
        }
        if(deploy==1)
            i=1;

    }
    drowsiness d;
    int eng;
    eng=ignition_check();
    while(eng==1)
    {
        d.driving_speed();
        d.camera();
        d.steering_angle();
        d.camera();
        cout<<"\n To exit press 0 \tTo continue press 1 "<<endl;
        cin>>eng;
    }

    return 0;
}
