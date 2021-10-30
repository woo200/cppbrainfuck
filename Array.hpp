#pragma once
#include <stdlib.h>
#include <iostream>

namespace JUtils
{
    template <class T>
    class Array
    {
    public:
        int size;
    private:
        T* array;
    public:
        Array();

        T& operator[](int);
        void operator+=(T);

        void append(T);
        T& pop();
        void remove(int);
        int len();
        T& get(int);
    };

    template <class T>
    std::ostream& operator<<(std::ostream& os, Array<T>& array);
}

#include "Array.tpp"