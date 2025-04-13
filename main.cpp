#include "priorityQueue.h"
#include <chrono>
#include <fstream>
#include <random>
#include <iostream>

std::ofstream file("time.dat");
std::ofstream file2("time2.dat");

long long measure_insert_time(priorityQueue &pq, Element &ele) {
    auto begin = std::chrono::high_resolution_clock::now();
    pq.insert(ele);
    auto end = std::chrono::high_resolution_clock::now();
    long long total_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    return total_duration;
}

long long pop_min_measure(priorityQueue &pq) {
    if (pq.isEmpty()) {
        return 0;
    }
    auto begin = std::chrono::high_resolution_clock::now();
    pq.pop_min_priority();
    auto end = std::chrono::high_resolution_clock::now();
    long long total_duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count();
    return total_duration;
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

void run_insert_time_tests() {
    int ITERATIONS = 10000;
    priorityQueue pq;
    priorityQueue pq2;
    std::string napis = "";
    long long dur, p1, p2;
    for (int i = 1; i < ITERATIONS; i++) {
        napis += "a";
        Element el = Element(napis);
        p1 = measure_insert_time(pq, el);
        p2 = measure_insert_time(pq2, el);
        dur = (p1 + p2) / 2;

        file << i << " " << dur << std::endl;
    }
}

void run_pop_time_tests() {
    int REPEATS = 3;
    for (int size = 1; size <= 1000; size++) {
        priorityQueue pq;
        for (int i = 0; i < size; i++) {
            pq.insert(Element(std::string(i + 1, 'a')));
        }
        long long total = 0;
        for (int rep = 0; rep < REPEATS; rep++) {
            priorityQueue copy = pq;
            total += pop_min_measure(copy);
        }
        file2 << size << " " << (total / REPEATS) << std::endl;
    }
}

int main() {
    int choice;
    bool running = true;

    while (running) {
        std::cout << "\nWybierz opcje:\n";
        std::cout << "1. Uruchom test wstawiania\n";
        std::cout << "2. Uruchom test usuwania minimalnego\n";
        std::cout << "3. Uruchom testy (test 1)\n";
        std::cout << "4. Uruchom testy (test 2)\n";
        std::cout << "5. Zakoncz\n";
        std::cout << "Wybor: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                run_insert_time_tests();
                std::cout << "Test wstawiania zakończony.\n";
                break;
            case 2:
                run_pop_time_tests();
                std::cout << "Test usuwania minimalnego zakończony.\n";
                break;
            case 3:
                test_1();
                break;
            case 4:
                test_2();
                break;
            case 5:
                running = false;
                std::cout << "Zakończenie programu.\n";
                break;
            default:
                std::cout << "Nieprawidłowy wybór. Spróbuj ponownie.\n";
                break;
        }
    }

    file.close();
    file2.close();
    return 0;
}
