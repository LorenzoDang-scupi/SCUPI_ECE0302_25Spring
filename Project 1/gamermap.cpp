#include"gamermap.h"
#include"map.h"
#include<string>
bool gamermap::addGamer(KeyType name)
{
	if (m_size == DEFAULT_MAX_ITEMS)
		return false;
	for (int i = 0; i < m_size; i++)
	{
		if (m_pairs[i].key == name)
			return false;
	}
	m_pairs[m_size].key = name;
	m_pairs[m_size].value = 0.0;
	m_size++;
	return true;
}
double gamermap::hoursSpent(KeyType name) const
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_pairs[i].key == name)
			return m_pairs[i].value;
	}
	return -1;
}
bool gamermap::play(KeyType name, ValueType hours)
{
	if (hours < 0)
		return false;
	for (int i = 0; i < m_size; i++)
	{
		if (m_pairs[i].key == name)
		{
			m_pairs[i].value += hours;
			return true;
		}
	}
	return false;
}
int gamermap::numGamers() const
{
	return m_size;
}
void gamermap::print() const
{
	for (int i = 0; i < m_size; i++)
	{
		std::cout << m_pairs[i].key << " " << m_pairs[i].value << std::endl;
	}
}
gamermap::gamermap()
{
	m_size = 0;
}
