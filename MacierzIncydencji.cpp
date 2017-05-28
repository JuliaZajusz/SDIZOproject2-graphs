//
// Created by julia on 22.04.2017.
//

#include "MacierzIncydencji.h"
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>
#include <sstream>

MacierzIncydencji::MacierzIncydencji() {
    lwierzcholkow=0;
    lkrawedzi=0;
    tablica=new signed int *[0];
}

MacierzIncydencji::~MacierzIncydencji() {
    //cout << "Wywoluje sie destruktor!!!!!!" << endl;
    for(int i = 0; i < lwierzcholkow; i++) {
        delete [] tablica[i];
    }
    delete [] tablica;
}



bool MacierzIncydencji::wczytaj(string nazwapliku) {
    std::fstream plik;
    plik.open( nazwapliku.c_str() );
    if( !plik.good() ) {
        return false;
    }
    int i=0;
    int j=0;
    int tmpp, tmpk, tmpw;
    plik >> lkrawedzi>> lwierzcholkow;
    tablica=new signed int* [lwierzcholkow];
    for(i = 0; i < lwierzcholkow; i++) {
        tablica[i] = new signed int[lkrawedzi]; // Tworzymy wiersze
    }


    for(i = 0; i < lwierzcholkow; i++) {       // Macierz wypełniamy zerami
        for (j = 0; j < lkrawedzi; j++) {
            tablica[i][j] = 0;
        }
    }
    i=0;
    while(i<lkrawedzi) //(true) pętla nieskończona
    {
        if( plik.good() ){
            plik>>tmpp>>tmpk>>tmpw;
            tablica[tmpp][i]=tmpw; //<--
            tablica[tmpk][i]=-1;
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


void MacierzIncydencji::zapiszDoPliku(std::string nazwapliku, std::string tresc) {
    std::ofstream plik;
    plik.open(nazwapliku, std::ios_base::out);
    plik << tresc;
    plik.close();
}
bool MacierzIncydencji::utworzlosowo(int lwierzcholkow, float gestosc) {
    string dopliku;
    ostringstream ss;
    srand(time(NULL));      //czemu nie wymaga biblioteki ctime?!!!
    int tmp2;
    this->lwierzcholkow = lwierzcholkow;
    lkrawedzi = floor((gestosc * (lwierzcholkow * (lwierzcholkow - 1))) / 2);
    if(lkrawedzi<lwierzcholkow-1){
        return false;
    }else {
        ss << lkrawedzi<<" "<<lwierzcholkow<<"\n";
        tablica = new signed int *[lwierzcholkow];
        for (int i = 0; i < lwierzcholkow; i++) {
            tablica[i] = new signed int[lkrawedzi]; // Tworzymy wiersze
        }
        for (int i = 0; i < lwierzcholkow; i++) {       // Macierz wypełniamy zerami
            for (int j = 0; j < lkrawedzi; j++) {
                tablica[i][j] = 0;
            }
        }
        if(lkrawedzi>0) {
            tablica[0][0] = 1;//tablica[0][0] = -1;
        }
        for (int i = 0; i < (lwierzcholkow-1); i++) {       // podstawowe krawedzie
            tablica[i + 1][i] = -1;//tablica[i + 1][i] = i + 1;
            if (i > 0) {
                tmp2 = rand() % (i+1);
                tablica[tmp2][i] =rand()%(100);//tablica[tmp2][i] = i+1;

            }

            ss << tmp2<<" ";
            ss << i+1<<" ";
            ss << tablica[tmp2][i]<<"\n";
            //dopliku=dopliku+ss.str();
        }


        for (int i = lwierzcholkow - 1; i < lkrawedzi; i++) { //nadprogramowe krawedzie
            int tmp = rand() % lwierzcholkow;
            tablica[tmp][i] = rand()%(100);//(i + 1);
            int tmp1 = rand() % lwierzcholkow;
            while (tmp1 == tmp) {
                tmp1 = rand() % lwierzcholkow;
            }
            tablica[tmp1][i] = -1;
            ss << tmp<<" ";
            ss << tmp1<<" ";
            ss << tablica[tmp][i]<<"\n";
            //dopliku=dopliku+ss.str();
        }
        dopliku=ss.str();
        //cout<<dopliku;
        zapiszDoPliku("graf4.txt",dopliku);
        return true;
    }
}




signed int **MacierzIncydencji::getTablica() {
    return tablica;
}


void MacierzIncydencji::wyswietl() {
                                                                //wyswietlenie macierzy incydencji grafu;
    cout <<endl<< "   ";
    for(int i = 0; i < lkrawedzi; i++) {
        cout << setw(3) << i;
    }
    cout << endl << endl;
    for(int i = 0; i < lwierzcholkow; i++) {
        cout << setw(3) << i;
        for(int j = 0; j < lkrawedzi; j++) {
            cout << setw(3) << tablica[i][j];
        }
        cout << endl;
    }
    cout << endl;
}



int MacierzIncydencji::getLwierzcholkow() const {
    return lwierzcholkow;
}

int MacierzIncydencji::getLkrawedzi() const {
    return lkrawedzi;
}
