/* Link : https://leetcode.com/problems/relative-sort-array/description/ */
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;
        for (int& num : arr1) mp[num]++;
        vector<int> ans;
        for(int &n: arr2) {
            while (mp[n]--) ans.push_back(n);
            mp.erase(n);
        }
        for (auto& p : mp) {
            while (p.second--) ans.push_back(p.first);
        }
        return ans;
    }
};
