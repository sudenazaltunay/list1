
#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H

#include <iostream>

template <typename T>
class DoubleLinkedList {
private:
    struct Node {
        T data;
        Node* prev;
        Node* next;

        Node(T value) : data(value), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    int listSize;

public:
    DoubleLinkedList() : head(nullptr), tail(nullptr), listSize(0) {}

    ~DoubleLinkedList() {
        while (head) {
            removeFromFront();
        }
    }

    void addAtFront(T value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        listSize++;
    }

    void addAtEnd(T value) {
        Node* newNode = new Node(value);
        if (!tail) {
            head = tail = newNode;
        }
        else {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        listSize++;
    }

    void removeFromFront() {
        if (!head) return; 
        Node* temp = head;
        if (head == tail) { 
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        listSize--;
    }

    void removeFromEnd() {
        if (!tail) return; 
        Node* temp = tail;
        if (head == tail) { 
            head = tail = nullptr;
        }
        else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        listSize--;
    }

    void print() const {
        Node* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    int size() const {
        return listSize;
    }
};

#endif // DOUBLE_LINKED_LIST_H
