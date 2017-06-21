class Solution {
public:
    int maxArea(vector<int>& height) {
        int leftIdx = 0,
            rightIdx = height.size()-1,
            res = 0;
            
        while(leftIdx<rightIdx)
        {
            int h = min(height[leftIdx], height[rightIdx]);
            res = max(res, (rightIdx-leftIdx)*h);
            if(height[leftIdx]>=height[rightIdx])
            {
                --rightIdx;
            }
            else
            {
                ++leftIdx;
            }
        }
        
        return res;
    }
};