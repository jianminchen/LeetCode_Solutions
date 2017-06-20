class Solution {
public:
    string countAndSay(int n) {
        string  res = "",
                resN_1 = "";
        int     i =0,
                count = ;
        char    last;
        
        if(n==0)
        {
            return "";
        }
        if(n==1)
        {
            return "1";
        }
        
        resN_1 = countAndSay(n-1);
        last = resN_1[0];
        count = 1;
        for(i = 1; i<resN_1.size();++i)
        {
            if(resN_1[i] == last)
            {
                count++;
            }
            else
            {
                res.push_back(count-0+'0');
                res.push_back(last);
                last = resN_1[i];
                count = 1;
            }
        }
        
        res.push_back(count-0+'0');
        res.push_back(last);
        return res;
    }
};