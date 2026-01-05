#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include <string>

#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict : public Dict<V> {
private:
    BSTree<TableEntry<V>>* tree;

public:
    BSTreeDict() : tree(new BSTree<TableEntry<V>>()) {}

    ~BSTreeDict() override {
        delete tree;
        tree = nullptr;
    }

    int entries() override {
        return tree->size();
    }

    void insert(std::string key, V value) override {
        tree->insert(TableEntry<V>(std::move(key), value));
    }

    V search(std::string key) override {
        TableEntry<V> found = tree->search(TableEntry<V>(std::move(key)));
        return found.value;
    }

    V remove(std::string key) override {
        TableEntry<V> found = tree->search(TableEntry<V>(key));
        tree->remove(TableEntry<V>(std::move(key)));
        return found.value;
    }

    V operator[](std::string key) {
        return search(std::move(key));
    }

    friend std::ostream& operator<<(std::ostream& out, const BSTreeDict<V>& d) {
        out << *(d.tree);
        return out;
    }
};

#endif

