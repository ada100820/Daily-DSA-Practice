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
    int final_ans = 0;
    void paths(TreeNode* root , vector<int> temp){
        if(!root){
            return;
        }else{
            temp.push_back(root->val);
            paths(root->left , temp);
            paths(root->right , temp);
            if(!root->left && !root->right){
                string s = "";
                for(int i = 0 ; i < temp.size() ; i++){
                    s += to_string(temp[i]);
                }
                final_ans += stoi(s);
            }
            temp.pop_back();
            return;
        }
    }
    
    
    int sumNumbers(TreeNode* root) {
        paths(root , {});
        return final_ans;
    }
};