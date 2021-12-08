#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <utility>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    pair<int, int> dfs(TreeNode* root, int& mx) {
        // if (root->left == nullptr and root->right == nullptr) return make_pair(0, 0);

        pair<int, int> leftSide = make_pair(0, 0);
        pair<int, int> rightSide = make_pair(0, 0);

        if (root->left) leftSide = dfs(root->left, mx);
        if (root->right) rightSide = dfs(root->right, mx);

        int temp1 = 1 + leftSide.first + rightSide.first; // stores the sum of the depths of right and left subtree and the current root.
        int temp2 = max(leftSide.first, rightSide.first) + 1; // stores the new max depth of subtree.
        //cout << "node: " << root->val << "  ";
        //cout << "[" + to_string(temp2) + "," + to_string(max({ leftSide.second, rightSide.second, temp1 })) + "]" << endl;
        return make_pair(temp2, max({ leftSide.second, rightSide.second, temp1 }));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int mx = INT32_MIN;
        pair<int, int> result = dfs(root, mx);
        return max(result.first, result.second) - 1;
    }
};