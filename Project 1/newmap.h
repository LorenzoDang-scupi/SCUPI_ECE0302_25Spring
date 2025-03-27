#pragma once
#ifndef NEWMAP_H
#define NEWMAP_H

#include <string>

const int DEFAULT_MAX_ITEMS = 150;

class Map
{
public:
    Map();
    Map(int capacity);
    Map(const Map& other);      
    Map& operator=(const Map& other); 
    ~Map();

    bool empty() const;
    int size() const;
    bool insert(const std::string& key, const double& value);
    bool update(const std::string& key, const double& value);
    bool insertOrUpdate(const std::string& key, const double& value);
    bool erase(const std::string& key);
    bool contains(const std::string& key) const;
    bool get(const std::string& key, double& value) const;
    bool get(int i, std::string& key, double& value) const;
    void swap(Map& other);

private:
    struct Pair
    {
        std::string key;
        double value;
    };

    Pair* m_data; // dynamically allocated array
    int m_size;
    int m_capacity;
};

#endif // NEWMAP_H
