//
// Created by julia on 23.04.2017.
//

#include "NajkrotszaSciezkaLista.h"

NajkrotszaSciezkaLista::NajkrotszaSciezkaLista(ListaSasiedztwa *l, int vp, int vk) {
    if(vp >= 0 && vp <lwierzcholkow && vk >=0 && vk <lwierzcholkow) {
        lwierzcholkow = l->getLwierzcholkow();
        //lkrawedzi=l.getLkrawedzi();
        wierzcholek = vp;
        tablicaKosztowDojscia = new int[lwierzcholkow];              // Tablica kosztów dojścia
        tablicaPoprzednikow = new int[lwierzcholkow];                // Tablica poprzedników
        QS = new bool[lwierzcholkow];                                // Zbiory Q i S   -true to S, false to Q
        graf = l->getTab();                                              // Tablica list sąsiedztwa
        S = new int[lwierzcholkow];                                  // Stos
        sptr = 0;                                                     // Wskaźnik stosu


        for (int i = 0; i < lwierzcholkow; i++) {
            tablicaKosztowDojscia[i] = 2147483647;
            tablicaPoprzednikow[i] = -1;
            QS[i] = false;
        }
        tablicaKosztowDojscia[wierzcholek] = 0;                       // Koszt dojścia v jest zerowy

        for (int i = 0; i < lwierzcholkow; i++) {
            int j;                                                    // Szukamy wierzchołka w Q o najmniejszym koszcie d
            for (j = 0; QS[j]; j++);                                  //j++
            for (wierzcholekU = j++; j < lwierzcholkow; j++) {
                if (!QS[j] && (tablicaKosztowDojscia[j] < tablicaKosztowDojscia[wierzcholekU])) {
                    wierzcholekU = j;
                }
            }
            QS[wierzcholekU] = true;                                                                                        // Znaleziony wierzchołek przenosimy do S

            for (pw = graf[wierzcholekU]; pw; pw = pw->nast) {                                                               // Modyfikujemy odpowiednio wszystkich sąsiadów u, którzy są w Q
                if (!QS[pw->v] &&
                    (tablicaKosztowDojscia[pw->v] > tablicaKosztowDojscia[wierzcholekU] + pw->wagaKrawedzi)) {
                    tablicaKosztowDojscia[pw->v] = tablicaKosztowDojscia[wierzcholekU] + pw->wagaKrawedzi;
                    tablicaPoprzednikow[pw->v] = wierzcholekU;
                }
            }
        }


        //wyswietlanie
        if (tablicaKosztowDojscia[vk] < 2000000000 && tablicaKosztowDojscia[vk] > -2000000000) {
            cout << "minimalny koszt dojscia z wierzcholka " << vp << " do wierzcholka " << vk
                 << " przez wierzcholki: ";
            for (int j = vk; j >
                             -1; j = tablicaPoprzednikow[j]) {                                                            // Ścieżkę przechodzimy od końca ku początkowi,
                S[sptr++] = j;                                                                                              // Zapisując na stosie kolejne wierzchołki
            }
            while (sptr) {                                                                                                   // Wyświetlamy ścieżkę, pobierając wierzchołki ze stosu
                cout << S[--sptr] << " ";
            }
            cout << "to: " << tablicaKosztowDojscia[vk]
                 << endl;                                                            // Na końcu ścieżki wypisujemy jej koszt
            cout << endl;
            for (int i = 0; i < lwierzcholkow; i++) {
                cout << "koszt dojscia do wierzcholka " << i << " " << tablicaKosztowDojscia[i] << endl;
            }
            cout << endl << endl << endl;
        } else {
            cout << "Nie ma polaczenia miedzy wierzcholkami." << endl;
        }
    } else {
        cout << "Blad! Nie ma takiego wierzcholka" << endl;
    }
}

NajkrotszaSciezkaLista::~NajkrotszaSciezkaLista() {
    delete [] tablicaKosztowDojscia;
    delete [] tablicaPoprzednikow;
    delete [] QS;
    delete [] S;

    for(int i = 0; i < lwierzcholkow; i++) {
        pw = graf[i];
        while(pw) {
            rw = pw;
            pw = pw->nast;
            delete rw;
        }
    }
    delete [] graf;
}
