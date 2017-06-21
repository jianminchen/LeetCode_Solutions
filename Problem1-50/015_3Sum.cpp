class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ret;
        for(int k = nums.size()-1; k>1;k--)
        {
            if(k<nums.size()-1 && nums[k] == nums[k+1])
            {
                continue;
            }
            for(int i = 0, j = k-1; i<j;)
            {
                if(nums[i] + nums[j] + nums[k]>0 || (j+1<k && nums[j] == nums[j+1]))
                {
                    j--;
                }
                else if(nums[i] + nums[j] + nums[k]<0 || (i>0 && nums[i] == nums[i-1]))
                {
                    i++;
                }
                else
                {
                    ret.push_back({nums[i], nums[j], nums[k]});
                    i++;
                    j--;
                }
            }
        }
        
        return ret;
    }
};