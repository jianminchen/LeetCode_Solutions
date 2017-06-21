bool isPalindrome(int x) {
    int in_x;
    long cvt_x;

    cvt_x = 0;
    in_x = x;
    
    if(x<0)
    {
        return false;
    }
    
    while(in_x)
    {
        cvt_x = 10*cvt_x+in_x%10;
        in_x = in_x/10;
    }
    
    return (cvt_x==x);
}