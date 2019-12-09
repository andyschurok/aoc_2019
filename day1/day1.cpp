
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

long calcModuleFuel(long mass){
    return (mass / 3) - 2;
}

int main(){

    std::ifstream myfile ("day_1_input.txt");
    std::string s;

    std::vector<long> orig_vals;
    std::vector<long> transformed_vals;

    while(std::getline(myfile, s)){
        long val;
        std::stringstream convertor (s);
        convertor >> val;
        orig_vals.emplace_back(val);
    }
    std::transform(orig_vals.begin(), orig_vals.end(), std::back_inserter(transformed_vals),
        [](long c) -> long { return calcModuleFuel(c);}
    );
    long outVal = std::accumulate(transformed_vals.begin(), transformed_vals.end(), 0L);
    std::cout << outVal << '\n'; 

    return 0;
}