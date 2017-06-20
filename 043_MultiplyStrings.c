char* multiply(char* num1, char* num2) {
    int numLen1 = strlen(num1),
        numLen2 = strlen(num2),
        i = 0,
        j = 0,
        mul1 = 0,
        mul2 = 0;
    int *saveRes = NULL;
    char *res = NULL;
    
    if(!(num1[0] - '0' + 0) || !(num2[0] - '0' +0))
    {
        return "0";
    }
    
    saveRes = (int *)malloc((numLen1+numLen2) *sizeof(int));
    memset(saveRes, 0, (numLen1+numLen2) *sizeof(int));
    res = (char *)malloc(numLen1+numLen2+1);
    res[numLen1+numLen2] = '\0';
    
    for(i = numLen1-1; i>=0; i--)
    {
        mul1 = num1[i] - '0' + 0;
        for(j = numLen2-1; j>=0; j--)
        {
            mul2 = num2[j] - '0' + 0;
            saveRes[i+j+1] += mul1*mul2;
        }
    }
    
    for(i = numLen1+numLen2-1; i>=1; i--)
    {
        saveRes[i-1] += saveRes[i]/10;
        saveRes[i] = saveRes[i]%10;
    }
    
    while(!saveRes[i])
    {
        i++;
    }
    
    for(j = 0; i<numLen1+numLen2; i++)
    {
        
        res[j] = saveRes[i] + '0';
        j++;
    }
    
    res[j] = '\0';
    
    return res;
}