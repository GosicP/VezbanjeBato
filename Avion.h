#ifndef _avion_h_
#define _avion_h_
#include <iostream>
#include <string>
#include "Piloti.h"
using namespace std;

class avion{
string ime;
pilot kapetan, kopilot;
int kap;

public:
    avion()=default;
    avion(int k, string i){
        kap=k;
        ime=i;
    }
    string dohvIme() const{return ime;}
    pilot dohvKapetan() const{return kapetan;}
    pilot dohvKopilot() const{return kopilot;}
    int dohvKap() const{return kap;}
    void IspisPilota(){
        cout<<"kapetan je"<<endl;
        kapetan.Ispis();
        cout<<endl;
        cout<<"kopilot je"<<endl;
        kopilot.Ispis();
    }

    /*void isitkapetan(pilot& p1, pilot& p2){ //proveri da li ovo radi, probaj sa DohvStanje()
        //da bi stanje mogao da vratis u private
        int hrs1, hrs2;
        hrs1=p1.DohvSatiLetenja();
        hrs2=p2.DohvSatiLetenja();
        if (hrs1>99 and hrs2>99){
            if (hrs1>hrs2){
                kapetan=p1;
                kapetan.Stanje=1;
                kopilot=p2;
                kopilot.Stanje=1;
            }else{
                kapetan=p2;
                kapetan.Stanje=1;
                kopilot=p1;
                kopilot.Stanje=1;
            }
        }else if(hrs1>99){
            kapetan=p1;
            kapetan.Stanje=1;
            kopilot=p2;
            kopilot.Stanje=1;
        }else if(hrs2>99){
            kapetan=p2;
            kapetan.Stanje=1;
            kopilot=p1;
            kopilot.Stanje=1;
        }else if(hrs1<100 and hrs2<100){
            cout<<"Ni jedan pilot nema preko 100 sati";
            exit(1);
        }

    }*/
    void setkapetan(pilot &p){
        int hrs;
        hrs=p.DohvSatiLetenja();
        if(hrs>100){
            p.PromeniStanje();
            kapetan=p;
        }
    }
    void setkopilot(pilot &p){
        p.PromeniStanje();
        kopilot=p;
    }
    void Ispis(){
        cout<<"AVION:"<<ime<<"-"<<kap;
    }


};


#endif
