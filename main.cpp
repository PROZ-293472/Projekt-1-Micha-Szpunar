#include <iostream>
#include "classdef.h"
#include <cstdio>

using namespace std;



int main()
{
    int choice;
    int x1,y1,z1;
    cin>>x1>>y1>>z1;
    Tensor t1(x1,y1,z1),t2,t3;
    for(int i=0;i<10;i++){
        cout<<"menu/n"<<endl;
        cin>>choice;
        switch(choice){
        case 1:
            t2=t1;
            cout<<t2;
            break;
        /*case 2:
            t1+=t2;
            break;
        case 3:
            t3=t1+t2;
            break;*/
        case 2:
            cout<<t1;
            break;
        }

    }
    return 0;
}
