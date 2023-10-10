#include "Collectible.h"
#include <iostream>

// Default construction possible
Collectible::Collectible(Type t_type, int t_value) :
    m_type(t_type), m_value(t_value)
{
    m_type = static_cast
}

int Collectible::value() const
{
    return m_value;
}

void Collectible::setType(Type t_type)
{
    m_type = t_type;
}

void Collectible::setValue(int t_value)
{
    m_value = t_value;
}

Collectible* Collectible::generateCollectibles(int t_howMany)
{
    int* arr = new int[t_howMany]; // new dynamic array

    for (int i; i < t_howMany; i++)
    {
        arr[i] = (rand() % 100) + 1;
    }

    return arr;
}
