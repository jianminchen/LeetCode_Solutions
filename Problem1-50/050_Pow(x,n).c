double calPow(double x, int n)
{
    double   t = 0;
    
    if(n==0)
    {
        return 1;
    }
    
    t = calPow(x, n/2);

    if(n%2)
    {
        return x*t*t;
    }
    else
    {
        return t*t;
    }
}


double myPow(double x, int n) {
    if(n<0)
    {
        x=1.0/x;
        n = -n;
    }
    
    return calPow(x,n);
}