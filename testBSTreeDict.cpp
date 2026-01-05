#include <iostream>
#include "BSTreeDict.h"

int main() {
    BSTreeDict<int> d;

    d.insert("c", 3);
    d.insert("a", 1);
    d.insert("b", 2);

    std::cout << "Dict inorder by key: " << d << "\n";
    std::cout << "entries: " << d.entries() << "\n";
    std::cout << "search(a): " << d.search("a") << "\n";
    std::cout << "operator[](b): " << d["b"] << "\n";
    std::cout << "remove(c): " << d.remove("c") << "\n";
    std::cout << "entries: " << d.entries() << "\n";

    try {
        d.search("c");
        std::cout << "ERROR: debería fallar search(c)\n";
    } catch (const std::runtime_error& e) {
        std::cout << "OK error: " << e.what() << "\n";
    }
    return 0;
}

