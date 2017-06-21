int strStr(char* haystack, char* needle) {
    int     nLen = strlen(needle),
            hLen = strlen(haystack),
            i = 0;
    char    *p = NULL,
            *q = NULL;
    
    if(!nLen && !hLen)
    {
        return 0;
    }
    
    for(i = 0; i<=hLen-nLen; ++i)
    {
        p = haystack+i;
        q = needle;
        while(*q && *p == *q)
        {
            ++p;
            ++q;
        }
        if(!*q)
        {
            return i;
        }
    }
    
    return -1;
}