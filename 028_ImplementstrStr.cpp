class Solution {
public:
    int strStr(string haystack, string needle) {
        int nLen = needle.size(),
            idx = 0;
            
        while(idx+nLen<=haystack.size())
        {
            if(haystack.substr(idx, nLen) == needle)
            {
                return idx;
            }
            else
            {
                ++idx;
            }
        }
        return -1;
    }
};