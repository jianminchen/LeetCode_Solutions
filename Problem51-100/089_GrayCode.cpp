class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        stack<int>  stk;
        
        if(n == 0)
        {
            res.push_back(0);
            return res;
        }
        
        res = grayCode(n-1);
        
        for(int i=0; i<res.size(); ++i)
        {
            stk.push(res[i]);
        }
        
        while(!stk.empty())
        {
            int tmp = stk.top();
            stk.pop();
            tmp = tmp+(1<<(n-1));
            res.push_back(tmp);
        }
        
        return res;
    }
};