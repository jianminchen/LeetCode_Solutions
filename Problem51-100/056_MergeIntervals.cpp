/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> res;
        
        sort(intervals.begin(), intervals.end(), cmp);
        while(!intervals.empty())
        {
            int s = (*intervals.begin()).start;
            int e = (*intervals.begin()).end;
            intervals.erase(intervals.begin());
            
            while(!intervals.empty() && (*intervals.begin()).start<=e)
            {
                e = max(e, (*intervals.begin()).end);
                intervals.erase(intervals.begin());
            }
            
            Interval *newOne = new Interval(s,e);
            res.push_back(*newOne);
        }
        
        return res;
    }
    
    static bool cmp(Interval &a, Interval &b)
    {
        if(a.start == b.start)
        {
            return a.end>b.end;
        }
        else
        {
            return a.start<b.start;
        }
    }
};