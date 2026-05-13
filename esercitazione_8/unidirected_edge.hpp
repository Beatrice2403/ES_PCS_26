#include <concepts> 
#include <iostream>
/*Dopo aver provato a far andare i test continuava a darmi errori, allora ho provato a 
far vedere cosa avevo scritto all'intelligenza artificiale, che mi ha suggerito di inserire 
#pragma once. Dopodichè cercando su internet ho scoperto che specifica che il compilatore include 
il file di intestazione una sola volta, durante la compilazione di un file di codice sorgente. 
Ha un effetto simile al linguaggio di inclusione guard , che usa le definizioni di macro del 
preprocessore per impedire più inclusioni del contenuto del file. Consente inoltre di evitare 
violazioni di una regola di definizione: il requisito che tutti i modelli, i tipi, le funzioni e 
gli oggetti non abbiano più di una definizione nel codice.*/ 
#pragma once 

template<typename I> 
class unidirected_edge
{
    I a;
    I b;

public:
    unidirected_edge(I x, I y) {
        if (x <= y) {
        a = x;
        b = y;
        } else {
        a = y;
        b = x;
        }
    }
    I from() const { return a; }
    I to() const { return b; }

    bool operator<(const unidirected_edge& other) const {
        if (from() < other.from()) return true;
        if (from() > other.from()) return false;
        return to() < other.to();
    }

    bool operator==(const unidirected_edge& other) const {
        return from() == other.from() && to() == other.to();
    }
    
};

template<typename I>
std::ostream& operator<<(std::ostream& os, const unidirected_edge<I>& e) {
    return os << "(" << e.from() << "," << e.to() << ")";
};