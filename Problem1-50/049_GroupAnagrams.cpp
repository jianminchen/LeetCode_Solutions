class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mapStr;
        vector<vector<string>> res;
        string tmp;
        map<string, vector<string>>::iterator it;
        int i;
        
        for(i=0; i<strs.size(); i++)
        {
            tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            mapStr[tmp].push_back(strs[i]);
        }
        
        for(it = mapStr.begin(); it != mapStr.end(); ++it)
        {
            vector<string>  mapRes;
            mapRes = it->second;
            sort(mapRes.begin(), mapRes.end());
            res.push_back(mapRes);
        }
        
        return res;
    }
};