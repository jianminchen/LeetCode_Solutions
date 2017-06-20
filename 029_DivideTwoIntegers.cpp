class Solution {
public:
    int divide(int dividend, int divisor) {
        int sign = 1,
            res = 0;
        
        if(divisor == 0 || (dividend == INT_MIN && divisor == -1))
        {
            return INT_MAX;
        }
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0))
        {
            sign = -1;
        }
        
        long    divd = labs((long)dividend),
                divs = labs((long)divisor);
        
        while(divd>=divs)
        {
            int     idx = 1;
            long    tmp = divs;
                
            while(divd>=(tmp<<1))
            {
                tmp <<= 1;
                idx <<= 1;
            }
            
            res += idx;
            divd -= tmp;
        }
        return (sign == -1)?(-res):res;
    }
};