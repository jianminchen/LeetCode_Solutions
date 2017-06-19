char* convert(char* s, int numRows) {
    char    *retStr;
    int     len, blockSize, loopSize, i, row, idx, rest;
    
    len = strlen(s);
    if(numRows>len)
    {
        numRows = len;
    }

    if(numRows == 1)
    {
        return s;
    }
    
    retStr = (char *)malloc((len+1) * sizeof(char));
    blockSize = 2*numRows-2;
    loopSize = len/blockSize;
    rest = len%blockSize;
    
    for(i = 0, idx = 0; i<loopSize; ++i)
    {
        retStr[idx] = s[i*blockSize];
        idx++;
    }
    
    if(rest)
    {
        retStr[idx] = s[i*blockSize];
        idx++;
    }
    
    for(row = 1; row<numRows-1; ++row)
    {
        for(i=0; i<loopSize; ++i)
        {
            retStr[idx] = s[i*blockSize+row];
            idx++;
            retStr[idx] = s[i*blockSize+blockSize-row];
            idx++;
        }
        
        if(rest>blockSize-row)
        {
            retStr[idx] = s[i*blockSize+row];
            idx++;
            retStr[idx] = s[i*blockSize+blockSize-row];
            idx++;            
        }
        else if(rest>row)
        {
            retStr[idx] = s[i*blockSize+row];
            idx++;
        }
        
    }
    for(i = 0; i<loopSize; ++i)
    {
        retStr[idx] = s[i*blockSize+numRows-1];
        idx++;
    }
    if(rest>numRows-1)
    {
        retStr[idx] = s[i*blockSize+numRows-1];
    }
    
    retStr[len] = '\0';
    
    return retStr;
}