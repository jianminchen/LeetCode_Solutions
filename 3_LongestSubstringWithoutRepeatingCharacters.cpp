class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> cSet;
        deque<char>         cQ;
        
        int res = 0;
        for(int i = 0; i<s.size(); ++i)
        {
            if(!cSet.count(s[i]))
            {
                cSet.insert(s[i]);
                cQ.push_back(s[i]);
                res = max(res, (int)cSet.size());
            }
            else
            {
                while(*cQ.begin() != s[i])
                {
                    char c = cQ.front();
                    cSet.erase(c);
                    cQ.pop_front();
                }
                
                cQ.pop_front();
                cQ.push_back(s[i]);
            }
        }
        
        return res;
    }
};