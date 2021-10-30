#include "Tape.hpp"

namespace Brainfuck
{
    Tape::Tape()
    {
        this->array = new JUtils::Array<int>();
        this->pointer = 0;
    }

    void Tape::right()
    {
        this->pointer++;
    }

    void Tape::left()
    {
        if (this->pointer <= 0)
        {
            this->pointer = 0;
            return;
        }
        this->pointer--;
    }

    void Tape::updateTapeLength()
    {
        if (this->array->len() - 1 < this->pointer)
        {
            for (int i = 0, len = this->pointer - this->array->len() + 1; i < len; i++)
                this->array->append(0);
        }
    }

    void Tape::add()
    {
        this->updateTapeLength();
        this->array->get(this->pointer) ++;
    }

    void Tape::sub()
    {
        this->updateTapeLength();
        this->array->get(this->pointer) --;
    }

    int Tape::get()
    {
        this->updateTapeLength();
        return this->array->get(this->pointer);
    }

    void Tape::set(int val)
    {
        this->updateTapeLength();
        this->array->get(this->pointer) = val;
    }

}