class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1)
        {
            return s;
        }
        
        vector<string>  save(numRows, "");
        string          res = "";
        
        int direct = 1,
            i = 0;
        for(auto c : s)
        {
            save[i].push_back(c);
            
            if(i == 0)
            {
                ++i;
                direct = 1;
            }
            else if(i == numRows-1)
            {
                --i;
                direct = -1;
            }
            else
            {
                i += direct;
            }
        }
        
        for(auto str : save)
        {
            res += str;
        }
        
        return res;
    }
};