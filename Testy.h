//
// Created by julia on 13.05.2017.
//

#ifndef PROJEKT2_TESTY_H
#define PROJEKT2_TESTY_H

#include<conio.h>
#include<string>
#include<iostream>
#include <afxres.h>
#include <iomanip>
#include <fstream>
#include "MacierzIncydencji.h"
#include "ListaSasiedztwa.h"
#include "NajkrotszaSciezkaLista.h"
#include "NajkrotszaSciezkaMacierz.h"
#include "NSBellmanFordLista.h"
#include "NSBellmanFordMacierz.h"
#include "MSTreeMacierz.h"
#include "MSTreeLista.h"


class Testy{
public:
    long long int frequency, start, elapsed;
    float times;
    float timems;
    float timeus;
    MacierzIncydencji ttm;
    ListaSasiedztwa tl;
    NajkrotszaSciezkaLista * tsdl;
    NajkrotszaSciezkaMacierz * tsdm;
    NSBellmanFordLista * tsbfl;
    NSBellmanFordMacierz * tsbfm;
    MSTreeMacierz *dpm;
    MSTreeLista *dpl;
public:
    void ZachowajCzas();
    long long int read_QPC();
    void zapiszStatystykeDoPliku(std::string nazwapliku, float timeus);
    void zapiszDoPliku(std::string nazwapliku, std::string tresc);
    void statMST( std::string nazwaPliku);
    void statMSTKrusk( std::string nazwaPliku);
    void statDikstra(std::string nazwaPliku);
    void statFordBellman(std::string nazwaPliku);
};

/*extern long long int frequency, start, elapsed;
//extern float times;
//extern float timems;
extern float timeus;

extern void zachowajCzas();
//extern void statTworzenieTabeli();
extern long long int read_QPC();
extern void zapiszStatystykeDoPliku(std::string nazwapliku, float timeus);
extern void zapiszDoPliku(std::string nazwapliku, std::string tresc);

extern MacierzIncydencji ttm;
extern ListaSasiedztwa tl;
extern NajkrotszaSciezkaLista * tsdl;
extern NajkrotszaSciezkaMacierz * tsdm;
extern NSBellmanFordLista * tsbfl;
extern NSBellmanFordMacierz * tsbfm;
extern MSTreeMacierz *dpm;

void statMST( std::string nazwaPliku) {
 signed int ** ttmptab=new signed int* [0];
 float tmp = 0;

    for(int i=1; i<=4; i++) {                             //test dla 10 elementów
        int lw=10;
        int gestosc=i*25;
        zapiszDoPliku(nazwaPliku, "Test dla 10 elementow i gestosci "+gestosc);
        ttm.utworzlosowo(lw, gestosc);
        if (ttm.utworzlosowo(lw, gestosc) == false) {
            cout << "Graf nie jest spojny!"<<endl;
        } else {
            //cout << "Graf jest ok <3"<<endl;
            ttmptab = ttm.getTablica();
            tl.utworzlosowo(ttmptab, lw, gestosc);
        }
        for (int i = 0; i < 100; i++) {
            start = read_QPC();
            dpm = new MSTreeMacierz(&ttm, 2); //Prim macierzowo
            elapsed = read_QPC() - start;
            zachowajCzas();
            tmp += timeus;
        }
        tmp = tmp / 100;
        zapiszStatystykeDoPliku(nazwaPliku, tmp);
        tmp = 0;
    }





}*/






#endif //PROJEKT2_TESTY_H




