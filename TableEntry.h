#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include <string>
#include <ostream>

template <typename V>
class TableEntry {
public:
    std::string key;
    V value;

    
    TableEntry(std::string key, V value) : key(std::move(key)), value(value) {}

    
    explicit TableEntry(std::string key) : key(std::move(key)), value(V()) {}

    
    TableEntry() : key(""), value(V()) {}

    
    friend bool operator==(const TableEntry<V>& a, const TableEntry<V>& b) {
        return a.key == b.key;
    }

    friend bool operator!=(const TableEntry<V>& a, const TableEntry<V>& b) {
        return !(a == b);
    }

    
    friend bool operator<(const TableEntry<V>& a, const TableEntry<V>& b) {
        return a.key < b.key;
    }

    friend bool operator>(const TableEntry<V>& a, const TableEntry<V>& b) {
        return a.key > b.key;
    }

    
    friend std::ostream& operator<<(std::ostream& out, const TableEntry<V>& te) {
        out << "{" << te.key << " : " << te.value << "}";
        return out;
    }
};

#endif

