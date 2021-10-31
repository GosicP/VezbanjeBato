#ifndef _piloti_h_
#define _piloti_h_
#include <iostream>
#include <string>
using namespace std;

class pilot{
    string ime;
    int SatiLetenja;
    int Stanje;
public:
    /*pilot(string n, int s=0, bool st=false){
        ime=n;
        SatiLetenja=s;
        Stanje=st;
    }*/
    string DohvName() const {return ime;}
    int DohvSatiLetenja() const {return SatiLetenja;}
    int DohvStanje() const{return Stanje;}
    int PovecajSate(int hrs){
        SatiLetenja=SatiLetenja+hrs;
        return SatiLetenja;
    }
    int PromeniStanje() {
        if (Stanje==0){
            return (Stanje=1);
        }else{
            return (Stanje=0);
        }
    }
    void Ispis() {
        if (Stanje == 1) {
            cout << ime << "(" << SatiLetenja << ")" << "-" << "L";
        }
        else{
            cout << ime << "(" << SatiLetenja << ")" << "-" << "N";
        }
    }
    void Unos(){
        cin>>ime>>SatiLetenja;
        Stanje=0;
    }
};


#endif