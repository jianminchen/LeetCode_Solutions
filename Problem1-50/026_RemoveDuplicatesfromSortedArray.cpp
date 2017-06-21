class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<=1)
        {
            return nums.size();
        }
        
        int i = 1,
            lastNum = nums[0];
        while(i<nums.size())
        {
            if(nums[i] == lastNum)
            {
                nums.erase(nums.begin()+i);
            }
            else
            {
                lastNum = nums[i++];
            }
        }
        return nums.size();
    }
};