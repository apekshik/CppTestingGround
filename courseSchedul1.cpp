#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        bool result = true;

        vector<vector<int>> adjacencyList(numCourses, vector<int> {});
        vector<int> visited(numCourses, 0); // 0 for not visited, 1 if in current dfs path, and -1 if previously visited. 

        // fill your adjacency list. 
        for (int i = 0; i < prerequisites.size(); i++) {
            int index = prerequisites[i][0];
            int element = prerequisites[i][1];
            adjacencyList[index].push_back(element);
        }

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                dfs(i, adjacencyList, visited, result);
            }
        }
        return result;
    }

    void dfs(int currentIndex, vector<vector<int>>& adjacencyList, vector<int> &visited, bool& result) {
        if (visited[currentIndex] == 1) {
            result = false;
            return;
        }

        visited[currentIndex] = 1;
        // cout << "visited[" + to_string(currentIndex) +"] = " << visited[currentIndex] << endl;
        for (int i = 0; i < adjacencyList[currentIndex].size(); ++i) {
            if (visited[adjacencyList[currentIndex][i]] != -1)
                dfs(adjacencyList[currentIndex][i], adjacencyList, visited, result);
        }

        visited[currentIndex] = -1;
        return;
    }
};
