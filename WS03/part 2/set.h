#ifndef SDDS_SET_H_
#define SDDS_SET_H_
#include <iostream>
#include <cmath>
#include "Collection.h"

namespace sdds
{
    template <typename T>
    class Set : public Collection<T, 100>
    {
    public:
        bool add(const T &item);
        ~Set(){};
    };

    template <>
    bool Set<double>::add(const double &item)
    {
        for (unsigned int i = 0; i < this->numOfRecords; i++)
        {
            if (fabs(floor(this->m_objects[i] * 100) / 100) == fabs(floor(item * 100) / 100))
                return false;
        }
        this->m_objects[this->numOfRecords++] = item;
        return true;
    }

    template <typename T>
    bool Set<T>::add(const T &item)
    {
        for (unsigned int i = 0; i < this->numOfRecords; i++)
        {
            if (this->m_objects[i] == item)
                return false;
        }
        this->m_objects[this->numOfRecords++] = item;
        return true;
    }

}
#endif // end of an if statement..