int climbStairs(int n) {
    int *PD;
    
    if(n<=2)
    {
        return n;
    }
    PD = (int *)malloc(n*sizeof(int));
    PD[0] = 1;
    PD[1] = 2;
    
    for(int i=2; i<n;++i)
    {
        PD[i] = PD[i-1]+PD[i-2];
    }
    
    return PD[n-1];
}