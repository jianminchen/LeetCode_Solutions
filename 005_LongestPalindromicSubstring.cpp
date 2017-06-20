class Solution {
public:
    string longestPalindrome(string s) {
        int i = 0,
            curMax = 0,
            maxMid = 0,
            maxRL = 0,
            pos = 0;
        
        string  copyS = "#";
        string  res = "";
        for(int i = 0;i<s.size(); ++i)
        {
            copyS.push_back(s[i]);
            copyS += "#";
        }
        
        int len = copyS.size();
        vector<int> RL(len, 0);
        
        for(int i = 0; i<len; ++i)
        {
            if(i<maxRL)
            {
                RL[i] = min(maxRL-i, RL[2*pos-i]);
            }
            else
            {
                RL[i] = 1;
            }
            
            while(i-RL[i]>=0 && i-RL[i]<len 
                    && copyS[i-RL[i]] == copyS[i+RL[i]])
            {
                RL[i] += 1;
            }
            
            if(RL[i]+i-1>maxRL)
            {
                maxRL = RL[i]+i-1;
                pos = i;
            }
            
            if(RL[i]-1>curMax)
            {
                curMax = RL[i]-1;
                maxMid = i;
            }
        }
        
        for(int j = maxMid-curMax; j<=maxMid+curMax; ++j)
        {
            if(copyS[j] != '#')
            {
                res += copyS[j];
            }
        }
        
        return res;
    }
};