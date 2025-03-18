#include <vector>
#include <queue>
/*
  Leetcode 973: K Closest Points to Origin (MEDIUM)
  You are given an 2-D array points where points[i] = [xi, yi] represents the coordinates of a point on an X-Y axis plane. You are also given an integer k.

  Return the k closest points to the origin (0, 0).

  The distance between two points is defined as the Euclidean distance (sqrt((x1 - x2)^2 + (y1 - y2)^2)).

  You may return the answer in any order.

  Example 1:

  Input: points = [[0,2],[2,2]], k = 1

  Output: [[0,2]]
*/


class Solution {
public:
    std::vector<std::vector<int>> kClosest(std::vector<std::vector<int>>& points, int k) {
        auto comp = [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0]*a[0] + a[1]*a[1] > b[0]*b[0] + b[1]*b[1];
        };
        std::priority_queue<std::vector<int>,std::vector<std::vector<int>>, decltype(comp)> pq(comp);
        std::vector<std::vector<int>> ret;
        for(int i=0; i<points.size(); i++) {
            pq.push({points[i][0], points[i][1]});
        }

        for(int i=0; i<k; i++) {
            ret.push_back(pq.top());
            pq.pop();
        }    

        return ret;
    }
};
