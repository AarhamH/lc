#include <cstdlib>
#include <vector>
#include <queue>
/*
  Leetcode 1046: Largest Stone Weight (EASY)
  You are given an array of integers stones where stones[i] represents the weight of the ith stone.

  We want to run a simulation on the stones as follows:

      At each step we choose the two heaviest stones, with weight x and y and smash them togethers
      If x == y, both stones are destroyed
      If x < y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.

  Continue the simulation until there is no more than one stone remaining.

  Return the weight of the last remaining stone or return 0 if none remain.

  Example 1:

  Input: stones = [2,3,6,2,4]

  Output: 1
*/

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
       std::priority_queue<int> pq(begin(stones), end(stones));

        while(pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
          
            if(x != y) {
                int pushed_val = abs(y-x);
                pq.push(pushed_val);
            }
        }

        return pq.size() == 1 ? pq.top() : 0;

    }
};
