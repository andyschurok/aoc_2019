
#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using StrIt = std::string::const_iterator;

std::vector<int> validInputs;

int startPoint = 248345;
int endPoint = 746315;



std::string convertToStr(int i){
    std::stringstream s;
    s << i;
    return s.str();
}

int groupLength(std::string s, StrIt start){
    
}

bool hasTwoAdjacentDigits(std::string s){
    bool ret = false;
    bool found = false;
    std::string::const_iterator start = s.cbegin();
    bool alreadyFound = false;
    char alreadyFoundNum = 0;
    while(!found){
        StrIt pos = std::adjacent_find(start, s.cend());
        if (pos == s.end()){
            return false;
        }
        if (*pos == *(pos+2)){ //the third value is the same.
            if (alreadyFound && (*pos == alreadyFoundNum)){
                return false;
            } else {

                alreadyFound = true;
                alreadyFoundNum = *pos;
                start = pos + 3; //move to next sequence.
            }
        } else {
            if (alreadyFound && (*pos == alreadyFoundNum)){ return false; 
            }
            return true;
        }
    }
    return ret;
}

bool alwaysIncreases(std::string& s){
    return std::is_sorted(s.begin(), s.end());    
}

bool isValid (int i){
    //Two adjacent digits are the same (like 22 in 122345).
    //Going from left to right, the digits never decrease; they only ever increase or stay the same (like 111123 or 135679).
    std::string inputAsStr = convertToStr(i);

    bool twoAdj = hasTwoAdjacentDigits(inputAsStr);
    bool alwaysInc = alwaysIncreases(inputAsStr);

    return twoAdj && alwaysInc;
}

int main(){
    std::cout << "Hello";
//123444 does not meet criteria but would 122444
    std::cout << "699999 " << std::boolalpha << isValid(699999) << "\n";
 //   std::cout << "223450 " << std::boolalpha << isValid(223450) << "\n";
  //  std::cout << "123789 " << std::boolalpha << isValid(123789) << "\n";

//    std::cout << "112233 " << std::boolalpha << isValid(112233) << "\n";
 //   std::cout << "123444 " << std::boolalpha << isValid(123444) << "\n";
  //  std::cout << "111122 " << std::boolalpha << isValid(111122) << "\n";

//    std::cout << "334446 " << std::boolalpha << isValid(334446) << "\n";
//    std::cout << "444555 " << std::boolalpha << isValid(444555) << "\n";
    //123444
    //111122

   for(int i = startPoint; i <= endPoint; ++i)
   {
       if(isValid(i)){
           validInputs.push_back(i);
       }
    }

    std::cout << "Number of inputs = " << validInputs.size() << "\n";

    // for (int i : validInputs){
    //     std::cout << i << " \n";
    // }

    return 0;
}