#include "newmap.h"
#include <iostream>

Map::Map() : m_size(0), m_capacity(DEFAULT_MAX_ITEMS) {
    m_data = new Pair[m_capacity];
}

Map::Map(int capacity) : m_size(0), m_capacity(capacity) {
    if (capacity < 0)
        m_capacity = DEFAULT_MAX_ITEMS;
    m_data = new Pair[m_capacity];
}

Map::Map(const Map& other) : m_size(other.m_size), m_capacity(other.m_capacity) {
    m_data = new Pair[m_capacity];
    for (int i = 0; i < m_size; i++)
        m_data[i] = other.m_data[i];
}

Map& Map::operator=(const Map& other) {
    if (this != &other) {
        delete[] m_data;
        m_capacity = other.m_capacity;
        m_size = other.m_size;
        m_data = new Pair[m_capacity];
        for (int i = 0; i < m_size; i++)
            m_data[i] = other.m_data[i];
    }
    return *this;
}

Map::~Map() {
    delete[] m_data;
}

bool Map::empty() const {
    return m_size == 0;
}

int Map::size() const {
    return m_size;
}

bool Map::insert(const std::string& key, const double& value) {
    if (m_size >= m_capacity || contains(key))
        return false;
    m_data[m_size] = { key, value };
    m_size++;
    return true;
}

bool Map::update(const std::string& key, const double& value) {
    for (int i = 0; i < m_size; i++) {
        if (m_data[i].key == key) {
            m_data[i].value = value;
            return true;
        }
    }
    return false;
}

bool Map::insertOrUpdate(const std::string& key, const double& value) {
    return update(key, value) || insert(key, value);
}

bool Map::erase(const std::string& key) {
    for (int i = 0; i < m_size; i++) {
        if (m_data[i].key == key) {
            m_data[i] = m_data[m_size - 1]; // move last element to i
            m_size--;
            return true;
        }
    }
    return false;
}

bool Map::contains(const std::string& key) const {
    for (int i = 0; i < m_size; i++) {
        if (m_data[i].key == key)
            return true;
    }
    return false;
}

bool Map::get(const std::string& key, double& value) const {
    for (int i = 0; i < m_size; i++) {
        if (m_data[i].key == key) {
            value = m_data[i].value;
            return true;
        }
    }
    return false;
}

bool Map::get(int i, std::string& key, double& value) const {
    if (i < 0 || i >= m_size)
        return false;
    // Sorting rule: key greater than exactly i keys
    int count;
    for (int pass = 0; pass < m_size; pass++) {
        count = 0;
        for (int j = 0; j < m_size; j++) {
            if (m_data[j].key < m_data[pass].key)
                count++;
        }
        if (count == i) {
            key = m_data[pass].key;
            value = m_data[pass].value;
            return true;
        }
    }
    return false;
}

void Map::swap(Map& other) {
    // Constant time swap
    std::swap(m_data, other.m_data);
    std::swap(m_size, other.m_size);
    std::swap(m_capacity, other.m_capacity);
}
