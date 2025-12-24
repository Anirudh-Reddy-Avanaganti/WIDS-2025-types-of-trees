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
void left(TreeNode* root,vector<int>&v){
if(!root){
    v.push_back(INT_MIN);
    return;
}
v.push_back(root->val);
left(root->left,v);
left(root->right,v);
}
void right(TreeNode* root,vector<int>&v){
if(!root){
    v.push_back(INT_MIN);
    return;
}
v.push_back(root->val);
right(root->right,v);
right(root->left,v);
}
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        vector<int> l,r;
        left(root,l);
        right(root,r);
        return (l==r);
    }
};
