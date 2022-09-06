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
    TreeNode* pruneTree(TreeNode* root) {
        if(root!=NULL){
            root->left = pruneTree(root->left);
            root->right = pruneTree(root->right);
            if(!root->left && !root->right && root->val==0)
                return NULL;
        }
        return root;
    }
};

/*

Intuition:
Seeing tree problems, first thing that hit's your brain is Recursion.

Approach:
Here we recursively traverse the nodes in binary tree and check:

--> If The current sub-tree is contains 1(if and only if root.val == 1 or leftSubTree contains 1 or rightSubTree     contains 1) then return root.
--> If The above condition doesn't satisfy then return NULL.
--> Finally Set the root->left == NULL if it's leftSubTree doesn't contain 1 otherwise keep the root->left as       the original node.
--> Do the same for the root->right as well with the same condtions.

--> Time Complexity: O(N), where N is the number of nodes in the Binary Tree.
--> Space Complexity: O(H), where H is the height of the Binary Tree (Recursion stack space)

*/