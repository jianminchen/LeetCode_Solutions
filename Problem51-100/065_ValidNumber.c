#define HAS_MID_E           0x00000001
#define HAS_DOT             0x00000002
#define HAS_NUM             0x00000004

bool isNumber(char* s) {
    int len, num;
    int state;
    
    len = strlen(s);
    state  = 0;
    
    while(*s == ' ')
    {
        ++s;
    }
    
    if(*s == '+' || *s == '-')
    {
        ++s;
    }
    
    if(*s == 'e')
    {
        return false;
    }
    
    while(*s && *s != ' ')
    {
        if(*s == 'e')
        {
            if(state & HAS_MID_E || !(state & HAS_NUM))
            {
                return false;
            }
            else
            {
                state |= HAS_MID_E;
                state &= ~HAS_NUM;
                if(*(s+1) && (*(s+1) == '+' || *(s+1) == '-'))
                {
                    ++s;
                }
            }
        }
        else if(*s == '.')
        {
            if(state & HAS_DOT)
            {
                return false;
            }
            if(state & HAS_MID_E)
            {
                return false;
            }
            state |= HAS_DOT;
            
        }
        else
        {
            num = *s - '0' + 0;
            if(num<0 || num>9)
            {
                return false;
            }
            state |= HAS_NUM;
        }
        ++s;
    }
    
    while(*s == ' ')
    {
        ++s;
    }
    
    return !*s && (state & HAS_NUM);
}