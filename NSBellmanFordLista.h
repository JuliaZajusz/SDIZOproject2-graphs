//
// Created by julia on 09.05.2017.
//

#ifndef PROJEKT2_NSBELLMANFORDLISTA_H
#define PROJEKT2_NSBELLMANFORDLISTA_H


#include "ListaSasiedztwa.h"

class NSBellmanFordLista {

    int lkrawedzi,lwierzcholkow;                          // Liczba krawędzi i wierzchołków w grafie
    ElementListy ** A;                                    // Tablica dynamiczna list sąsiedztwa
    long long * tablicaKosztowDojscia;                    // Tablica kosztów dojścia
    int * tablicaPoprzednikow;                            // Tablica poprzedników
public:
    NSBellmanFordLista(ListaSasiedztwa *l, int vp, int vk);
    ~NSBellmanFordLista();
    bool BF(int v);
};


#endif //PROJEKT2_NSBELLMANFORDLISTA_H
