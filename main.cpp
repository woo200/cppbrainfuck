#include <stdlib.h>
#include <iostream>
#include <vector>
#include <fstream>

#include "BF.hpp"

class InputParser{
    public:
        InputParser (int &argc, char **argv){
            for (int i=1; i < argc; ++i)
                this->tokens.push_back(std::string(argv[i]));
        }

        const std::string& getCmdOption(const std::string &option) const{
            std::vector<std::string>::const_iterator itr;
            itr =  std::find(this->tokens.begin(), this->tokens.end(), option);
            if (itr != this->tokens.end() && ++itr != this->tokens.end()){
                return *itr;
            }
            static const std::string empty_string("");
            return empty_string;
        }

        bool cmdOptionExists(const std::string &option) const{
            return std::find(this->tokens.begin(), this->tokens.end(), option)
                   != this->tokens.end();
        }
    private:
        std::vector <std::string> tokens;
};

int main(int argc, char **argv)
{
    InputParser input(argc, argv);

    const std::string &filename = input.getCmdOption("-f");
    if (!filename.empty())
    {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string code((std::istreambuf_iterator<char>(file)),
                              std::istreambuf_iterator<char>());

            Brainfuck::Brainfuck* interpreter = new Brainfuck::Brainfuck(code);
            interpreter->interpret();
        } else {
            std::cout << argv[0] << ": ERROR: Could not open file." << std::endl;
        }
        
    } else if (input.cmdOptionExists("-h")){
        std::cout << "Usage: " << argv[0] << " [options] ... " << std::endl;
        std::cout << "Options and Arguments: " << std::endl;
        std::cout << "-h         : Displays help menu" << std::endl;
        std::cout << "-f file.bf : Run Brainfuck file" << std::endl;
    } else {
        std::cout << argv[0] << ": ERROR: No arguments provided." << std::endl;
    }
}