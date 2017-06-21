class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ret = 0,
            cur = 0,
            curMin = INT_MAX;
        
        for(int k = nums.size()-1; k>1; k--)
        {
            for(int i = 0, j = k-1; i<j;)
            {
                cur = nums[i]+nums[j]+nums[k];
                if(abs(cur-target)<curMin)
                {
                    curMin = abs(cur-target);
                    ret = cur;
                }
                
                if(cur-target>0)
                {
                    j--;
                }
                else if(cur-target<0)
                {
                    i++;
                }
                else
                {
                    return ret;
                }
            }
        }
        
        return ret;       
    }
};