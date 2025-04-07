#ifndef TASKS_H
#define TASKS_H

#include <iostream>

class Task {
    private:
      std::string name;
      int priority;

    public:
       Task(std::string name) : name(name){
           this->priority = name.length();
       }

};

#endif