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
void search(TreeNode* root,vector<int> &v){
    if(!root)return;
    v.push_back(root->val);
    search(root->left,v);
        search(root->right,v);
}
    int getMinimumDifference(TreeNode* root) {
        vector<int>tree;
search(root,tree);
sort(tree.begin(),tree.end());
int ans=INT_MAX;
for(int i=0;i<tree.size()-1;i++){
    ans=min(ans,tree[i+1]-tree[i]);
}
return ans;
    }
};
