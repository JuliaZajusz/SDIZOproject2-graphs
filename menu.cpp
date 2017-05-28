//
// Created by julia on 22.04.2017.
//
// menu.cpp : Defines the entry point for the console application.
//


#include<conio.h>
#include<string>
#include<iostream>
#include <iomanip>
#include <windows.h>
#include <iomanip>
#include <afxres.h>
#include "MacierzIncydencji.h"
#include "ListaSasiedztwa.h"
#include "MSTreeLista.h"
#include "NajkrotszaSciezkaLista.h"
#include "NajkrotszaSciezkaMacierz.h"
#include "MSTreeMacierz.h"
#include "NSBellmanFordLista.h"
#include "NSBellmanFordMacierz.h"
#include "Testy.h"

using namespace std;


string nazwapliku;
MacierzIncydencji m;
ListaSasiedztwa l;
signed int ** tmptab=new signed int* [0];
NajkrotszaSciezkaLista * sdl;
NajkrotszaSciezkaMacierz * sdm;
NSBellmanFordLista * sbfl;
NSBellmanFordMacierz * sbfm;
int v;
Testy t;


int main(int argc, char* argv[])
{
    QueryPerformanceFrequency((LARGE_INTEGER *)&t.frequency);

    char option;
    do{
        cout << endl;
        cout << "==== MENU GLOWNE ===" << endl;

        cout << "1.Wczytaj graf z pliku" << endl;
        cout << "2.Wygeneruj graf losowo" << endl;
        cout << "3.Wyswiel listowo i macierzowo na ekranie" << endl;
        cout << "4.Algorytm Prima macierzowo i listowo z wyswietleniem wynikow" << endl;
        cout << "5.Algorytm Kruskala macierzowo i listowo z wyswietleniem wynikow" << endl;
        cout << "6.Wyznaczenie najkrotszej sciezki w grafie - algorytm Dijkstry" << endl;
        cout << "7.Wyznaczenie najkrotszej sciezki w grafie - algorytm Forda-Bellmana" << endl;
        cout << "8.Wyznaczenie maksymalnego przeplywu - algorytm Forda-Fulkersona" << endl;
        cout << "9.Testy"<<endl;
        cout << "0.Wyjscie" << endl;
        cout << "Podaj opcje:";
        option = getche();
        cout << endl;

        switch (option){
            case '1':
                cout << "Podaj nazwe pliku: " << endl;
                cin>>nazwapliku;
                m.wczytaj(nazwapliku);
                l.wczytaj(nazwapliku);
                break;

            case '2':
                int lw;
                float gestosc;
                cout << "Podaj liczbe wierzcholkow i gestosc (w zakresie od 0 do 1): " << endl;
                cin>>lw;
                cin>>gestosc;
                if(lw!=0) {
                    bool a=m.utworzlosowo(lw, gestosc);
                    if (a == false) {
                        cout << "Graf nie jest spojny!";
                    } else {
                        cout << "Graf jest ok <3";
                        tmptab = m.getTablica();
                        l.utworzlosowo(tmptab, lw, gestosc);
                    }
                }
                break;

            case '3':
                m.wyswietl();
                l.wyswietl();
                break;

            case '4': {
                MSTreeMacierz *tmp = new MSTreeMacierz(&m, 2);
                tmp->printMacierz();
                MSTreeLista *tlp = new MSTreeLista(&l, 2);
            }  break;

            case '5':{
                MSTreeMacierz * tmk=new MSTreeMacierz(&m,1);
                tmk->printMacierz();
                MSTreeLista * tlk=new MSTreeLista(&l,1);
            }
                break;
            case '6': {
                cout<<"algorytm Dijkstry- Podaj wierzcholek poczatkowy i koncowy: ";
                int vp, vk;
                cin>>vp>>vk;
                sdl=new NajkrotszaSciezkaLista(&l,vp,vk);
                sdm=new NajkrotszaSciezkaMacierz(&m,vp,vk);
            }  break;
            case '7': {
                cout<<"algorytm Forda-Bellmana- Podaj wierzcholek poczatkowy i koncowy: ";
                int vp, vk;
                cin>>vp>>vk;
                sbfl=new NSBellmanFordLista(&l,vp,vk);
                sbfm=new NSBellmanFordMacierz(&m,vp,vk);
            }  break;
            case '8': {

            }  break;
            case '9': {
                //t.statMST( "statystykiPrimMacierzowo.txt");
                //t.statMSTKrusk( "statystykiKruskalMacierzowo.txt");
                //t.statDikstra( "statystykiDikstraMacierzowo.txt");
                //t.statFordBellman("statystykiFBMacierzowo.txt");
            }  break;
        }

    } while (option != '0');


    return 0;
}


