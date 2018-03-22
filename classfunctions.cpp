#include <iostream>
#include <cstdlib>
#include "classdef.h"

#define MESSAGE "Impossible! The following tensors have different dimensions\n"

using namespace std;

Tensor::Tensor(int wymx, int wymy, int wymz){ //dynamic array!!!
    tab = new double **[wymx];
    for (int i=0; i<wymx; i++){
        tab[i]= new double *[wymy];
        for(int j=0;j<wymy;j++){
            tab[i][j]=new double [wymz]();
        }
    }
    dimx=wymx;
    dimy=wymy;
    dimz=wymz;
    val=0.0;
}

Tensor::Tensor(Tensor const &t){
	tab = new double **[t.dimx];
	for(int i = 0; i<t.dimx; i++){
		tab[i] = new double *[t.dimy];
		for(int j=0; j< t.dimy; j++) {
		    tab[i][j]=new double [t.dimz];
            for (int k=0; k<t.dimz; k++){
                tab[i][j][k]=t.tab[i][j][k];
            }
		}

	}
    dimx=t.dimx;
    dimy=t.dimy;
    dimz=t.dimz;
}

istream& operator>> (istream &is, Tensor &t){
    double liczba;
    for(int i=0;i<t.dimx;i++){
        for (int j=0; j<t.dimy;j++){
            for (int k=0;k<t.dimz;k++){
                is>>liczba;
                if (is.good()) {
                    t.tab[i][j][k]=liczba;
                    t.val=liczba;
                }
                else {
                    k--;
                    is.clear();
                    is.sync();
                }
            }
        }
    };
    return is;
}

ostream& operator<< (ostream &os, const Tensor &t){
for (int i=0; i<t.dimx; i++){
    for (int j=0; j<t.dimy; j++){
        for (int k=0; k<t.dimz; k++){
            os<<t.tab[i][j][k]<<" ";
        }
        os<<"\n";
    }
    os<<"-----------\n";
}
return os;
}

Tensor& Tensor::operator=(const Tensor &t){
dimx=t.dimx; dimy=t.dimy; dimz=t.dimz;
tab = new double** [dimx];
for (int i=0; i<dimx; i++){
    tab[i]=new double* [dimy];
    for(int j=0; j<dimy; j++){
        tab[i][j]= new double [dimz];
    }
}
for (int i=0; i<dimx; i++){
    for (int j=0; j<dimy; j++){
        for(int k=0; k<dimz; k++){
            tab[i][j][k]=t.tab[i][j][k];
        }
    }
}
return *this;
}

bool Tensor::operator==(const Tensor &t){
if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz)) return false;
for (int i=0; i<dimx; i++){
    for (int j=0; j<dimy; j++){
        for(int k=0; k<dimz; k++){
            if(this->tab[i][j][k]!=t.tab[i][j][k]) return false;
        }
    }
}
return true;
}

bool Tensor::operator!=(const Tensor &t){
if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz)) return true;
for (int i=0; i<dimx; i++){
    for (int j=0; j<dimy; j++){
        for(int k=0; k<dimz; k++){
            if(this->tab[i][j][k]!=t.tab[i][j][k]) return true;
        }
    }
}
return false;
}


Tensor Tensor::operator+(const Tensor& t){
if ((dimx==t.dimx)&&(dimy==t.dimy)&&(dimz==t.dimz)){
    Tensor p(dimx,dimy,dimz);
    for (int i=0; i<dimx; i++){
        for (int j=0; j<dimy; j++){
            for(int k=0; k<dimz; k++){
                p.tab[i][j][k]=tab[i][j][k]+t.tab[i][j][k];
            }
        }
    }
    return p;
}
else cerr<<MESSAGE;
}

Tensor Tensor::operator-(const Tensor& t){
if (dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz){
    Tensor p(dimx, dimy, dimz);
    for (int i=0; i<dimx; i++){
        for (int j=0; j<dimy; j++){
            for(int k=0; k<dimz; k++){
                p.tab[i][j][k]=val-t.val;
            }
        }
    }
    return p;
}
else cerr<<MESSAGE;
}

Tensor Tensor::operator*(const Tensor &t){
if (dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz){
    Tensor p(dimx,dimy,dimz);
    for (int i=0; i<dimx; i++){
        for (int j=0; j<dimy; j++){
            for(int k=0; k<dimz; k++){
                p.tab[i][j][k]=val*t.val;
            }
        }
    }
return p;
}
else cerr<<MESSAGE;
}

void Tensor::operator+=(const Tensor &t){
if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz))
    cerr<<MESSAGE;
else{
    for (int i=0; i<dimx; i++){
        for (int j=0; j<dimy; j++){
            for(int k=0; k<dimz; k++){
                this->tab[i][j][k]=val+t.val;
            }
        }
    }

}
}

void Tensor::operator-=(const Tensor &t){
if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz))
    cerr<<MESSAGE;
else{
    for (int i=0; i<dimx; i++){
        for (int j=0; j<dimy; j++){
            for(int k=0; k<dimz; k++){
                this->tab[i][j][k]=val-t.val;
            }
        }
    }

}
}

void Tensor::operator*=(const Tensor &t){
if (!(dimx==t.dimx&&dimy==t.dimy&&dimz==t.dimz))
    cerr<<MESSAGE;
else{
    for (int i=0; i<dimx; i++){
        for (int j=0; j<dimy; j++){
            for(int k=0; k<dimz; k++){
                this->tab[i][j][k]=val*t.val;
            }
        }
    }

}
}

double Tensor::read(int a, int b, int c){
    if((a-1>dimx)||(b-1>dimy)||(c-1>dimz)) {
        cout<<"No match!"<<endl;
        return -1;
    }
    else return tab[a-1][b-1][c-1];
}

void Tensor::change(double w, int a, int b, int c){
    if(a-1>dimx||b-1>dimy||c-1>dimz) cerr<<"No match!"<<endl;
    else tab[a-1][b-1][c-1]=w;
    return;
}

