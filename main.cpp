#include "priorityQueue.h"
#include <chrono>
#include <fstream>

int ITERATIONS = 1000;
std::ofstream file("time.dat");

void insert_measure(priorityQueue pq, std::string element, int iteration) {
    auto begin = std::chrono::high_resolution_clock::now();
    pq.insert(Element(element));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    file << iteration << " " << duration << std::endl;
}

void test_1() {
    priorityQueue pq;
    pq.insert(Element("wow"));
    pq.insert(Element("priorityqueue"));
    pq.insert(Element("wo"));
    pq.print();
    std::cout << "po pop: " << std::endl;
    pq.pop_min_priority();
    pq.print();
}
void test_2() {
    priorityQueue pq;
    pq.insert(Element("aaa"));
    pq.insert(Element("www"));
    pq.insert(Element("a"));
    pq.insert(Element("w"));
    pq.print();
    std::cout << " Po pop: " << std::endl;
    pq.pop_min_priority();
    pq.print();
}

int main() {
    //test_2();
    //test_1();


    return 0;
}