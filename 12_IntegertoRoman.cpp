class Solution {
public:
    string intToRoman(int num) {
        int             h = 0,
                        t = 0;
        string          res = "";
        
        vector<vector<string>>  roman = {{"I","II","III","IV","V","VI","VII","VIII","IX"},
                                        {"X","XX","XXX","XL","L","LX","LXX","LXXX","XC"},
                                        {"C","CC","CCC","CD","D","DC","DCC","DCCC","CM"}};

        h = num/1000;
        t = num%1000;
        
        while(h)
        {
            res.push_back('M');
            --h;
        }
        
        h = t/100;
        t = t%100;
        
        if(h)
        {
            res += roman[2][h-1];
        }
        
        h = t/10;
        t = t%10;
        
        if(h)
        {
            res += roman[1][h-1];
        }
        
        if(t)
        {
            res += roman[0][t-1];
        }
        
        return res;
    }
};