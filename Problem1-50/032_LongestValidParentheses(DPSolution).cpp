class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() == 0) {
            return 0;
        }
        int res = 0;
        vector<int> DP(s.size(), 0);
        for(int i = 1; i<s.size(); ++i) {
            if(s[i] == ')' && s[i-DP[i-1]-1] == '(') {
                DP[i] = DP[i-1]+2;
                if(i-DP[i-1]-2>=0) {
                    DP[i] += DP[i-DP[i-1]-2];
                }
                
                res = max(res, DP[i]);
            }
        }
        
        return res;
    }
};