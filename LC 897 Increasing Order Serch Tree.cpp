/**
 * Link : https://leetcode.com/problems/increasing-order-search-tree/description/
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
void build(TreeNode* root, vector <int> &v){
    if(root->left) build(root->left,v);
    v.push_back(root->val);
    if(root->right) build(root->right,v);
}
    TreeNode* increasingBST(TreeNode* root) {
       vector <int> v;
       build(root,v);
       TreeNode* righter_inorder=new TreeNode(v[0]);
       TreeNode* res=righter_inorder;
       for (int i =1;i<v.size();i++){
            righter_inorder->right=new TreeNode(v[i]);
            righter_inorder=righter_inorder->right;
       }
       return res;
    }
};
