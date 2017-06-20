class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s, 0, p, 0);
    }
    
    bool match(string &s, int sIdx, string &p, int pIdx)
    {
        while(sIdx<s.size())
        {
            if(pIdx+1<p.size() && p[pIdx+1] == '*')
            {
                if(p[pIdx] != s[sIdx] && p[pIdx] != '.')
                {
                    pIdx += 2;
                    continue;
                }
                if(!match(s, sIdx, p, pIdx+2))
                {
                    ++sIdx;
                    continue;
                }
                else
                {
                    return true;
                }
            }
            else if(p[pIdx] == s[sIdx] || p[pIdx] == '.')
            {
                ++pIdx;
                ++sIdx;
                continue;
            }
            else
            {
                return false;
            }
        }
        
        while(pIdx+1<p.size()  && p[pIdx+1] == '*')
        {
            pIdx +=2;
        }
        
        return pIdx == p.size();
    }
};