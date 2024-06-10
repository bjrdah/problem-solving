/*Link : https://leetcode.com/problems/find-the-n-th-value-after-k-seconds/description/*/
class Solution {
public:
    int valueAfterKSeconds(int n, int k) {
        vector <long long> a(n,1);
        for (int i=0;i<k;i++){
            for (int j=0;j<n;j++){
                if(j!=0){
                    a[j]=(a[j]+a[j-1])%1000000007;
                }
            }
        }
        return a[n-1]%1000000007;

    }
};
