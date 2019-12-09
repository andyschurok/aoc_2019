
#include <string>

#include <vector>
#include <iostream>
#include <fstream>
#include <iterator>

struct CurrentHead{
    unsigned currPos;
    int* current_opcode;

};

void advance(CurrentHead& pos, std::vector<int>& code){
    pos.currPos = pos.currPos + 4;
    pos.current_opcode = &code[pos.currPos];
}

void addition(CurrentHead& pos, std::vector<int>& codes){
    size_t n0 = codes[pos.currPos + 1];
    size_t n1 = codes[pos.currPos + 2];

    int v0 = codes[n0];
    int v1 = codes[n1];
std::cout << "add \n";
    codes[codes[pos.currPos + 3]] = v0 + v1;
}

void multiply(CurrentHead& pos, std::vector<int>& codes){
    
    size_t n0 = codes[pos.currPos + 1];
    size_t n1 = codes[pos.currPos + 2];

    int v0 = codes[n0];
    int v1 = codes[n1];
    std::cout << "Multiply \n";
    codes[codes[pos.currPos + 3]] = v0 * v1;
}

int main(){
    std::vector<int> opcodes;

    std::ifstream inputFile("day2.txt");
    std::string s;
    while(std::getline(inputFile, s, ',')){
       opcodes.push_back(std::atoi(s.c_str()));
    }
    std::cout << "Size = " << opcodes.size() << "\n";

    opcodes[1] = 12;
    opcodes[2] = 2;

    struct CurrentHead pos;
    pos.currPos = 0;
    pos.current_opcode = &opcodes.data()[0];
    

    bool end = false;
    while(pos.currPos < opcodes.size()){
        switch(*(pos.current_opcode)){
            case 1: 
                addition(pos, opcodes);
                break;
            case 2: 
                multiply(pos, opcodes);
            case 99: break;
            default: std::cout << "error with opcode" << *pos.current_opcode << "\n"; break;
        }
        advance(pos, opcodes);
    }


    //advance(int* curr);

    std::cout << "value is " << opcodes[0] << "\n";
}

