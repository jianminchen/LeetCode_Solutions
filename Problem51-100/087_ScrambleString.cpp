class Solution {
public:
    bool isScramble(string s1, string s2) {
        return checkSubstr(s1, s2, s1.size());
    }
    
    bool checkSubstr(string s1, string s2, int len)
    {
        if(len == 1)
        {
            return s1[0] == s2[0];
        }
        if(len == 2)
        {
            return (s1[0] == s2[0] && s1[1] == s2[1])
                    || (s1[0] == s2[1] && s1[1] == s2[0]);
        }

        string cs1 = s1;
        string cs2 = s2;
        
        sort(cs1.begin(), cs1.end());
        sort(cs2.begin(), cs2.end());
        
        for(int i = 0; i<len;++i)
        {
            if(cs1[i] != cs2[i])
            {
                return false;
            }
        }

        for(int i=1; i<len; ++i)
        {
            if((checkSubstr(s1.substr(0,i), s2.substr(0,i), i)
                && (checkSubstr(s1.substr(i,len-i), s2.substr(i, len-i), len-i)))
                || (checkSubstr(s1.substr(0, i), s2.substr(len-i, i), i)
                && (checkSubstr(s1.substr(i, len-i), s2.substr(0,len-i), len-i))))
            {
                return true;
            }
        }
        return false;
    }
};