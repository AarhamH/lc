#include <string>

/*
  Leetcode 5: Longest Palindromic Subtring (MEDIUM)
   Given a string s, return the longest

  in s.

  Example 1:

  Input: s = "babad"
  Output: "bab"
  Explanation: "aba" is also a valid answer.

  Example 2:

  Input: s = "cbbd"
  Output: "bb"
*/

using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int start = 0, maxLength = 0;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            return right - left - 1;
        };

        for (int i = 0; i < n; i++) {
            int len1 = expandAroundCenter(i, i);  
            int len2 = expandAroundCenter(i, i + 1);
            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};
