#include <vector>
#include <algorithm>

/*
  Leetcode 46: Permutations (MEDIUM)

  Given an array nums of unique integers, return all the possible permutations. You may return the answer in any order.

  Example 1:

  Input: nums = [1,2,3]

  Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

  Example 2:

  Input: nums = [7]

  Output: [[7]]
*/

class Solution {
public:
    std::vector<std::vector<int>> res;
    std::vector<int> sol;
    void backtrack(std::vector<int> &nums) {
      if(sol.size() == nums.size()) {
        res.push_back(sol);
        return;
      }

      for(int x: nums) {
        if(std::find(sol.begin(), sol.end(), x) == sol.end()) {
            sol.push_back(x);
            backtrack(nums);
            sol.pop_back();
        }
      }

      return;
    }
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
       backtrack(nums);
       return res; 
    }
};
