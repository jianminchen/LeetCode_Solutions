bool isMatch(char* s, char* p) {
    while(*s)
    {
        if(*p&& *(p+1) == '*')
        {
            if(*p != *s && *p != '.')
            {
                p += 2;
                continue;
            }
            if(!isMatch(s,p+2))
            {
                s++;
                continue;
            }
            else
            {
                return true;
            }
        }
        else if(*p==*s || *p == '.')
        {
            s++;
            p++;
            continue;
        }
        else
        {
            return false;
        }
    }
    
    while(*p && *(p+1) == '*')
    {
        p += 2;
    }
    
    return !*p;
}