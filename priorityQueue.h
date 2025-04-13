#ifndef PRIORITY_H
#define PRIORITY_H

#include "setLinked.h"
#include "element.h"

class priorityQueue {
private:
    setLinked<Element> elementy;

public:
    void insert(const Element &ele){
        elementy.insert(ele);
    }
    void print() const{
        elementy.print();
    }

    Element pop_min_priority() {
        return elementy.popFront();
    }
    bool isEmpty() const {
        return elementy.empty();
    }

};

#endif