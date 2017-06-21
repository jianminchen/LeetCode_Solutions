class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int>     leftArr;
        string          res;
        
        int level = 0,
			total = 1;

        for(int i=1; i<n; ++i)
        {
            leftArr.push_back(i);
            total *= i;
        }
        
        leftArr.push_back(n);
        
        while(leftArr.size()>1)
        {
            level =  (k-1)/total;
            res.push_back(leftArr[level]+'0');
            leftArr.erase(leftArr.begin()+level);
            k -= level*total;
            total = total/leftArr.size();
        }
        
        res.push_back(leftArr[0]+'0');
        return res;
    }
};