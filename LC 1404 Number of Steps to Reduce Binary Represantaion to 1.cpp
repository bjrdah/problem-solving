/*Link : * https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description//
class Solution {
public:

    int numSteps(string s) {
        if (s=="1") return 0;
        else if (s[s.length()-1]=='1') {
            int i=s.length()-1;
            s[i]='0';
            i=i-1;
            while((i>=0) && (s[i]!='0')) {
                s[i]='0';
                i--;
            }
            if (i < 0)  s="1"+s;
            else s[i]='1';
            return 1+numSteps(s);
            }
        else return 1 + numSteps( s.substr(0,s.length()-1));
    }
};
