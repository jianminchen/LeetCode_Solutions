char* addBinary(char* a, char* b) {
    int aLen, bLen, longerLen, shorterLen, i, sum, plusOne;
    char *res, *longer, *shorter;

    while(*a == '0')
    {
        ++a;
    }
    while(*b == '0')
    {
        ++b;
    }
    aLen = strlen(a);
    bLen = strlen(b);
    if(!aLen && !bLen)
    {
        return "0";
    }
    
    longer = aLen>bLen?a:b;
    shorter = aLen<=bLen?a:b;
    longerLen = aLen>bLen?aLen:bLen;
    shorterLen = aLen<=bLen?aLen:bLen;
    plusOne = 0;
    
    res = (int *)malloc((longerLen+2) * sizeof(int));
    res[longerLen+1] = '\0';
    
    for(i=0;i<shorterLen;++i)
    {
        sum = (longer[longerLen-1-i]-'0'+0)+(shorter[shorterLen-1-i]-'0'+0)+plusOne;
        res[longerLen-i] = sum%2+'0';
        plusOne = sum/2;
    }
    
    for(i=shorterLen;i<longerLen;++i)
    {
        sum = (longer[longerLen-1-i]-'0'+0)+plusOne;
        res[longerLen-i] = sum%2+'0';
        plusOne = sum/2;
    }
    
    if(plusOne)
    {
        res[0] = '1';
        return res;
    }
    else
    {
        return res+1;
    }
}