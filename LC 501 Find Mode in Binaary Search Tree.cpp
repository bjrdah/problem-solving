/**
 * Link : https://leetcode.com/problems/find-mode-in-binary-search-tree/description/
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
    map<int,int> modes;
    void dfs(TreeNode* root, map<int,int> &modes,int &maxModeLength){
        modes[root->val]++;
        maxModeLength=max(maxModeLength,modes[root->val]);
        if(root->left){
            dfs(root->left,modes,maxModeLength);
        }
        if(root->right){
            dfs(root->right,modes,maxModeLength);
        }
    }
    vector<int> findMode(TreeNode* root) {
        int maxModeLength=-1;
        dfs(root,modes,maxModeLength);
        vector<int>ans;
        for(auto &mode:modes){
            if(mode.second==maxModeLength) ans.push_back(mode.first);
        }
        return ans;
    }

};
