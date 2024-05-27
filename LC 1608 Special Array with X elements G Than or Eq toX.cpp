/*
 * Link : https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/description/
*/
class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int pos;
        for (int i=1;i<=nums[nums.size()-1];i++){
            pos=nums.size()-i;
            if(pos==0){
                if( nums[pos]>=i){
                    return i;
                }
                else{
                    return -1;
                }
           }
            else if(nums[pos-1]<i && nums[pos]>=i){
                return i;
            }
        }
           return -1;       
    }
};
