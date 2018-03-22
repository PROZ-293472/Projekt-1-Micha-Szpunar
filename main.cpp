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
        cout<<"11. t1-=t2"<<endl;
        cout<<"12. t1==t2"<<endl;
        cout<<"13. t1!=t2"<<endl;
        cout<<"14. t3=t1*t2"<<endl;
        cout<<"15. t1*=t2"<<endl;
        cout<<"16. znajdz w t1 element o danych wspolrzednych"<<endl;
        cout<<"17. zamien w t1 element o danych wspolrzednych"<<endl;



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
        case 10:
            t3=t1-t2;
            cout<<t3;
            break;
        case 11:
            t1-=t2;
            break;
        case 12:
            bool czy;
            czy=(t1==t2);
            cout<<czy<<endl;
            break;
        case 13:
            bool czy2;
            czy2=(t1!=t2);
            cout<<czy2<<endl;
            break;
        case 14:
            t3=t1*t2;
            cout<<t3;
            break;
        case 15:
            t1*=t2;
            break;
        case 16:
            int a, b, c;
            cin>>a>>b>>c;
            cout<<t1.read(a,b,c)<<endl;
            break;
        case 17:
            int d, e, f;
            cin>>d>>e>>f;
            double w;
            cin>>w;
            t1.change(w,d,e,f);
        }

    }
    return 0;
}

