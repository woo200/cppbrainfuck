#pragma once

#include <stdlib.h>
#include "Array.hpp"

namespace Brainfuck
{
    class Tape
    {
        JUtils::Array<int>* array;
        int pointer;
    public:
        Tape();

        void right();
        void left();
        void add();
        void sub();
        int get();
        void set(int);
    protected:
        void updateTapeLength();
    };
}
