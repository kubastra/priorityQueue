#ifndef SETLINKED_H
#define SETLINKED_H

#include <iostream>

template<class T>
class setLinked {
private:
    struct Node {
        T value;
        Node *next;
        Node(T val, Node *next = nullptr) : value(val), next(next) {}
    };

    Node *head;

public:
    setLinked() {
        head = nullptr;
    }
    setLinked(const setLinked &other) : head(nullptr) {
        Node* current = other.head;
        while (current) {
            insert(current->value);
            current = current->next;
        }
    }

    setLinked &operator=(const setLinked &other) {
        if (this == &other) return *this;
        // najpierw usuń stare dane
        while (!empty()) {
            popFront();
        }
        Node* current = other.head;
        while (current) {
            insert(current->value);
            current = current->next;
        }
        return *this;
    }

    void insert(T x) {
        if (head == nullptr) {
            head = new Node(x, nullptr);
            return;
        }

        if (x < head->value) {
            head = new Node(x, head);
            return;
        }

        if (x == head->value) return;

        Node *current = head;
        while (current -> next != nullptr && current->next->value < x) {
            current = current->next;
        }

        if ( current->next == nullptr || current->next->value != x ) {
            current->next = new Node(x, current->next);
        }
    }

    bool zawieranie(T x) {
        if (head == nullptr || head->value > x) return false;

        if (head -> value == x) return true;

        Node *current = head;
        while (current -> next != nullptr && current->next->value < x) {
            current = current->next;
        }

        if (current->next == nullptr || current->next->value != x) {
            return false;
        }
        return true;
    }

    void usuwanie(T x) {
        if (head == nullptr || head -> value > x ) return;
        if (head -> value == x) {
            Node *temp = head;
            head = head -> next;
            delete temp;
            return;
        }
        Node* current = head;
        while (current -> next != nullptr && current->next->value < x) {
            current = current -> next;
        }
        if (current -> next != nullptr && current->next->value == x) {
            Node *temp = current -> next;
            current -> next = temp ->next;
            delete temp;
            return;
        }
    }

    T popFront() {
        if (!head) throw std::runtime_error("Empty list");
        Node* temp = head;
        T value = head->value;
        head = head->next;
        delete temp;
        return value;
    }

    void print() const {
        Node* current = head;
        std::cout << "Zawartosc listy:" << std::endl;
        while (current != nullptr) {
            std::cout << current->value;
            current = current->next;
        }
        std::cout << std::endl;
    }
    bool empty() const {
        return head == nullptr;
    }
};


#endif