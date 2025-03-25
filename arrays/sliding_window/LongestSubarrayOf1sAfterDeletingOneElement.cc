#include <vector>

/* 
  Leetcode 1493: Longest Subarray of 1's After Deleting One Element (MEDIUM)

  Given a binary array nums, you should delete one element from it.

  Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

  Example 1:

  Input: nums = [1,1,0,1]
  Output: 3
  Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.

  Example 2:

  Input: nums = [0,1,1,1,0,1,1,0,1]
  Output: 5
  Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].

  Example 3:

  Input: nums = [1,1,1]
  Output: 2
  Explanation: You must delete one element. 
*/

class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
       int l=0;
       int r = 0;
       int zero_count = 0;
       int max_count = 0;
       while (r < nums.size()) {
        if(nums[r] == 0) {
          zero_count ++;
        }
        if(zero_count > 1) {
          while(zero_count > 1) {
            if(nums[l] == 0) {
              zero_count--;
            }
            l++;
          }
        }
        max_count = std::max(max_count, r-l);
        r++;
       }
       return max_count;
    }
};
