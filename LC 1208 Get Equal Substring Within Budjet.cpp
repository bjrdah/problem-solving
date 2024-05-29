/* Link : https://leetcode.com/problems/get-equal-substrings-within-budget/description/ */
class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int>sum;
        sum.push_back(abs(int(s[0])-int(t[0])));
        for(int i=1;i<s.length();i++){
            sum.push_back(   sum[i-1]+abs( int(s[i])-int(t[i]) )     );
        } 
       int  i=0;
       int maxC=0;
       int j,currmax;
       int prevcost=0;
        while(i<=s.length()-1){
            j=i;  
            currmax=0;    
            while( (j<=s.length()-1)&&(sum[j]-prevcost<=maxCost)){
                j++;
                currmax++;
            }
            if(currmax>maxC) maxC=currmax;
            prevcost=sum[i];
            i++;
        }
        return maxC;
    }
};
