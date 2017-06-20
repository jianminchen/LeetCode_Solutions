class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
        {
            return "";
        }
        
        string res = strs[0];
        for(int i = 1; i<strs.size(); ++i)
        {
            int j = 0;
            string tmp = "";
            while(j<res.size() && j<strs[i].size())
            {
                if(res[j] == strs[i][j])
                {
                    tmp.push_back(res[j]);
                    ++j;
                }
                else
                {
                    break;
                }
            }
            
            res = tmp;
        }
        
        return res;
    }
};