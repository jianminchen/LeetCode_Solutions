char* longestPalindrome(char* s) {
    int len = 0,
        idx = 0,
        sameLen = 0,
        curMax = 0,
        beginMax = 0,
        retMax = 0,
        curBegin = 0;
        
    char *retStr= NULL;
        
    len = strlen(s);
    retStr = NULL;
    retMax = beginMax = 0;
    sameLen = 0;
    
    for(idx = 0; idx+retMax/2<len;)
    {
        curMax = 0;
        while((s[idx] == s[idx+sameLen]) && (idx+sameLen <len))
        {
            sameLen ++;
        }
        
        while((idx>=curMax+1) && (idx+curMax+sameLen<len) &&
            (s[idx+sameLen + curMax] == s[idx-curMax-1]))
        {
            curMax++;
        }
        
        curBegin = idx-curMax;

        curMax = 2*curMax+sameLen;
        
        if(curMax>retMax)
        {
            retMax = curMax;
            beginMax = curBegin;
        }
        
        idx += sameLen;
        
        sameLen = 0;
    }
    
    retStr = (char *)malloc((retMax+1) * sizeof(char));
    for(idx = 0; idx<retMax; idx++)
    {
        retStr[idx] = s[beginMax+idx];
    }
    retStr[retMax] = '\0';
    
    return retStr;
}