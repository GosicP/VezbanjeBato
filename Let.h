#ifndef _let_h_
#define _let_h_
#include <iostream>
#include <string>
#include "Piloti.h"
#include "Avion.h"
#include "FlotaAviona.h"
using namespace std;

class let {
string polaziste, dolaziste;
int id;
avion avion_na_relaciji;
public:
    let(string name1, string name2, int i, avion a){
        polaziste=name1;
        dolaziste=name2;
        id=i;
        avion_na_relaciji=a;
    }
    int dohvati_id() const{return id;}
    string dohvati_polaziste() const{return polaziste;}
    string dohvati_dolaziste() const{return dolaziste;}
    avion dohvati_avion_na_relaciji() const{return avion_na_relaciji;}
    void Ispis(){
        cout<<endl<<"LET"<<"-"<<polaziste<<":"<<dolaziste<<"-"<<avion_na_relaciji.dohvIme()<<endl;
    }
};


#endif //VEZBANJEBATO_LET_H
