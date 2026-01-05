#include <iostream>
#include "HashTable.h"

int main() {
    HashTable<int> ht(7);

    ht.insert("uno", 1);
    ht.insert("dos", 2);
    ht.insert("tres", 3);

    std::cout << ht;
    std::cout << "search(uno)=" << ht.search("uno") << "\n";
    std::cout << "remove(dos)=" << ht.remove("dos") << "\n";
    std::cout << "entries=" << ht.entries() << "\n";

    try {
        ht.search("dos");
    } catch (const std::runtime_error& e) {
        std::cout << "OK error: " << e.what() << "\n";
    }
    return 0;
}

