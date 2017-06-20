int longestValidParentheses(char* s) {
    int     sLen = strlen(s),
            curMax = 0,
            retMax = 0,
            popLen = 0,
            stackLen = 0;
    
    while(*s)
    {
        if(*s == '(')
        {
            stackLen ++;
        }
        else
        {
            if(stackLen == 0)
            {
                curMax = 0;
            }
            
            if(stackLen > 0)
            {
                popLen ++;
                stackLen --;
            }
            
            if(stackLen == 0)
            {
                curMax += 2*popLen;
                retMax = retMax>curMax?retMax:curMax;
                popLen = 0;
            }
        }

        s++;
    }
    
    if(stackLen>0)
    {
        curMax = longestValidParentheses(s -(stackLen + 2*popLen-1));
        retMax = retMax>curMax?retMax:curMax;
    }
    
    return retMax;
}