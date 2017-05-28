//
// Created by julia on 25.04.2017.
//

#ifndef PROJEKT2_EGDE_H
#define PROJEKT2_EGDE_H

struct Edge {
    int v1,v2,weight;               // Wierzchołki krawędzi, waga krawędzi
};



// Definicja obiektu kolejki priorytetowej


class Queue {
private:
    Edge * Heap;
    int hpos;
public:
    Queue(int n);
    ~Queue();
    Edge front();
    void push(Edge e);
    void pop();
    int lpush=0;
    int lpop=0;
};





// Definicja obiektu struktury zbiorów rozłącznych
struct DSNode {
    int up,rank;
};

class DSStruct {
private:
    DSNode * Z;
public:
    DSStruct(int n);
    ~DSStruct();
    void MakeSet(int v);
    int FindSet(int v);
    void UnionSets(Edge e);
};





#endif //PROJEKT2_EGDE_H
