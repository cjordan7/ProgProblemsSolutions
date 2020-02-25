// You have to implement the function “Encode” of CaesarCrypto class that codes or
// decodes text based on Caesar’s algorithm.

// the function receives 2 parameters: an original text of any length of type
// “string” and a number of type “int” that represents shifts;

// only letters in both cases must be encrypted;
// alphabet contains only letters in this range: a-zA-Z;
// by encryption the letter can change the case;
// shift could be either positive or negative (for left shift);

// If the input text is empty, null or includes only whitespaces, return an empty
// string.


#include <iostream>
#include <vector>

char getChar(int temp, char a, char z) {
    return temp < a ? ((temp - a)%26)+26 + a :
              temp > z ? ((temp- a)%26) + a: temp;
}

bool isInBetween(char c, char a, char z) {
    return c >= a && c <= z;
}

std::string encode(std::string input, int shift) {
    std::cout << (signed long long)shift << std::endl;
    size_t t = input.find_first_not_of(" ");
    if (t == std::string::npos || input.empty()) {
        return "";
    }
    
    std::vector<char> vector;
   
    for(char i = 'a'; i <= 'z'; ++i) {
        vector.push_back(i);
    }
    
    for(char i = 'A'; i <= 'Z'; ++i) {
        vector.push_back(i); 
    }
       
    
    int size = vector.size();
    
    for(unsigned long long i = 0; i < input.length(); ++i) {
        if(isInBetween(input[i], 'A', 'Z')) {
            int temp = input[i] + shift;
            int temp2 = (temp - 'A' + 26);

            temp = temp2 < 0 ? ((temp2%size) + size)%size : temp2 % size;
            
            input[i] = vector[temp];
            
        } else if(isInBetween(input[i], 'a', 'z')) {
            int temp = input[i] + shift;
            int temp2 = (temp - 'a');

            temp = temp2 < 0 ? ((temp2%size) + size)%size : temp2 % size;
            
            input[i] = vector[temp];
        }
    }    
    
    return input;
}
