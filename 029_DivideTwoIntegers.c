int divide(int dividend, int divisor) {
    int     ret = 0,
            sign = 0,
            idx = 0;
    long    dvd = 0,
            dvs = 0,
            tmp = 0;

    if(!divisor || (dividend == INT_MIN && divisor == -1 ))
    {
        return INT_MAX;
    }
    
    if((dividend< 0 && divisor >0)
        ||(dividend>0 && divisor<0))
    {
        sign = 1;
    }
    
    dvd = labs(dividend);
    dvs = labs(divisor);
    
    while(dvd >= dvs)
    {
        idx = 1;
        tmp = dvs;
        while(dvd>= (tmp<<1))
        {
            idx <<= 1;
            tmp <<= 1;
        }
        dvd -= tmp;
        ret += idx;
    }
    
    if(sign)
    {
        ret = -ret;
    }
    
    return ret;
}