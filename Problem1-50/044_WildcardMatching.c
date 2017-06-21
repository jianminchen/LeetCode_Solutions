bool isMatch(char* s, char* p) {
    char *pSave, *sSave;
    
    pSave = sSave = NULL;
    
    while(*s)
    {
        if(*p == '?' || *p == *s)
        {
            p++;
            s++;
            continue;
        }
        else if(*p == '*')
        {
            pSave = ++p;
            sSave = s;
        }
        else if(pSave)
        {
            p = pSave;
            s = ++sSave;
        }
        else
        {
            return false;
        }
    }
    
    while(*p == '*')
    {
        p++;
    }
    return !*p;
}