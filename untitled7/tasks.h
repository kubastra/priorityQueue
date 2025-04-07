#ifndef TASKS_H
#define TASKS_H

#include <iostream>

class Element {
    private:
      const std::string name;
      int priority;

    public:
    	explicit Element(std::string name) : name(name){
        	this->priority = name.length();
        }

    	int getPriority(){ return priority; }
		std::string getName(){ return name; }

		bool operator<(const Element &e) const{
        	return this->priority < e.priority;
        }

		bool operator>(const Element &e) const{
    		return this->priority > e.priority;
    	}

        bool operator==(const Element &e) const{
          return this->priority == e.priority && this->name == e.name;
        }

		friend std::ostream &operator<<(std::ostream &os, const Element &e) {
    		os << e.name << "(" << e.priority << ")" << std::endl;
    		return os;
    	}
};

#endif