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
void depth(TreeNode* root,int h,vector<vector<int>> &v){
    if(!root)return;
    if(v.size()<=h)v.push_back({});
    v[h].push_back(root->val);
    depth(root->left,h+1,v);
    depth(root->right,h+1,v);
}
    vector<vector<int>> levelOrder(TreeNode* root) {
       vector<vector<int>> v; 
       depth(root,0,v);
       return v;
    }
};
