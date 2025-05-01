#include <climits>
#include <vector>

/*
  Leetcode 322: Coin Change (MEDIUM)

  You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

  Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

  You may assume that you have an infinite number of each kind of coin.

  Example 1:

  Input: coins = [1,2,5], amount = 11
  Output: 3
  Explanation: 11 = 5 + 5 + 1

  Example 2:

  Input: coins = [2], amount = 3
  Output: -1

  Example 3:

  INPUT: COINS = [1], AMOUNT = 0
  OUTPUT: 0
*/

using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int> d(amount+1, amount+1);
       
       d[0] = 0;
       for(int i=1; i<=amount; i++) {
         int local_min = INT_MAX;
         bool found_coin = false;
         for(int coin: coins) {
            if(i - coin >= 0) {
                d[i] = min(d[i], d[i - coin] + 1);
            }
         }
       }
       if(d[amount] > amount) {
        return -1;
       }

       return d[amount];
    }
};

