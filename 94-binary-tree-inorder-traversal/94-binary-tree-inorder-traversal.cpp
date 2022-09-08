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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inOrder;
        TreeNode* cur = root;
        while(cur!=NULL){
            if(cur->left==NULL){
                inOrder.push_back(cur->val);
                cur=cur->right;
            }
            else{
                TreeNode* prev = cur->left;
                while(prev->right!=NULL && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==NULL){
                    prev->right=cur;
                    cur=cur->left;
                }
                else if(prev->right==cur){
                    prev->right=NULL;
                    inOrder.push_back(cur->val);
                    cur=cur->right;
                }
            }
        }
        return inOrder;
    }
};

/*
Intuition:
Seeing tree problems, first thing that it hit's is?
what is it? 
its Recursion.

Approach 2: (Optimized - Morris Traversal)

So the idea is that at a node whether we have to move left or right is determined whether the node has a left subtree.
If it doesn’t we move to the right.
If there is a left subtree then we see its rightmost child. If the rightmost child is pointing to NULL, we move the current node to its left.
If the rightmost child is already pointing towards the current node, we remove that link and move to the right of the current node.
We will stop the execution when the current points to null and we have traversed the whole tree.

Time Complexity: O(N), where N is the number of nodes in the Binary Tree.
Space Complexity: O(1), constant space
*/