#include<vector>

/*
  Leetcode 152: Maximum Product Subarray (MEDIUM) 
  Given an integer array nums, find a

  that has the largest product, and return the product.

  The test cases are generated so that the answer will fit in a 32-bit integer.

  Example 1:

  Input: nums = [2,3,-2,4]
  Output: 6
  Explanation: [2,3] has the largest product 6.

  Example 2:

  Input: nums = [-2,0,-1]
  Output: 0
  Explanation: The result cannot be 2, because [-2,-1] is not a subarray.


  SOLUTION: Kadane's Algorithm
*/

using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
     int global = nums[0];
     int curr_min = 1;
     int curr_max = 1;

     for(int num: nums) {
      int prod = curr_max * num;
      curr_max = max(max(num * curr_max, num * curr_min), num);
      curr_min = min(min(prod, num * curr_min), num);

      global = max(global, curr_max);
     }    

     return global; 
    }
};
