class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        map<int,int>    candidates;
        stack<int>      stk;
        int             curMax, newArea, height, len;
        
        if(matrix.size()<1)
        {
            return 0;
        }
        
        for(int k=0; k<matrix[0].size()+1; ++k)
        {
            candidates[k] = 0;
        }
        
        curMax = 0;
        for(int i = 0; i<matrix.size();++i)
        {
            height = len =0;
            for(int j=0; j<matrix[i].size();++j)
            {
                if(matrix[i][j] == '1')
                {
                    candidates[j] ++;
                }
                else
                {
                    candidates[j] = 0;
                }
            }
            
            int m = 0;
            
            while(m<matrix[0].size()+1)
            {
                if(stk.empty() || candidates[stk.top()]<candidates[m])
                {
                    stk.push(m);
                    ++m;
                    continue;
                }
                else
                {
                    int tmp = stk.top();
                    stk.pop();
                    if(stk.empty())
                    {
                        len = m;
                    }
                    else
                    {
                        len = m-stk.top()-1;
                    }
                    
                    newArea = candidates[tmp]*len;
                    curMax = curMax>newArea?curMax:newArea;
                }
            }
            
            while(!stk.empty())
            {
                stk.pop();
            }
        }
        
        return curMax;
    }
};