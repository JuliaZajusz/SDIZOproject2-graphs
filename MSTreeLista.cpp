//
// Created by julia on 09.04.2017.
//

#include "MSTreeLista.h"


MSTreeLista::MSTreeLista(int n) {             // Konstruktor - tworzy tablicę pustych list sąsiedztwa
    A=new ElementListy * [n];                 // Tworzymy tablicę dynamiczną
    for(int i = 0; i < n; i++) {              // i wypełniamy ją pustymi listami
        A[i] = NULL;
    }
    Alen = n - 1;                   // Zapamiętujemy długość tablicy
    weight = 0;                     // Zerujemy wagę drzewa
}




MSTreeLista::~MSTreeLista() {                 // Destruktor - usuwa listy oraz tablicę sąsiedztwa
    //cout<<"\nWykonuje sie destruktor drzewa listowego\n";
    ElementListy *p, *r;
    for(int i = 0; i <= Alen; i++) {
        p = A[i];
        while(p) {
            r = p;                      // Zapamiętujemy wskazanie
            p = p->nast;                // Przesuwamy się do następnego elementu listy
            delete r;                   // Usuwamy element
        }
    }
    delete [] A;                    // Usuwamy tablicę list sąsiedztwa
}


ElementListy *MSTreeLista::getAList(int n) {
    return A[n];
}

void MSTreeLista::addEdge(Edge e) {      // Dodaje krawędź do drzewa
    ElementListy *p;
    weight += e.weight;             // Do wagi drzewa dodajemy wagę krawędzi
    p = new ElementListy;                  // Tworzymy nowy węzeł
    p->v = e.v2;                    // Wierzchołek końcowy
    p->wagaKrawedzi = e.weight;           // Waga krawędzi
    p->nast = A[e.v1];              // Dodajemy p do listy wierzchołka v1
    A[e.v1] = p;

    p = new ElementListy;                  // To samo dla krawędzi odwrotnej
    p->v = e.v1;                    // Wierzchołek końcowy
    p->wagaKrawedzi = e.weight;           // Waga krawędzi
    p->nast = A[e.v2];              // Dodajemy p do listy wierzchołka v2
    A[e.v2] = p;
}



void MSTreeLista::print() {              // Wyświetla zawartość drzewa oraz jego wagę
    ElementListy *p;

    cout << endl;
    for(int i = 0; i <= Alen; i++) {
        cout << "Wierzcholek " << i << " - ";
        for(p = A[i]; p; p = p->nast) {
            cout<< " waga:" << p->wagaKrawedzi<<" do wierzcholka " << p->v<<";";
        }
        cout << endl;
    }
    cout << endl << endl << "Waga minimalnego drzewa rozpinajacego = " << weight << endl << endl;
}





MSTreeLista::MSTreeLista(ListaSasiedztwa *l, int alg) {
    if(alg==1) {                                //MSTreeLista algorytmem Kruska z listy
        int lwGrafu = l->getLwierzcholkow();
        int lkGrafu = l->getLkrawedzi();
        Edge e;
        DSStruct Z(lwGrafu);
        Queue Q(lkGrafu);
        MSTreeLista T(lwGrafu);
        ElementListy **tab = l->getTab();
        ElementListy *p;

        for (int i = 0; i < lwGrafu; i++) {
            Z.MakeSet(i);
        }

        for (int j = 0; j < lwGrafu; j++) {
            p=tab[j];
            while (p) {
                e.v1 = j;
                e.v2 = p->v;
                e.weight = p->wagaKrawedzi;
                Q.push(e);
                p = p->nast;
            }
        }

        for (int i = 1; i < lwGrafu; i++) {          // Pętla wykonuje się n - 1 razy !!!
            do {
                e = Q.front();              // Pobieramy z kolejki krawędź
                Q.pop();                    // Krawędź usuwamy z kolejki
            } while (Z.FindSet(e.v1) == Z.FindSet(e.v2));
            T.addEdge(e);                 // Dodajemy krawędź do drzewa
            Z.UnionSets(e);               // Zbiory z wierzchołkami łączymy ze sobą
        }
        T.print();
    }




    else if(alg==2){                               //MSTreeLista algorytmem Prima z listy
        int lwGrafu = l->getLwierzcholkow();
        int lkGrafu = l->getLkrawedzi();
        Edge e;
        //WezelDrzewa *p;  //TNode * p;
        ElementListy *p;
        Queue Q(lkGrafu);
        MSTreeLista T(lwGrafu);
        MSTreeLista G(lwGrafu);
        bool * visited = new bool [lwGrafu];
        ElementListy * tmpW;
        ElementListy **tab = l->getTab();

        for(int i = 0; i < lwGrafu; i++) {
            visited[i] = false;
        }

        for (int j = 0; j < lwGrafu; j++) {
            tmpW = tab[j];
            while (tmpW) {
                e.v1 = j;
                e.v2 = tmpW->v;
                e.weight = tmpW->wagaKrawedzi;
                G.addEdge(e);
                tmpW = tmpW->nast;
            }
        }
        int v = 0;                          // Wierzchołek startowy
        visited[v] = true;              // Oznaczamy go jako odwiedzonego

        for(int i = 1; i < lwGrafu; i++) {         // Do drzewa dodamy n - 1 krawędzi grafu
            for(p = G.getAList(v); p; p = p->nast) { // Przeglądamy listę sąsiadów
                if (!visited[p->v]) {         // Jeśli sąsiad jest nieodwiedzony,
                    e.v1 = v;                 // to tworzymy krawędź
                    e.v2 = p->v;
                    e.weight = p->wagaKrawedzi;
                    Q.push(e);                // Dodajemy ją do kolejki priorytetowej
                }
            }
            do {
                e = Q.front();              // Pobieramy krawędź z kolejki
                Q.pop();
            } while(visited[e.v2]);       // Krawędź prowadzi poza drzewo?

            T.addEdge(e);                 // Dodajemy krawędź do drzewa rozpinającego
            visited[e.v2] = true;         // Oznaczamy drugi wierzchołek jako odwiedzony
            v = e.v2;
        }

        // Wyświetlamy wyniki

        T.print();

        delete [] visited;
    }
}








