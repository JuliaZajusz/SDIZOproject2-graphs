//
// Created by julia on 04.05.2017.
//

#ifndef PROJEKT2_MSTREEMACIERZ_H
#define PROJEKT2_MSTREEMACIERZ_H
#include <iostream>
#include "MacierzIncydencji.h"
#include "Edge.h"

class MSTreeMacierz {
private:
    int **A;      // macierz incydencji
    //MacierzIncydencji M;
    int Alen;                     // Liczba komórek w tablicy
    int weight;                   // Waga całego drzewa
public:
    //int ** tablica1;
    int licznikK=0;
    bool *visited;
    MSTreeMacierz(int n);
    ~MSTreeMacierz();
    void addEdge(Edge e);
    void printMacierz();
    MSTreeMacierz(MacierzIncydencji *m, int alg);

};


#endif //PROJEKT2_MSTREEMACIERZ_H
