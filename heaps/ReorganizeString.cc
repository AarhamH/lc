#include <unordered_map>
#include <string>
#include <queue>

/*
  Leetcode 767: Reorganize String (MEDIUM)

  You are given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

  You can return any possible rearrangement of s or return "" if not posssible.

  Example 1:

  Input: s = "axyy"

  Output: "xyay"

  Example 2:

  Input: s = "abbccdd"

  Output: "abcdbcd"

  Example 3:

  Input: s = "ccccd"

  Output: ""


  SOLUTION STRUCTURE: Use a maximum heap to get the character with the largest frequency everytime, and insert the most frequent elements firstly
*/

using namespace std;
class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<int, char>> heap;
        for (auto i : freq) {
            heap.push({i.second, i.first});
        }

        string result = "";
        pair<int, char> prev = {0, ' '};

        while (!heap.empty()) {
            auto [count, c] = heap.top();
            heap.pop();
            result += c;
            count--;

            if (prev.first > 0) {
                heap.push(prev); 
            }

            prev = {count, c};
        }

        return result.length() == s.length() ? result : "";
    }
};
