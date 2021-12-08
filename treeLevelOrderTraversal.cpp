#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
	TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> result{};
        if (root == nullptr) return result;
        return result;
         
    }

private:
    void helper(TreeNode* root, vector<vector<int>> &result) {
        // Pseudocode...............................
        // initialize a queue for TreeNode pointers
        // push in the root of the tree to initiliaze our queue
        // loop while the queue isn't empty. 
            // store the current size of queue (call it n)
            // for loop that iterates n times. 
                // pop the front of the queue and store it in a temp array. 
                // push in the left and right children of the parent node. 

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            int s = q.size();
            TreeNode* f;
            vector<int> temp{};
            for (int i = 0; i < s; i++) {
                f = q.front();
                q.pop();
                temp.push_back(f->val);
                if (f->left != nullptr)
                    q.push(f->left);
                if (f->right != nullptr)
                    q.push(f->right);

            }

            result.push_back(temp);
        }
        return;
    }
};