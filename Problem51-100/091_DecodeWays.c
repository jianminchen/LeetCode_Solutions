int numDecodings(char* s) {
    int len;
    int *DP;
    
    len = strlen(s);
    
    if(len == 0 || (len == 1 && *s == '0'))
    {
        return 0;
    }
    else if(len == 1)
    {
        return 1;
    }
    
    DP = (int *)malloc((len) * sizeof(int));
    
    if(*(s+len-1) =='0')
    {
        DP[len-1] = 0;
    }
    else
    {
        DP[len-1] = 1;
    }
    
    if(*(s+len-2) == '0')
    {
        DP[len-2] = 0;
    }
    else if(*(s+len-2) == '1' || (*(s+len-2) == '2' && (*(s+len-1) - '0'+0<=6)))
    {
        DP[len-2] = DP[len-1]+1;
    }
    else
    {
        DP[len-2] = DP[len-1];
    }
    
    for(int i = len-3; i>=0; --i)
    {
        if(*(s+i) == '0')
        {
            DP[i] == 0;
        }
        else if(*(s+i) == '1' || (*(s+i) == '2' && (*(s+i+1) - '0'+0<=6)))
        {
            DP[i] = DP[i+1]+DP[i+2];
        }
        else
        {
            DP[i] = DP[i+1];
        }
    }
    
    return DP[0];
}