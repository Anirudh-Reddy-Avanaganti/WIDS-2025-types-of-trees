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
bool vali(TreeNode* root,long long mini,long long maxi){
if(!root)return true;
if(root->val <=mini || root->val>=maxi){
    return false;
}
if(vali(root->left,mini,root->val)&&
vali(root->right,root->val,maxi))
return true;
else{return false;}
}
    bool isValidBST(TreeNode* root) {
      return  vali(root,LLONG_MIN,LLONG_MAX);
    }
};
