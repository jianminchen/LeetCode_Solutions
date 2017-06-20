class Solution {
public:
    int romanToInt(string s) {
        map<char,int>   charToInt;
        int             res = 0;
        
        charToInt['I'] = 1;
        charToInt['V'] = 5;
        charToInt['X'] = 10;
        charToInt['L'] = 50;
        charToInt['C'] = 100;
        charToInt['D'] = 500;
        charToInt['M'] = 1000;

        res = charToInt[s[0]];
        for(int i = 0; i<s.size()-1; ++i)
        {
            if(charToInt[s[i+1]]>charToInt[s[i]])
            {
                res += charToInt[s[i+1]] - 2*charToInt[s[i]];
            }
            else
            {
                res += charToInt[s[i+1]];
            }
        }
        
        return res;
    }
};