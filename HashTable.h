#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include <string>

#include "Dict.h"
#include "TableEntry.h"

// MODIFICA si tu ruta es distinta:
#include "../PRA_2526_P1/ListLinked.h"

template <typename V>
class HashTable : public Dict<V> {
private:
    int n;
    int max;
    ListLinked<TableEntry<V>>** table;  // array de punteros a listas

    int h(const std::string& key) const {
        int sum = 0;
        for (size_t i = 0; i < key.size(); ++i) sum += int(key.at(i));
        return sum % max;
    }

public:
    explicit HashTable(int size) : n(0), max(size), table(nullptr) {
        if (max <= 0) throw std::runtime_error("Invalid size");

        table = new ListLinked<TableEntry<V>>*[max];
        for (int i = 0; i < max; ++i) table[i] = new ListLinked<TableEntry<V>>();
    }

    ~HashTable() override {
        for (int i = 0; i < max; ++i) delete table[i];
        delete[] table;
    }

    int capacity() const { return max; }

    int entries() override { return n; }

    void insert(std::string key, V value) override {
        int idx = h(key);
        int pos = table[idx]->search(TableEntry<V>(key));
        if (pos != -1) throw std::runtime_error("Key already exists");

        table[idx]->prepend(TableEntry<V>(std::move(key), value));
        ++n;
    }

    V search(std::string key) override {
        int idx = h(key);
        int pos = table[idx]->search(TableEntry<V>(key));
        if (pos == -1) throw std::runtime_error("Key not found");

        return table[idx]->get(pos).value;
    }

    V remove(std::string key) override {
        int idx = h(key);
        int pos = table[idx]->search(TableEntry<V>(key));
        if (pos == -1) throw std::runtime_error("Key not found");

        TableEntry<V> te = table[idx]->remove(pos);
        --n;
        return te.value;
    }

    V operator[](std::string key) {
        return search(std::move(key));
    }

    friend std::ostream& operator<<(std::ostream& out, const HashTable<V>& ht) {
        for (int i = 0; i < ht.max; ++i) {
            out << i << ": ";
            if (ht.table[i]->size() == 0) {
                out << "NULL";
            } else {
                for (int j = 0; j < ht.table[i]->size(); ++j) {
                    out << ht.table[i]->get(j) << " -> ";
                }
                out << "NULL";
            }
            out << "\n";
        }
        return out;
    }
};

#endif

