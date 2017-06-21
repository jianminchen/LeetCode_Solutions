class Solution {
public:
    string multiply(string num1, string num2) {
        vector<int> result(220, 0);
        string      res = "";
        int         len1 = num1.size(),
                    len2 = num2.size();
        
        for(int i = 0; i<num1.size(); ++i)
        {
            int mul1 = num1[len1-i-1]-'0';
            int add = 0;
            for(int j = 0; j<num2.size(); ++j)
            {
                int mul2 = num2[len2-j-1]-'0';
                int tmp = mul1*mul2+add;
                add = tmp/10;
                result[i+j] += tmp%10;
            }
            if(add)
            {
                result[i+num2.size()] += add;
            }
        }
        
        int rest = 0;
        for(int i= 0; i<result.size(); ++i)
        {
            int tmp = rest+result[i];
            result[i] = tmp%10;
            rest = tmp/10;
        }
        
        int end = result.size()-1;
        while(end>=0 && result[end] == 0)
        {
            --end;
        }
        
        if(end < 0)
        {
            return "0";
        }
        else
        {
            while(end>=0)
            {
                res.push_back(result[end]+'0');
                --end;
            }
            return res;
        }
    }
};