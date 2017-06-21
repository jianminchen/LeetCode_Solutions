class Solution {
    static string letters[10];
    vector<string> res;
    
public:
    vector<string> letterCombinations(string digits) {
    if(digits.empty())
    {
        return res;
    }
        
    combineStr(digits, 0, "");
    return res;
    }
    
    void combineStr(string &digits, int i, string str)
    {
        if(i>=digits.size())
        {
            res.push_back(str);
            return;
        }
        
        int num = digits[i]-'0' + 0;
        string letter = letters[num];
        for(int j=0; j<letter.size(); j++)
        {
            combineStr(digits, i+1, str+letter[j]);
        }
    }
};

string Solution::letters[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};