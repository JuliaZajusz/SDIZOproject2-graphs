//
// Created by julia on 09.05.2017.
//

#include "NSBellmanFordLista.h"


NSBellmanFordLista::NSBellmanFordLista(ListaSasiedztwa *l, int vp, int vk) {
    if(vp >= 0 && vp <lwierzcholkow && vk >=0 && vk <lwierzcholkow) {
        int sptr;
        int *S;
        lwierzcholkow = l->getLwierzcholkow();
        lkrawedzi = l->getLkrawedzi();
        A = l->getTab();                                                  // Tworzymy tablicę list sąsiedztwa
        tablicaKosztowDojscia = new long long[lwierzcholkow];          // Tworzymy tablicę kosztów dojścia
        tablicaPoprzednikow = new int[lwierzcholkow];                  // Tworzymy tablice poprzedników
        for (int i = 0; i < lwierzcholkow; i++) {                       // Inicjujemy struktury danych
            tablicaKosztowDojscia[i] = 2147483647;
            tablicaPoprzednikow[i] = -1;
        }


        cout << endl;
        // Wyznaczamy najkrótsze ścieżki algorytmem Bellmana-Forda

        if (BF(vp)) {
            S = new int[lwierzcholkow];                                     // Tworzymy prosty stos
            sptr = 0;
            if (tablicaKosztowDojscia[vk] < 2000000000 && tablicaKosztowDojscia[vk] > -2000000000) {
                cout << "minimalny koszt dojscia z wierzcholka " << vp << " do wierzcholka " << vk
                     << " przez wierzcholki: ";
                for (int j = vk; j !=
                                 -1; j = tablicaPoprzednikow[j]) {                                                           // Ścieżkę przechodzimy od końca ku początkowi,
                    S[sptr++] = j;                                                                                              // Zapisując na stosie kolejne wierzchołki
                }
                while (sptr) {                                                                                                   // Wierzchołki ze stosu drukujemy
                    cout << S[--sptr]
                         << " ";                                                                                   // w kolejności od pierwszego do ostatniego
                }
                cout << " to: " << tablicaKosztowDojscia[vk] << endl;

                for (int i = 0; i < lwierzcholkow; i++) {
                    cout << "koszt dojscia do wierzcholka " << i << " to " << tablicaKosztowDojscia[i] << endl;
                }
                cout << endl << endl << endl;
            } else {
                cout << "Nie ma polaczenia miedzy wierzcholkami." << endl;
            }


            delete[] S;                  // Usuwamy stos
        } else cout << "Znaleziono cykl ujemny" << endl;
    } else {
        cout << "Blad! Nie ma takiego wierzcholka" << endl;
    }
}






bool NSBellmanFordLista::BF(int v) {
    bool test;
    ElementListy * pv;

    tablicaKosztowDojscia[v] = 0;                                                                     // Zerujemy koszt dojścia do v
    for(int i = 1; i < lwierzcholkow; i++){                                                               // Pętla relaksacji
        test = true;                                                                                  // Oznacza, że algorytm nie wprowadził zmian do d i p
        for(int x = 0; x < lwierzcholkow; x++) {                                                           // Przechodzimy przez kolejne wierzchołki grafu
            for (pv = A[x]; pv; pv = pv->nast) {                                                       // Przeglądamy listę sąsiadów wierzchołka x
                if (tablicaKosztowDojscia[pv->v] > tablicaKosztowDojscia[x] + pv->wagaKrawedzi) {      // Sprawdzamy warunek relaksacji
                    test = false;                                                                     // Jest zmiana w d i p
                    tablicaKosztowDojscia[pv->v] = tablicaKosztowDojscia[x] + pv->wagaKrawedzi;       // Relaksujemy krawędź z x do jego sąsiada
                    tablicaPoprzednikow[pv->v] = x;                                                   // Poprzednikiem sąsiada będzie x
                }
            }
        }
        if(test) {
            return true;
        }                                                                         // Jeśli nie było zmian, to kończymy
    }

    // Sprawdzamy istnienie ujemnego cyklu

    for(int x = 0; x < lwierzcholkow; x++) {
        for (pv = A[x]; pv; pv = pv->nast) {
            if (tablicaKosztowDojscia[pv->v] > tablicaKosztowDojscia[x] + pv->wagaKrawedzi) {
                return false; // ujemny cykl!!
            }
        }
    }
    return true;
}







NSBellmanFordLista::~NSBellmanFordLista() {
    ElementListy *pv,* rv;
    for(int i = 0; i < lwierzcholkow; i++) {
        pv = A[i];
        while(pv) {
            rv = pv;
            pv = pv->nast;
            delete rv;
        }
    }
    delete [] A;
    delete [] tablicaKosztowDojscia;
    delete [] tablicaPoprzednikow;
}
