class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string>  res;
        
        res = resSub(s, 4);
        
        return res;
    }
    
    vector<string> resSub(string s, int num)
    {
        vector<string>  res, 
                        res1;
        string          save,
                        prefix;
        int             len,
                        resSize,
                        range;
        
        len = s.size();
        if(len >3*num || len<num)
        {
            return res;
        }
        
        if(num==1)
        {
            if(isValidIP(s))
            {
                res.push_back(s);
            }
            
            return res;
        }
        
        range = len>=3?3:len;
        
        for(int k = 1; k<=range; ++k)
        {
            prefix = s.substr(0,k);
            if(isValidIP(prefix))
            {
                res1 = resSub(s.substr(k, len-k), num-1);
                if(!res1.empty())
                {
                    resSize = res1.size();
                    for(int i = 0; i<resSize;++i)
                    {
                        save = prefix + '.'+res1[i];
                        res.push_back(save);
                    }
                }
            }
        }

        return res;
    }
    
    bool isValidIP(string s)
    {
        if(s.size()==1
            || (s.size()==2 && s[0] != '0'))
        {
            return true;
        }
        
        if(s.size() == 3)
        {
            if(s[0] == '1')
            {
                return true;
            }
            if(s[0] == '2' && (s[1]-'0'+0<5
                || (s[1]-'0'+0==5 && s[2]-'0'+0<=5)))
            {
                return true;
            }
        }
        return false;
    }
};