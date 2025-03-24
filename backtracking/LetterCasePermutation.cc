#include <vector>
#include <string>

/*
  Leetcode 784: Letter Case Permutation (MEDIUM)

  Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

  Return a list of all possible strings we could create. Return the output in any order.

  Example 1:

  Input: s = "a1b2"
  Output: ["a1b2","a1B2","A1b2","A1B2"]

  Example 2:

  Input: s = "3z4"
  Output: ["3z4","3Z4"]
*/

class Solution {
public:
    std::vector<std::string> res;
    std::string sol;
    void backtrack (std::string s, int i) {
      if(sol.length() == s.length()) {
        res.push_back(sol);
        return;
      }

      sol.push_back(s[i]);
      backtrack(s, i+1);
      sol.pop_back();

      if(isalpha(s[i])) {
        s[i] ^= 32;
        sol.push_back(s[i]);
        backtrack(s, i+1);
        sol.pop_back();
      }
    }
    std::vector<std::string> letterCasePermutation(std::string s) {
        backtrack(s, 0);
        return res; 
    }
};
