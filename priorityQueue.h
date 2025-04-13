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
        Element pierwszy = elementy.getFirst();
        elementy.usuwanie(pierwszy);
        return pierwszy;
    }

};

#endif