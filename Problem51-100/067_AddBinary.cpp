class Solution {
public:
    string addBinary(string a, string b) {
        string  res;
        int     aIdx = a.size()-1,
                bIdx = b.size()-1,
                add = 0;
                
        while(aIdx>=0 || bIdx>=0)
        {
            int num = add;
            if(aIdx>=0)
            {
                num += a[aIdx]-'0';
                --aIdx;
            }
            if(bIdx>=0)
            {
                num += b[bIdx]-'0';
                --bIdx;
            }
            add = num/2;
            num = num%2;
            res.insert(res.begin(), num+'0');
        }
        if(add)
        {
            res.insert(res.begin(), add+'0');
        }
        return res;
    }
};