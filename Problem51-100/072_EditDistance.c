int minDistance(char* word1, char* word2) {
    int len1, len2, i, j, cost;

    len1 = strlen(word1);
    len2 = strlen(word2);
    
    int DP[len1+1][len2+1];
    
    for(i = 0; i<len1+1; ++i)
    {
        DP[i][0] = i;
    }
    
    for(j = 0; j<len2+1; ++j)
    {
        DP[0][j] = j;
    }
    
    for(i = 1; i<len1+1; i++)
    {
        for(j = 1; j<len2+1; j++)
        {
            if(word1[i-1] == word2[j-1])
            {
                cost = DP[i-1][j-1];
            }
            else
            {
                cost = DP[i-1][j-1] + 1;
            }
            cost = cost<(DP[i-1][j]+1)?cost:(DP[i-1][j]+1);
            cost = cost<(DP[i][j-1]+1)?cost:(DP[i][j-1]+1);
            DP[i][j] = cost;
        }
    }
    return DP[len1][len2];
}