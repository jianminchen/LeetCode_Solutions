class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>  stk;
        int         i,
                    maxArea;
        heights.push_back(0);
        i = maxArea = 0;
        while(i<heights.size())
        {
            if(stk.empty() || heights[i]>heights[stk.top()])
            {
                stk.push(i);
                ++i;
            }
            else
            {
                int tmp;
                tmp = stk.top();
                stk.pop();
                
                if(stk.empty())
                {
                    maxArea = maxArea>i*heights[tmp]?maxArea:i*heights[tmp];
                }
                else
                {
                    maxArea = maxArea>heights[tmp]*(i-stk.top()-1)?maxArea:heights[tmp]*(i-stk.top()-1);
                }
            }
        }
        
        return maxArea;
    }
};