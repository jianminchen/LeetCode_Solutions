int reverse(int x) {
    int ten = 0,
        digit = 0,
        ret = 0,
        len = 0;

    ten = x/10;
    digit = x%10;
    ret = digit;
    len = 1;
    
    while(ten)
    {
        len++;
        digit = ten%10;
        ten = ten/10;
        
        if((len > 10) || (len == 10 && ((ret>214748364 || (ret== 214748364 && digit>7)|| ((ret< -214748364 || (ret== -214748364 && digit>8)))))))
        {
            return 0;
        }

        ret = 10*ret+digit;
    }
    
    return ret;
}