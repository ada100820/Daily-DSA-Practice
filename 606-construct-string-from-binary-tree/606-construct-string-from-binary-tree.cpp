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
    string tree2str(TreeNode* root) {
		string ans = to_string(root->val);
		if (root->left) //left side check
			ans += "(" + tree2str(root->left) + ")";
		if (root->right) { //right side check
			if (!root->left) ans += "()"; //left side not present, but right side present
			ans += "(" + tree2str(root->right) + ")"; 
		}
		return ans;
	}
};

/*
Here we recursively traverse the nodes in binary tree and check:

--> If there exists a left or right child, we add parentheses for left child and put inside whatever we find on left 
    subtree.
--> If there exists only right child, we add parentheses for right child and add inside whatever we find in right
    subtree.
--> The difference that can observed is that for left part we create parentheses even when there is no left child, but
    for right part we create parentheses only when there is right child.

--> Time Complexity: O(N^2), where N is the number of nodes in the Binary Tree.
    Space Complexity: O(H), where H is the height of the Binary Tree (Recursion stack space)
*/
