#include<vector>

/*
   Leetcode 198: House Robbers (MEDIUM)
  You are given an integer array nums where nums[i] represents the amount of money the ith house has. The houses are arranged in a straight line, i.e. the ith house is the neighbor of the (i-1)th and (i+1)th house.

  You are planning to rob money from the houses, but you cannot rob two adjacent houses because the security system will automatically alert the police if two adjacent houses were both broken into.

  Return the maximum amount of money you can rob without alerting the police.

  Example 1:

  Input: nums = [1,1,3,3]

  Output: 4

  Explanation: nums[0] + nums[2] = 1 + 3 = 4.
*/

class Solution {
public:
    int rob(std::vector<int>& nums) {
       int n = nums.size();
       std::vector<int> d(n + 1);
       d[0] = 0;
       d[1] = nums[0];
       for(int i=2; i<=nums.size(); i++) {
        d[i] = std::max(nums[i-1] + d[i-2], d[i-1]);
       } 

       return d[d.size()-1];
    }
};
