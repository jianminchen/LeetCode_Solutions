class Solution {
public:
    string simplifyPath(string path) {
        string          res, tmp;
        stringstream    ckPath(path);
        vector<string>  save;
        
        res = "";
        while(getline(ckPath, tmp, '/'))
        {
            if(tmp == "" || tmp == ".")
            {
                continue;
            }
            if(tmp == ".." && !save.empty())
            {
                save.pop_back();
            }
            else if(tmp != "..")
            {
                save.push_back(tmp);
            }
        }
        
        for(int i = 0; i<save.size(); ++i)
        {
            res += '/'+save[i];
        }
        
        if(!save.size())
        {
            res = "/";
        }
        
        return res;
    }
};