bool isInterleave(char* s1, char* s2, char* s3) {
    int len1, len2, i, j;
    
    len1 = strlen(s1);
    len2 = strlen(s2);
    
    if(strlen(s3)!=len1+len2)
    {
        return false;
    }
    
    bool DP[len1+1][len2+1];
    
    DP[0][0] = true;

    for(i = 0; i<len1+1;++i)
    {
        for(j = 0; j<len2+1;++j)
        {
            if(i==0 && j>0)
            {
                DP[i][j] = DP[i][j-1]&&(*(s3+i+j-1) == *(s2+j-1));
            }
            else if(j == 0 && i>0)
            {
                DP[i][j] = DP[i-1][j] && (*(s3+i+j-1) == *(s1+i-1));
            }
            else if(i>0 && j>0)
            {
                DP[i][j] = DP[i-1][j]&&(*(s3+i+j-1) == *(s1+i-1)) 
                        ||  DP[i][j-1]&&(*(s3+i+j-1) == *(s2+j-1));
            }
        }
    }

    return DP[len1][len2];
}