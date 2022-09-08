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
    vector<int> vec; 
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==NULL)
            return {};
        inorderTraversal(root->left);
        vec.push_back(root->val);
        inorderTraversal(root->right);
        return vec;
    }
};

/*
Intuition:
Seeing tree problems, first thing that it hit's is?
what is it? 
its Recursion.

Approach: (DFS Traversal)

--> Inorder Traversal follows - Left Root Right
--> If root==NULL we can simply return {};
--> we declare a vector vec and simply push all the root->val after every left traversal and after that right traversal
    happens.
--> Time Complexity: O(N), where N is the number of nodes in the Binary Tree.
--> Space Complexity: O(N), where N is the number of node in the Binary Tree (Recursion stack space)
*/