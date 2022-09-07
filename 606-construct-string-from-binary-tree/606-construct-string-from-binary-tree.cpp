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
    static string tree2str(const TreeNode* root) {
        string ans;
        tree2Str(root, ans);
        return ans;
    }
    static void tree2Str(const TreeNode* node, string& ans) {
        if (!node) return;   
        ans += to_string(node->val);
        if (node->left) { //left side check
            ans += '(';
            tree2Str(node->left, ans);
            ans += ')';
        }
        if (node->right) { //right side check
            if (!node->left) ans += "()"; //left side not present, but right side present
            ans += '(';
            tree2Str(node->right, ans);
            ans += ')';
        }
    }
};


/*
                                              Optimize solution 
Here we recursively traverse the nodes in binary tree and check:

--> If there exists a left or right child, we add parentheses for left child and put inside whatever we find on left 
    subtree.
--> If there exists only right child, we add parentheses for right child and add inside whatever we find in right
    subtree.
--> The difference that can observed is that for left part we create parentheses even when there is no left child, but
    for right part we create parentheses only when there is right child.

--> Time Complexity: O(N), where N is the number of nodes in the Binary Tree.
    Space Complexity: O(H), where H is the height of the Binary Tree (Recursion stack space)
*/
