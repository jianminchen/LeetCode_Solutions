class Solution {
public:
    int trap(vector<int>& height) {
        stack<int>  idxStk;
        int         res = 0;
        
        idxStk.push(0);
        for(int i=1; i<height.size(); ++i) {
            if(height[i]<=height[idxStk.top()]) {
                idxStk.push(i);
            }
            else {
                if(idxStk.size()==1) {
                    idxStk.pop();
                    idxStk.push(i);
                }
                else {
                    while(!idxStk.empty() && height[i]>height[idxStk.top()]) {
                        int h = height[idxStk.top()];
                        idxStk.pop();
                        if(!idxStk.empty()) {
                            int rh= min(height[i], height[idxStk.top()])-h;
                            res += rh*(i-idxStk.top()-1);
                        }
                    }
                    idxStk.push(i);
                }
            }
        }
        
        return res;
    }