//
// Created by julia on 23.04.2017.
//

#ifndef PROJEKT2_NAJKROTSZASCIEZKA_H
#define PROJEKT2_NAJKROTSZASCIEZKA_H
#include "ListaSasiedztwa.h"

class NajkrotszaSciezkaLista {
private:
    //int lkrawedzi;
    int lwierzcholkow;
    int wierzcholek;
    int wierzcholekU;
    int sptr;
    int *tablicaKosztowDojscia;
    int *tablicaPoprzednikow;
    int *S;
    bool *QS;                       // Zbiory Q i S
    ElementListy **graf;            // Tablica list sąsiedztwa
    ElementListy *pw;
    ElementListy *rw;
public:
    NajkrotszaSciezkaLista(ListaSasiedztwa *l, int vp, int vk);
    ~NajkrotszaSciezkaLista();
};


#endif //PROJEKT2_NAJKROTSZASCIEZKA_H
