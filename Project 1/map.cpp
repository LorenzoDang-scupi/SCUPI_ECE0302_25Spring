#include "map.h"

Map::Map()
{
m_size = 0;
}

bool Map::empty()
const {
if (m_size == 0)
	return true;
else
	return false;
}

int Map::size()
const {
return m_size;
}

bool Map::insert(const KeyType& key, const ValueType& value)
{
if (m_size == DEFAULT_MAX_ITEMS)
	return false;
for (int i = 0; i < m_size; i++) {
	if (m_pairs[i].key == key)
		return false;
}
m_pairs[m_size].key = key;
m_pairs[m_size].value = value;
m_size++;
return true;
}

bool Map::update(const KeyType& key, const ValueType& value)
{
for (int i = 0; i < m_size; i++) {
	if (m_pairs[i].key == key) {
		m_pairs[i].value = value;
		return true;
	}
}
return false;
}

bool Map::insertOrUpdate(const KeyType& key, const ValueType& value) {
if (contains(key))
	return update(key, value);
else
	return insert(key, value);
}

bool Map::erase(const KeyType& key) {
for (int i = 0; i < m_size; i++) {
	if (m_pairs[i].key == key) {
		m_pairs[i] = m_pairs[m_size - 1];
		m_size--;
		return true;
	}
}
return false;
}

bool Map::contains(const KeyType& key) const{
for (int i = 0; i < m_size; i++) {
	if (m_pairs[i].key == key)
		return true;
}
return false;
}

bool Map::get(const KeyType& key, ValueType& value)
const {
for (int i = 0; i < m_size; i++) {
	if (m_pairs[i].key == key) {
		value = m_pairs[i].value;
		return true;
	}
}
return false;
}

bool Map::get(int i, KeyType& key, ValueType& value)
const{
if (i >= 0 && i < m_size) {
	key = m_pairs[i].key;
	value = m_pairs[i].value;
	return true;
}
return false;
}

void Map::swap(Map& other)
{
Pair tempPairs[DEFAULT_MAX_ITEMS];
int tempSize = other.m_size;

for (int i = 0; i < other.m_size; i++) {
	tempPairs[i] = other.m_pairs[i];
}

other.m_size = m_size;
for (int i = 0; i < m_size; i++) {
	other.m_pairs[i] = m_pairs[i];
}

m_size = tempSize;
for (int i = 0; i < tempSize; i++) {
	m_pairs[i] = tempPairs[i];
}
}
