#include <iostream>
#include <string>
#include "Piloti.h"
#include "Avion.h"
using namespace std;
#ifndef _flotaaviona_h_
#define _flotaaviona_h_


class flotaaviona {
struct node{
    avion* plane;
    node* next;
    node(avion* av, node* s= nullptr): next(s), plane(av){
    }
};
node *prvi=nullptr;
node *prvinovi=nullptr;
string ime;
int uk=0, max=0, maxputnika;
avion* amax;
public:
    flotaaviona()=default;
    flotaaviona(const flotaaviona& f) {
        uk=f.uk;
        max=f.max;
        node* tek=f.prvi;
        node* novi; node* posl;
        while(tek){
            novi=new node(tek->plane);
            if(!prvi) prvi=novi;
            else posl=novi;
            tek=tek->next;
        }
    };
    flotaaviona(flotaaviona &&f){
        uk=f.uk;
        max=f.max;
        prvi=f.prvi;
        f.prvi=nullptr;
    };
    ~flotaaviona(){
        node* tek=prvi, *stari;
        while (tek){
            stari=tek;
            tek=tek->next;
            delete stari;
        }
    };
    flotaaviona(string i){
        ime=i;
    }
    void dodajAvione(avion *a){
        prvi=new node(a,prvi);
        uk++;
        max=max+a->dohvKap();
    };
    avion NajveciAvion(){
        int kap1, kap2;
        for(node* tek=prvi; tek; tek=tek->next){
            for (node* tek2=tek;tek2 ;tek2=tek2->next){
                kap2=tek2->plane->dohvKap();
                kap1=tek->plane->dohvKap();
                if (kap2>kap1){
                    amax= tek2->plane;
                }
            }
        }
        return *amax;
    }
    void pisi(){
        cout<<ime<<" "<<"kapacitet je: "<<max<<" u floti ima toliko aviona: "<<uk;
        for(node* tek=prvi;tek; tek=tek->next){
            cout<<endl;
            tek->plane->Ispis();
        }
        cout<<endl<<"najveci avion je"<<endl;
        *amax=NajveciAvion();
        amax->Ispis();
    }
    int BrojAviona()const {return uk;}
    int Kapacitet()const{return max;}
    void IzbaciAvion(string name){
        node *q;
        for(node* tek=prvi; tek; tek=tek->next){
            if (name==tek->next->plane->dohvIme()){
                tek->next=tek->next->next;
                q=tek->next;
                delete(q);
            }
        }
    }
    node* DohvatiAvione(int min, int maks){
        for(node* tek=prvi; tek; tek=tek->next){
            if(tek->plane->dohvKap()>min and tek->plane->dohvKap()<maks){
                prvinovi=new node(tek->plane,prvinovi);
            }
        }
        return prvinovi;
    }
    void IspisDohvatiAvione(){
        cout<<"dovati avione su "<<endl;
        for(node* tek=prvinovi;tek; tek=tek->next){
            cout<<endl;
            tek->plane->Ispis();
        }
    }
};


#endif //VEZBANJEBATO_FLOTAAVIONA_H
