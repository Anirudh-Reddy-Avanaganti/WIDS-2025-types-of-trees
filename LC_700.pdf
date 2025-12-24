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
void search(TreeNode* root, int vali,TreeNode*& n){
    if(!root)return;
    else if(root->val==vali){
n=root;return;
    }
    else{if(root->val>vali)
        search(root->left,vali,n);
        else
                search(root->right,vali,n);
    }
}
    TreeNode* searchBST(TreeNode* root, int vali) {
       TreeNode* n=nullptr;
     search(root, vali, n);  
     return n; 
    }
};
