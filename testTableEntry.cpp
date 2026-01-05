#include <iostream>
#include "TableEntry.h"

int main() {
    TableEntry<int> a("uno", 1);
    TableEntry<int> b("uno", 999);   // misma key, distinto value
    TableEntry<int> c("dos", 2);
    TableEntry<int> d("tres");
    TableEntry<int> e;

    std::cout << a << "\n";
    std::cout << c << "\n";
    std::cout << d << "\n";
    std::cout << e << "\n";

    std::cout << std::boolalpha;
    std::cout << "(a == b) -> " << (a == b) << "\n"; // true (misma key)
    std::cout << "(a != c) -> " << (a != c) << "\n"; // true (key distinta)
    std::cout << "(a == c) -> " << (a == c) << "\n"; // false

    return 0;
}

