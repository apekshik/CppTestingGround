#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> result;
        // sort the given list of intervals.
        sort(intervals.begin(), intervals.end(),
            [](vector<int> a, vector<int> b) {
                return a[0] < b[0];
            }
        );

        // push the first interval into the result variable.
        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); ++i) {
            int lastIndex = result.size() - 1;
            if (result[lastIndex][1] >= intervals[i][0]) {
				// This inner-if statement exists to deal with the subtle 
				// case of: [[1,4],[2,3]] which should output [[1,4]]
                if (result[lastIndex][1] >= intervals[i][1]) 
                    continue;
                result[lastIndex][1] = intervals[i][1];
            }
            else
                result.push_back(intervals[i]);
        }
        return result;
    }
};