class Solution {
public:
    bool isMatch(string s, string p) {
        int sidx = 0,
            pidx = 0,
            orgpidx = -1,
            orgsidx = -1;
        
        while(sidx<s.size())
        {
            if(pidx<p.size() && (p[pidx] == s[sidx] || p[pidx] == '?'))
            {
                ++pidx;
                ++sidx;
            }
            else if(pidx<p.size() && p[pidx] == '*')
            {
                orgpidx = pidx;
                ++pidx;
                orgsidx = sidx;
            }
            else
            {
                if(orgpidx > -1)
                {
                    pidx = orgpidx+1;
                    ++orgsidx;
                    sidx = orgsidx;
                }
                else
                {
                    return false;
                }
            }
        }
        
        while(pidx<p.size() && p[pidx] == '*')
        {
            ++pidx;
        }
        
        return pidx == p.size();
    }
};