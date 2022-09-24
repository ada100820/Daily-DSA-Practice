/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& ans) {
        if (!root) return;
        path.push_back(root->val);
        if (!root->left && !root->right && targetSum == root->val) {
            ans.push_back(path);
        }
        dfs(root->left, targetSum - root->val, path, ans);
        dfs(root->right, targetSum - root->val, path, ans);
        path.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root, targetSum, path, ans);
        return ans;
    }
};

/*
Intuition:
We can use DFS to traverse the tree and keep track of the path we took to get to the current node.

Approach:
--> Using DFS if we reach a leaf node and the sum of the path is equal to the target sum, we add the path to the answer.
--> If we reach a leaf node and the sum of the path is not equal to the target sum, we backtrack and try another path.
--> Time Complexity: O(n), where n is the number of nodes in the tree
--> Space Complexity: O(n)
*/
