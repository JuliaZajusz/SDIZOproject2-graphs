//
// Created by julia on 22.04.2017.
//

#ifndef PROJEKT2_MACIERZINCYDENCJI_H
#define PROJEKT2_MACIERZINCYDENCJI_H

#include <iostream>
#include <iomanip>
using namespace std;

class MacierzIncydencji {
    int lwierzcholkow,lkrawedzi;
    signed int ** tablica;

public:
    MacierzIncydencji();
    ~MacierzIncydencji();
    bool wczytaj(string nazwapliku);
    //void utworzlosowo (int lwierzcholkow, float gestosc);
    bool utworzlosowo (int lwierzcholkow, float gestosc);
    void wyswietl();
    int getLwierzcholkow() const;
    int getLkrawedzi() const;
    signed int ** getTablica();
    //bool czyGrafSpojny();
   void zapiszDoPliku(std::string nazwapliku, std::string tresc);
};


#endif //PROJEKT2_MACIERZINCYDENCJI_H
