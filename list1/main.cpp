#include "double_linked_list.h"
#include <iostream>

int main() {
    DoubleLinkedList<int> list;

    list.addAtFront(10);
    list.addAtFront(20);
    list.addAtEnd(30);

    std::cout << "List: ";
    list.print();

    std::cout << "Size: " << list.size() << std::endl;

    list.removeFromFront();
    std::cout << "After removing from front: ";
    list.print();

    list.removeFromEnd();
    std::cout << "After removing from end: ";
    list.print();

    std::cout << "Size: " << list.size() << std::endl;

    return 0;
}
