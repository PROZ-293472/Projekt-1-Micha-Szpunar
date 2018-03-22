#ifndef CLASSDEF_H
#define CLASSDEF_H

using namespace std;

class Tensor{
    int dimx, dimy, dimz;
    double ***tab;
    double val;
public:
    Tensor( int=1, int=1, int=1);
    Tensor( Tensor const &t);
    Tensor& operator=(Tensor const  &t);
    bool operator==(Tensor const  &t);
    bool operator!=(Tensor const  &t);
    Tensor operator+(Tensor const  &t);
    void operator+=(Tensor const  &t);
    Tensor operator-(Tensor const  &t);
    void operator-=(Tensor const  &t);
    Tensor operator*(Tensor const  &t);
    void operator*=(Tensor const  &t);
    double read(int a, int b, int c);
    void change(double w, int a, int b, int c);

friend
    ostream& operator<< (ostream &os, const Tensor &t);
friend
    istream& operator>>(istream &is, Tensor &t);

};
#endif // CLASSDEF_H
