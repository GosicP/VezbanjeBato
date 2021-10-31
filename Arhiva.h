#ifndef _arhiva_h_
#define _arhiva_h_
#include <iostream>
#include <string>
#include "Piloti.h"
#include "Avion.h"
#include "Let.h"
#include "FlotaAviona.h"


using namespace std;

class Arhiva {
struct node_arhiva{
    let* l;
    node_arhiva* next;
    node_arhiva(let* ll, node_arhiva* s= nullptr): next(s), l(ll){
    }
};
node_arhiva *prvi=nullptr;
node_arhiva *prvinovi=nullptr;
public:
    Arhiva()=default;
    Arhiva(const Arhiva& a) {
        node_arhiva* tek=a.prvi;
        node_arhiva* novi; node_arhiva* posl;
        while(tek){
            novi=new node_arhiva(tek->l);
            if(!prvi) prvi=novi;
            else posl=novi;
            tek=tek->next;
        }
    }
    Arhiva(Arhiva &&a){
        prvi=a.prvi;
        a.prvi=nullptr;
    }
    ~Arhiva() {
        node_arhiva *tek = prvi, *stari;
        while (tek) {
            stari = tek;
            tek = tek->next;
            delete stari;
        }
    }
    void dodajletove(let *lll){
        prvi=new node_arhiva(lll,prvi);
    }
    node_arhiva* dohvati_ime_polazista(string imee){
        for (node_arhiva* tek=prvi;tek;tek=tek->next){
            if(imee==tek->l->dohvati_polaziste()){
                prvinovi=new node_arhiva(tek->l,prvinovi);
            }
        }
        return prvinovi;
    }
    void IspisArhive(){
        cout<<"ARHIVA"<<endl;
        for(node_arhiva* tek=prvinovi;tek; tek=tek->next){
            tek->l->Ispis();
            cout<<endl;
        }
    }
};


#endif //VEZBANJEBATO_ARHIVA_H
