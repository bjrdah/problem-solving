/* Link : https://leetcode.com/problems/find-the-child-who-has-the-ball-after-k-seconds/description/*/
class Solution {
public:
    int numberOfChild(int n, int k) {
        int i=0;
        int j=0;
        int direction=1;
        while(i<k){
            if((j==0) &&(direction==-1)){
                j=j+1;
                direction=1;
                i++;
                continue;
            }
            if((j==n-1) &&(direction==1)){
                j=j-1;
                direction=-1;
                i++;
                continue;
            }
            j+=direction;
            i++;
        }
        return j;
    }
};
