// Write a function that determines whether a string is a valid guess in a Boggle
// board, as per the rules of Boggle. A Boggle board is a 2D array of individual
// characters

#include <iostream>
#include <vector>


bool checkBounds(const std::vector<std::vector<char>>& board, int i, int j) {
    try {
        board.at(i).at(j);
    } catch (const std::out_of_range & throwUp) {
        return false;
    }
    return true;
}

bool check(const std::vector<std::vector<char>>& board,
           const std::string& word,
           std::vector<std::vector<bool>>& booleanVector, int i, int j,
           size_t size, int number) {
    if(word.at(number) != board.at(i).at(j)) {
        return false;
    } else {
        number = number + 1;
    }
    
    if(word.length() == number) {
        return true;
    }
    
    booleanVector.at(i).at(j) = true;
    
    for(int a = -1; a < 2; ++a) {
        for(int b = -1; b < 2; ++b) {
            if(!(a == 0 && b == 0) && checkBounds(board, i + a, j + b)) {
                if(!booleanVector.at(i + a).at(j + b) &&
                   check(board, word, booleanVector, i + a, j + b, size, number)) {
                    return true;
                }
            }
        }
    }
    
    booleanVector.at(i).at(j) = false;
    return false;
}

bool check_word(const std::vector<std::vector<char> > &board, const std::string &word)
{
  if(board.size() == 0 && word.length()) {
    return true;
  }
  if(word.length() == 0) {
      return false;
  }
  size_t size = board.size();
    
    std::vector<std::vector<bool>> booleanVector(size,
                                                 std::vector<bool> (size, false));
    for(int i = 0; i < size; ++i) {
        for(int j = 0; j < size; ++j) {
            if(check(board, word, booleanVector, i, j, size, 0)) {
                return true;
            }
        }
    }
    
    return false;
}
