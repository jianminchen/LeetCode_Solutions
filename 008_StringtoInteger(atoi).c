int myAtoi(char* str) {
    long ret = 0;
    int sign = 0;
    
    ret = 0;
    sign = 1;
    while(isspace(*str))
    {
        str++;
    }

    if(*str == '+' || *str == '-')
    {
        sign = (*str == '+')? 1:0;
        str++;
    }
    
    if(!isdigit(*str))
    {
        return 0;
    }
    
    while(isdigit(*str) && (ret<=INT_MAX))
    {
        ret = 10*ret+(*str-'0'+0);
        str++;
    }
    
    if(ret>INT_MAX)
    {
        ret = (sign==1)?INT_MAX : INT_MIN;
    }
    
    ret = (sign==1)?ret:-ret;
    
    return ret;
}