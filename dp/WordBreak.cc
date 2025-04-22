#include<vector>
#include<string>

/*
  Leetcode 139: Word Break (MEDIUM)
  Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary words.

  Note that the same word in the dictionary may be reused multiple times in the segmentation.

  Example 1:

  Input: s = "leetcode", wordDict = ["leet","code"]
  Output: true
  Explanation: Return true because "leetcode" can be segmented as "leet code".

  Example 2:

  Input: s = "applepenapple", wordDict = ["apple","pen"]
  Output: true
  Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
  Note that you are allowed to reuse a dictionary word.

  Example 3:

  Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
  Output: false
*/

using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
       vector<bool> d(s.length() + 1, false);
       d[s.length()] = true;
       int counter = 0;
       for(int i=s.length() - 1; i >= 0; i--) {
         for(string w: wordDict) {
          if(i+w.length() <= s.length() && s.substr(i, w.length()) == w) {
            d[i] = d[i+w.length()];
          }
          if(d[i]) {
            break;
          }
         } 
       }

       return d[0];

       return counter == wordDict.size(); 
    }
};
