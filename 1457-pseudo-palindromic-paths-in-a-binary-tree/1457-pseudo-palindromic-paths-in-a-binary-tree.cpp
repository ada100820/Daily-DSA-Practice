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

class Solution{
public:
  int pseudoPalindromicPaths(TreeNode *root, int count = 0){
    // dfs way to find the number of pseudo palindromic paths
    if (!root)
      return 0;
    count ^= 1 << root->val;
    int res = pseudoPalindromicPaths(root->left, count) + pseudoPalindromicPaths(root->right, count);
    if (!root->left && !root->right && (count & (count - 1)) == 0)
      res++;
    return res;
  }
};

/*
Intuition:
Since we need to return the number of pseudo-palindromic paths going from the root node to leaf nodes, so we know that seeing tree problems, first thing that should hit our brain is? what is it? Yessss its Recursion.

Approach:
--> So first, recursively iterate all paths from root to leaves, and count the occurrence of each digits in an integer
    (count=0, initiallly).
--> Will be using count as a bit mask.
--> Whenever we meet an element, we just toggle the corresponding bit using ^(XOR) operation.
--> At the leaf node, we check if the count has only one bit that is 1, we use lowbit to count this.
--> Basically this thing :- (count & (count - 1)) == 0)

--> Time Complexity: O(N)
--> Space Complexity: O(K+H)
*/