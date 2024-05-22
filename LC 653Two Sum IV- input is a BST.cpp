/**
 * Link : https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
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
set<int>elements;
    
    bool findTarget(TreeNode* root, int k) {
        if (root == NULL) return false;
        if (elements.find(k-root->val)!=elements.end()) return true;
        elements.insert(root->val);
        if(findTarget(root->left,k) )return true;
        if (findTarget(root->right,k) ) return true;
        return false;
    }
};
