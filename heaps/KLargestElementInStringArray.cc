#include <vector>
#include <queue>
#include <string>

/*
  Leetcode 1985: Find the Kth Largest Integer in the array (MEDIUM)
  You are given an array of strings nums and an integer k. Each string in nums represents an integer without leading zeros.

  Return the string that represents the kth largest integer in nums.

  Note: Duplicate numbers should be counted distinctly. For example, if nums is ["1","2","2"], "2" is the first largest integer, "2" is the second-largest integer, and "1" is the third-largest integer.

   

  Example 1:

  Input: nums = ["3","6","7","10"], k = 4
  Output: "3"
  Explanation:
  The numbers in nums sorted in non-decreasing order are ["3","6","7","10"].
  The 4th largest integer in nums is "3".
*/

class Solution {
public:

  std::string kthLargestNumber(std::vector<std::string>& nums, int k) {
      auto comp = [](std::string  &a, std::string &b) {
        if(a.size() == b.size()) {
            return a > b;
        }
        return a.size() > b.size();
      };
      std::priority_queue<std::string, std::vector<std::string>, decltype(comp)> pq(comp);
       for(auto &it : nums) {
        pq.push(it);
        if(pq.size() > k)pq.pop();
       }
        return pq.top();
    }
};
