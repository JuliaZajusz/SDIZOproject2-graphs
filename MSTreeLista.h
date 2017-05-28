

#ifndef PROJEKT2_MSTREE_H
#define PROJEKT2_MSTREE_H


#include <iostream>
#include "MacierzIncydencji.h"
#include "ListaSasiedztwa.h"
#include "Edge.h"

using namespace std;



class MSTreeLista {
private:

    ElementListy ** A;            // Tablica list sąsiedztwa
   // ListaSasiedztwa A;
    int Alen;                     // Liczba komórek w tablicy
    int weight;                   // Waga całego drzewa
public:
    MSTreeLista(int n);
    ~MSTreeLista();
    void addEdge(Edge e);
    void print();
    MSTreeLista(ListaSasiedztwa *l, int alg);
    ElementListy * getAList(int n);
};












#endif //PROJEKT2_MSTREE_H
