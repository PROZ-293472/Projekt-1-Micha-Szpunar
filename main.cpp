#include <iostream>
#include "classdef.h"
#include <cstdio>

using namespace std;



int main()
{
    int choice;
    int x,y,z;
    Tensor t1,t2,t3;
    for(int i=0;i<10;i++){
        cout<<"menu:"<<endl;
        cout<<"1. podaj wymiary t1"<<endl;
        cout<<"2. podaj wymiary t2"<<endl;
        cout<<"3. podaj wartosci t1(>>t1)"<<endl;
        cout<<"4. podaj wartosci t2(>>t2)"<<endl;
        cout<<"5. drukuj t1 (<<t1)"<<endl;
        cout<<"6. drukuj t2 (<<t2)"<<endl;
        cout<<"7. drukuj t3 (<<t3)"<<endl;
        cout<<"8. t3=t1+t2"<<endl;
        cout<<"9. t1+=t2"<<endl;
        cout<<"10. t3=t1-t2"<<endl;



        cin>>choice;
        switch(choice){
        case 1:
            cin>>x>>y>>z;
            t1=Tensor(x,y,z);
            break;
        case 2:
            cin>>x>>y>>z;
            t2=Tensor(x,y,z);
            break;
        case 3:
            cin>>t1;
            break;
        case 4:
            cin>>t2;
            break;
        case 5:
            cout<<t1;
            break;
        case 6:
            cout<<t2;
            break;
        case 7:
            cout<<t3;
            break;
        case 8:
            t3=t1+t2;
            cout<<t3;
            break;
        case 9:
            t1+=t2;
            break;
        }

    }
    return 0;
}
