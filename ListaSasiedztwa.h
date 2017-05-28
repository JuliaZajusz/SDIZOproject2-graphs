//
// Created by julia on 22.04.2017.
//

#ifndef PROJEKT2_LISTASASIEDZTWA_H
#define PROJEKT2_LISTASASIEDZTWA_H
#include <iostream>
#include "Edge.h"
using namespace std;

struct ElementListy{
    ElementListy * nast;
    int v;
    int wagaKrawedzi;
};
class ListaSasiedztwa {
private:
    int lwierzcholkow;
    int lkrawedzi;
    ElementListy **tab;


public:
    ListaSasiedztwa();
    ~ListaSasiedztwa();
    bool wczytaj(string nazwapliku);
    void utworzlosowo (signed int ** tmptab,int lwierzcholkow, float gestosc);
    void wyswietl();
    int getLwierzcholkow() const;
    int getLkrawedzi() const;
    ElementListy **getTab() const;



};


#endif //PROJEKT2_LISTASASIEDZTWA_H
