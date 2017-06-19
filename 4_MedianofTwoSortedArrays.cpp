class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double  res = 0.0,
                save = 0.0;
        int     total = 0,
                n = (int)nums1.size()+(int)nums2.size();
        
        for(int idx1 = 0, idx2 = 0; idx1<nums1.size() || idx2<nums2.size(); )
        {
            if(idx1 == nums1.size() ||(idx2<nums2.size() && nums1[idx1]>=nums2[idx2]))
            {
                res = nums2[idx2];
                ++idx2;
                ++total;
            }
            else
            {
                res = nums1[idx1];
                ++idx1;
                ++total;
            }
            
            if(n&1)
            {
                if(total == n/2+1)
                {
                    return res;
                }
            }
            else
            {
                if(total == n/2)
                {
                    save = res;
                }
            
                if(total == n/2+1)
                {
                    return (save+res)/2.0;
                }
            }
        }
    }
};