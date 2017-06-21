class Solution {
public:
    bool isValid(string s) {
        stack<char> pStk;
        
        for(int i = 0; i<s.size(); ++i)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                pStk.push(s[i]);
            }
            else
            {
                if(pStk.empty() || 
                    (s[i] == ')' && pStk.top() != '(') ||
                    (s[i] == ']' && pStk.top() != '[') ||
                    (s[i] == '}' && pStk.top() != '{'))
                {
                    return false;
                }
                
                pStk.pop();
            }
        }
        
        return pStk.empty();
    }
};