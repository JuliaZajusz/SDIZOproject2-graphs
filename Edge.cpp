//
// Created by julia on 04.05.2017.
//

#include "Edge.h"
#include <iostream>
// Definicje metod obiektu Queue
//------------------------------

// Konstruktor - tworzy lwierzcholkow elementową tablicę heap na kopiec
//---------------------------------------------------------
Queue::Queue(int n)
{
    Heap = new Edge [n];            // Tworzymy tablicę
    hpos = 0;                       // Pozycja w kopcu

}

// Destruktor - usuwa kopiec z pamięci
//------------------------------------
Queue::~Queue()
{
    //std::cout<<lpush<<" "<<lpop<<std::endl;
   // std::cout<<"Wykonuje sie destruktor Queue"<<std::endl;
    delete [] Heap;
}

// Zwraca krawędź z początku kopca
//--------------------------------
Edge Queue::front()
{
    return Heap[0];
}



void Queue::push(Edge e) {          // Umieszcza w kopcu nową krawędź i odtwarza strukturę kopca
    long i,j;
    lpush++;

    i = hpos++;                     // i ustawiamy na koniec kopca
    j = (i - 1) >> 1;               // Obliczamy pozycję rodzica

    // Szukamy miejsca w kopcu dla e
    while(i && (Heap[j].weight > e.weight)) {
        Heap[i] = Heap[j];
        i = j;
        j = (i - 1) >> 1;
    }
    Heap[i] = e;                    // Krawędź e wstawiamy do kopca
}




void Queue::pop() {     // Usuwa korzeń z kopca i odtwarza jego strukturę
    int i,j;
    Edge e;
    lpop++;
    if(hpos) {
        e = Heap[--hpos];

        i = 0;
        j = 1;

        while(j < hpos) {
            if((j + 1 < hpos) && (Heap[j + 1].weight < Heap[j].weight)) j++;
            if(e.weight <= Heap[j].weight) break;
            Heap[i] = Heap[j];
            i = j;
            j = (j << 1) + 1;
        }

        Heap[i] = e;
    }
}







// Definicje metod obiektu DSStruct
//---------------------------------


DSStruct::DSStruct(int n) {         // Konstruktor
    Z = new DSNode [n];             // Tworzymy tablicę dla elementów zbiorów
}


DSStruct::~DSStruct() {             // Destruktor
    delete [] Z;                    // Usuwamy tablicę ze zbiorami
}


void DSStruct::MakeSet(int v) {     // Tworzy wpis w tablicy Z
    Z[v].up   = v;
    Z[v].rank = 0;
}



int DSStruct::FindSet(int v) {                    // Zwraca indeks reprezentanta zbioru, w którym jest wierzchołek v
    if(Z[v].up != v){
        Z[v].up = FindSet(Z[v].up);
    }
    return Z[v].up;
}


void DSStruct::UnionSets(Edge e) {   // Łączy ze sobą zbiory z v i u
    int ru,rv;

    ru = FindSet(e.v1);             // Wyznaczamy korzeń drzewa z węzłem u
    rv = FindSet(e.v2);             // Wyznaczamy korzeń drzewa z węzłem v
    if(ru != rv){                // Korzenie muszą być różne
        if(Z[ru].rank > Z[rv].rank) {  // Porównujemy rangi drzew
            Z[rv].up = ru;              // ru większe, dołączamy rv
        }else {
            Z[ru].up = rv;              // równe lub rv większe, dołączamy ru
            if(Z[ru].rank == Z[rv].rank) Z[rv].rank++;
        }
    }
}
