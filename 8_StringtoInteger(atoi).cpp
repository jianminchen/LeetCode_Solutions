class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        while(i<str.size() && str[i] == ' ')
        {
            ++i;
        }
        
        int sign = 1;
        if(i<str.size() && str[i] == '+')
        {
            sign = 1;
            ++i;
        }
        else if(i<str.size() && str[i] == '-')
        {
            sign = -1;
            ++i;
        }
        
        long res = 0;
        while(i<str.size())
        {
            if(str[i]>='0' && str[i]<='9')
            {
                res = 10*res+(str[i]-'0');
                ++i;
                if(sign == 1 && res>INT_MAX)
                {
                    return INT_MAX;
                }
                else if(sign == -1 && sign*res<INT_MIN)
                {
                    return INT_MIN;
                }
            }
            else
            {
                break;
            }
        }
        
        return sign == 1?(int)res:(int)(-res);
    }
};