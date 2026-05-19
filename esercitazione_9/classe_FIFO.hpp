#include <iostream>
#include <queue>
#pragma once


template<typename T>
class fifo {

    std::queue<T> q;

public:
    /*Costruttore di default*/
    fifo() = default;

    /*Implementazione put(), inserisce l'elemento*/
    void put(const T& x) {
        q.push(x);
    }

    /*Implementazione get(), estrae l'elemento*/
    T get() {
        T x = q.front();
        q.pop();
        return x;
    }

    /*Implementazione empty(), controlla se è vuoto*/
    bool empty() const {
        return q.empty();
    }
};