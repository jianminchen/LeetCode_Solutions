int lengthOfLastWord(char* s) {
    int i,
        len;
    
    len = 0;
    for(i = strlen(s)-1; i>=0;--i)
    {
        if(s[i] != ' ')
        {
            ++len;
        }
        else if(len>0)
        {
            break;
        }
    }
    
    return len;
}