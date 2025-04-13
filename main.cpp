#include "priorityQueue.h"
#include <chrono>
#include <fstream>
#include <random>

int ITERATIONS = 10000;
std::ofstream file("time.dat");

void insert_measure(priorityQueue &pq, std::string element, int iteration) {
    auto begin = std::chrono::high_resolution_clock::now();
    pq.insert(Element(element));
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    file << iteration << " " << duration << std::endl;
}

void pop_min_measure(priorityQueue &pq, int iteration) {
    auto begin = std::chrono::high_resolution_clock::now();
    pq.pop_min_priority();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    file << iteration << " " << duration << std::endl;
}

std::string randomstringsize(int length) {
    std::string s;
    static const char charset[] =
    "abcdefghijklmnopqrstuwvxyz"
    "ABCDEFGHIJKLMNOPQRSTUWVXYZ";
    for (int i = 0; i < length; i++) {
        s += charset[rand() % (sizeof(charset) - 1)];
    }
    return s;
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

    priorityQueue pq;
    for (int i = 0; i < ITERATIONS; i++) {
        //pesymistyczna wersja
        std::string element(i + 10, 'a');
        insert_measure(pq, element, i);
    }

    file.close();
    std::cout << "Dane zapisane do time.dat" << std::endl;
    return 0;
}