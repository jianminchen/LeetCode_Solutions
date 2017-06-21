class Solution {
public:
    int longestValidParentheses(string s) {
        int res = 0,
            curLen = 0;
            
        stack<int> idxStk;
        for(int i = 0; i<s.size(); ++i) {
            if(s[i] == '(') {
                idxStk.push(i-curLen);
                curLen = 0;
            }
            else if(s[i] == ')') {
                if(!idxStk.empty()) {
                    curLen = i-idxStk.top()+1;
                    idxStk.pop();
                    res = max(res, curLen);
                }
                else {
                    curLen = 0;
                }
            }
        }
        return res;
    }
};