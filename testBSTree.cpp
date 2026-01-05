#include <iostream>
#include "BSTree.h"

int main() {
    BSTree<int> bst;

    bst.insert(8);
    bst.insert(3);
    bst.insert(10);
    bst.insert(1);
    bst.insert(6);
    bst.insert(14);
    bst.insert(4);
    bst.insert(7);
    bst.insert(13);

    std::cout << "BST inorder: " << bst << "\n";
    std::cout << "size: " << bst.size() << "\n";

    std::cout << "search(6): " << bst.search(6) << "\n";
    std::cout << "operator: " << bst[7] << "\n";

    bst.remove(3);  // caso típico: tiene dos hijos en este árbol
    std::cout << "after remove(3): " << bst << "\n";
    std::cout << "size: " << bst.size() << "\n";

    try {
        bst.search(3);
        std::cout << "ERROR: debería haber fallado search(3)\n";
    } catch (const std::runtime_error& e) {
        std::cout << "OK error: " << e.what() << "\n";
    }

    return 0;
}

