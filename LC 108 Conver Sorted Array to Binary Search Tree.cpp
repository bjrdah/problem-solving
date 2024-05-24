/**
 * Link : https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
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
    TreeNode* root;
    TreeNode* makeTree(TreeNode* root,vector<int> &nums,int begin,int end){
        if(begin == end) {
            root->val=nums[begin];
            return root;
        }
        root->val=nums[(begin+end)/2];
        TreeNode* rght=new TreeNode();
        rght=makeTree(rght,nums,((begin+end)/2)+1,end);
        root->right=rght;
        if(((begin+end)/2) !=begin){
        TreeNode* lft=new TreeNode();
        lft=makeTree(lft,nums,begin,((begin+end)/2)-1);
        root->left=lft; 
        }
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=new TreeNode();
        root=makeTree(root,nums,0,nums.size()-1);
        return root;
    }
};
