char* longestCommonPrefix(char** strs, int strsSize) {
    int i = 0,
        curMax = 0,
        curLen = 0,
        j = 0;
    char    *curStr = NULL,
            *ret = NULL;
    
    if(strsSize == 0)
    {
        return "";
    }
    
    curStr = strs[0];
    curMax = strlen(curStr);

    for(i=1; i<strsSize;i++)
    {
        curLen = 0;
        for(j=0;j<curMax;j++)
        {
            if(strs[i][j] == curStr[j])
            {
                curLen++;
            }
            else
            {
                break;
            }
        }
        
        curStr = strs[i];
        curMax = curMax<curLen?curMax:curLen;
    }
    
    ret = (char *)malloc((curMax+1) * sizeof(char));
    for(i = 0;i<curMax;i++)
    {
        ret[i] = curStr[i];
    }
    ret[curMax] = '\0';
    
    return ret;
}