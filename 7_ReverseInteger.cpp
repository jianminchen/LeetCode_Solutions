class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);
        if(x<0)
        {
            std::reverse(s.begin()+1, s.end());
        }
        else
        {
            std::reverse(s.begin(), s.end());
        }
        
        long res = stol(s);
        if(res>INT_MAX || res<INT_MIN)
        {
            return 0;
        }
        else
        {
            return (int)res;
        }
    }
};