int numTrees(int n) {
    int DP[n];
    int i,j;
    
    if(n <= 1)
    {
        return n;
    }
    
    DP[0] = 1;
    for(i = 1; i<n; ++i)
    {
        DP[i] = 2*DP[i-1];
        for(j = 0; j<i-1;++j)
        {
            DP[i] += DP[j]*DP[i-2-j];
        }
    }
    return DP[n-1];
}