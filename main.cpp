#include <iostream>
#include <string>
#include "Piloti.h"
#include "Avion.h"
#include "FlotaAviona.h"
#include "Let.h"
#include "Arhiva.h"
using namespace std;

int main() {
    int id;
    id=rand();
avion a1(200, "Boeing 747"), a2(230, "Boeing 757"), a3(250, "Boeing 767");
flotaaviona f("PavleFlota");
let l("Beograd","Berlin",id,a2);
    let l2("Nis","Minhen",id,a1);
    let l3("Nis","Bukurest",id,a1);
Arhiva a;
/*pilot p1, p2;
p1.Unos();
p2.Unos();
a1.setkapetan(p1);
a1.setkopilot(p2);*/
f.dodajAvione(&a1);
f.dodajAvione(&a3);
f.dodajAvione(&a2);
//f.IzbaciAvion("Boeing 747");
f.pisi();
f.DohvatiAvione(210,260);
f.IspisDohvatiAvione();
l.Ispis();
l2.Ispis();
a.dodajletove(&l);
a.dodajletove(&l2);
    a.dodajletove(&l3);
a.dohvati_ime_polazista("Nis");
a.IspisArhive();
}