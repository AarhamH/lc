#include <vector>
#include <string>

/*
  Leetcode 17: Letter Combinations of a Phone Number (MEDIUM)

  Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

  A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

  Example 1:

  Input: digits = "23"
  Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

  Example 2:

  Input: digits = ""
  Output: []

*/

class Solution {
public:
    std::vector<std::string> res;
    std::string sol;
    std::vector<std::string> map = {"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"}; 
    void backtrack(std::string digits, int i) {
      if(sol.length() == digits.length()) {
        res.push_back(sol);
        return;
      }

      char digit = digits[i];
      if(digit < '2' || digit > '9') {
        return;
      }
      int index = digit - '0';
      std::string chars = map[index];
      
      for(char c1: chars) {
        sol.push_back(c1);
        backtrack(digits, i+1);
        sol.pop_back();
      }
    }
    std::vector<std::string> letterCombinations(std::string digits) {
      if(digits.length() == 0) {
        return res;
      }
      
      backtrack(digits,0);
      return res;    
    }
};
