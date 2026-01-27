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
void search(TreeNode* root,map<int,int>&v){
    if(!root)return;
    else{
v[root->val]++;
search(root->left,v);
search(root->right,v);
    }
}
    vector<int> findMode(TreeNode* root) {
        map<int,int>v;
search(root,v);
        vector<pair<int,int>> ans;
        vector<int>p;
for(auto it :v){
ans.emplace_back(it.second,it.first);
}
sort(ans.begin(),ans.end());
int last=ans.back().first;
int i=ans.size()-1;
while(i>=0 && ans[i].first==last){
p.push_back(ans[i].second);i--;
}
return p;
    }
};
