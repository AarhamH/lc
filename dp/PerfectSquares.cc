#include <climits>
#include<vector>
#include<math.h>

/*
  Leetcode 279: Perfect Squares (MEDIUM)

  Given an integer n, return the least number of perfect square numbers that sum to n.

  A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 9, and 16 are perfect squares while 3 and 11 are not.

  Example 1:

  Input: n = 12
  Output: 3
  Explanation: 12 = 4 + 4 + 4.

  Example 2:

  Input: n = 13
  Output: 2
  Explanation: 13 = 4 + 9.
*/

using namespace std;
class Solution {
public:
    int numSquares(int n) {
       vector<int> d(n+1, INT_MAX);
       d[0] = 0;
       for(int i=1;i<=n;i++) {
        for(int j=1; j<=i; j++) {
          long long square = j*j;
          if(i - square < 0) {
            break;
          }
          d[i] = min(d[i], d[i-square]+1);
        }
       }

       return d[n]; 
    }
};
