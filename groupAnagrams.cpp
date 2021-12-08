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
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map; // Hash map maintaining anagrams.

        vector<string>::iterator i = strs.begin();
        string t1; 
        while (i != strs.end()) {
            t1 = *i;
            sort(t1.begin(), t1.end());
            if (map.find(t1) == map.end()) { // so the word's anagram doesn't exist in the map
                // add the new anagram's key and the word to the map as well
                vector<string> t2 = {*i};
                map.emplace(t1, t2);
            }
            else {
                map[t1].push_back(*i);
            }
            i++;
        }

        for (auto& p: map) {
            ans.push_back(p.second);
        }

        return ans;
    }
};