//
// Created by julia on 22.04.2017.
//

#include "ListaSasiedztwa.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include <iomanip>

ListaSasiedztwa::ListaSasiedztwa() {
    lwierzcholkow=0;
    lkrawedzi=0;
    tab=new ElementListy *[0];
}

ListaSasiedztwa::~ListaSasiedztwa() {
    //cout<<"wywoluje sie destruktor listy"<<endl;
    delete [] tab;
}

bool ListaSasiedztwa::wczytaj(string nazwapliku) {
    ElementListy *p, *r;
    std::fstream plik;
    plik.open( nazwapliku.c_str() );
    if( !plik.good() ) {
        return false;
    }
    int tmpp, tmpk, tmpw;
    plik >> lkrawedzi>> lwierzcholkow;
    tab=new ElementListy* [lwierzcholkow];

    for(int i = 0; i < lwierzcholkow; i++) tab[i] = NULL;

    int i=0;
    while(i<lkrawedzi) //(true) pętla nieskończona
    {
        if( plik.good() ){
            plik>>tmpp>>tmpk>>tmpw;
            p=new ElementListy;
            p->v=tmpk;
            p->wagaKrawedzi=tmpw;
            p->nast=tab[tmpp];
            tab[tmpp]=p;
        }
        else {
            cout<<"Podana ilosc krawedzi w pliku nie zgadza sie z iloscia danych\n";
            break; //zakończ wczytywanie danych - wystąpił jakiś błąd (np. nie ma więcej danych w pliku)
        }
        i++;
    }
    plik.close();
    return true;
}

void ListaSasiedztwa::utworzlosowo(signed int ** tmptab, int lwierzcholkow, float gestosc) {
    ElementListy *p;
    int tmpp, tmpk, tmpw;
    this->lwierzcholkow= lwierzcholkow;
    lkrawedzi=floor((gestosc*(lwierzcholkow*(lwierzcholkow-1)))/2);

    tab=new ElementListy* [lwierzcholkow];

    for(int i = 0; i < lwierzcholkow; i++) tab[i] = NULL;

    for(int i=0;i<lwierzcholkow;i++){
        for(int j=0;j<lkrawedzi;j++){
            if(tmptab[i][j]>0){
                for(int k=0;k<lwierzcholkow;k++){
                    if(tmptab[k][j]==-1){
                        p=new ElementListy;
                        p->v=k;//tmpk
                        p->wagaKrawedzi=tmptab[i][j];
                        p->nast=tab[i]; //tab[tmpp]
                        tab[i]=p;
                        break;
                    }
                }

            }

        }
    }
}

void ListaSasiedztwa::wyswietl() {
    ElementListy *p;
    for(int i = 0; i < lwierzcholkow; i++) {
        cout << "wierzcholek " << i << " =";
        p = tab[i];
        while(p) {
            cout << setw(3) <<" waga:"<<p->wagaKrawedzi<<" "<< p->v;
            p = p->nast;
        }
        cout << endl;
    }
}

int ListaSasiedztwa::getLwierzcholkow() const {
    return lwierzcholkow;
}

int ListaSasiedztwa::getLkrawedzi() const {
    return lkrawedzi;
}

ElementListy **ListaSasiedztwa::getTab() const {
    return tab;
}



