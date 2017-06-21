class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int>              tMap;
        int                         i, j, m, curMin;
        string                      res;
        map<char, int>::iterator    it;
        pair<int, int>              range;
        int                         leftNum;
        
        if(t.size() == 0 || s.size()<t.size())
        {
            return "";
        }
        
        curMin = INT_MAX;
        for(i = 0; i<t.size(); ++i)
        {
            if(tMap.find(t[i]) == tMap.end())
            {
                tMap[t[i]] = 1;
            }
            else
            {
                ++tMap[t[i]];
            }
        }
        
        leftNum = tMap.size();
        
        j = i = 0;
        while(i<=s.size()-t.size())
        {
            if(tMap.find(s[i]) == tMap.end())
            {
                ++i;
                continue;
            }
            
            if(j<i)
            {
                j = i;
            }
            
            while(j<s.size())
            {
                if(tMap.find(s[j]) != tMap.end())
                {
                    --tMap[s[j]];
                    if(tMap[s[j]] == 0)
                    {
                        --leftNum;
                    }
                }
                
                if(j-i+1<t.size() || tMap.find(s[j]) == tMap.end())
                {
                    ++j;
                    continue;
                }
                
                if(leftNum == 0)
                {
                    break;
                }
                
                ++j;
            }
            
            while(i<=j && leftNum == 0)
            {
                if(tMap.find(s[i]) == tMap.end())
                {
                    ++i;
                    continue;
                }
                
                if((j-i+1)<curMin)
                {
                    range = make_pair(i,j);
                    curMin = j-i+1;
                }
                
                ++tMap[s[i]];
                if(tMap[s[i]]>0)
                {
                    ++leftNum;
                    ++j;
                    break;
                }
                ++i;
            }
            
            ++i;

        }
        
        if(curMin < INT_MAX)
        {
            for(int k = range.first; k<=range.second;++k)
            {
                res.push_back(s[k]);
            }
        }
        
        return res;
    }
};