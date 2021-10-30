#include "BF.hpp"

namespace Brainfuck
{
    Brainfuck::Brainfuck(std::string code)
    {
        this->loopIndicies = new JUtils::Array<int>();
        this->tape = new Tape();
        this->srcCode = new std::string(code.c_str());
    }

    void Brainfuck::check()
    {
        // TODO: Add checks 
    }

    void Brainfuck::run(char code)
    {
        switch (code)
        {
        case '>':
            this->tape->right();
            break;
        case '<':
            this->tape->left();
            break;
        case '+':
            this->tape->add();
            break;
        case '-':
            this->tape->sub();
            break;
        case '.':
            std::cout << (char) this->tape->get();
            break;
        case ',':
            this->tape->set(std::cin.get());
            break;
        case '[':
            this->loopIndicies->append(this->codePointer - 1);
            if (this->tape->get() == 0)
            {
                this->loopIndicies->pop();
                while (this->srcCode->at(this->codePointer) != ']')
                    this->codePointer ++;
            }
            break;
        case ']':
            if (this->loopIndicies->len() == 0)
                return;
            this->codePointer = this->loopIndicies->pop();
            break;
        default:
            break;
        }
    }   

    void Brainfuck::interpret()
    {
        this->check();
        while (true)
        {
            if (this->codePointer + 1 == this->srcCode->length())
                break;
            this->run(this->srcCode->at(this->codePointer));
            this->codePointer ++;
        }
    }
   
}