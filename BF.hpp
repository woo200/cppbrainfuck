#pragma once

#include <stdlib.h>
#include <string>
#include "Tape.hpp"
#include "Array.hpp"

namespace Brainfuck
{
    class Brainfuck
    {
        Tape* tape;
        JUtils::Array<int>* loopIndicies;
        std::string* srcCode;
        int codePointer;
    public:
        Brainfuck(std::string code);
        void interpret();
    protected:
        void check();
        void run(char code);
    };
}