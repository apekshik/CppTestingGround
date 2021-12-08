#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set; 
        int ans = 0;
        string::iterator f = s.begin();
        string::iterator b = s.begin();

        while (f != s.end() && b != s.end()) {
            if (set.find(*f) == set.end()) {
                set.insert(*f);
                f++;
                ans = max(ans, int(set.size()));
            }
            else
            {
                set.erase(*b);
                b++;
            }
        }
        
        return ans;
    }
};

