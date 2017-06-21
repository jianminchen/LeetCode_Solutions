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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        int newStart = newInterval.start,
            newEnd = newInterval.end,
            i = 0,
            pos = -1;
            
        stack<int> idxStk;
        for(; i<intervals.size(); ++i)
        {
            if((intervals[i].start<=newStart && intervals[i].end>=newStart)
                || (intervals[i].start<=newEnd && intervals[i].end>=newEnd)
                || (intervals[i].start>=newStart && intervals[i].end<=newEnd))
            {
                idxStk.push(i);
                if(pos == -1)
                {
                    pos = i;
                }
                newStart = min(newStart, intervals[i].start);
                newEnd = max(newEnd, intervals[i].end);
            }
            else if(intervals[i].start>newEnd)
            {
                break;
            }
        }
        
        if(pos == -1)
        {
            pos = i;
        }
        
        while(!idxStk.empty())
        {
            intervals.erase(intervals.begin()+idxStk.top());
            idxStk.pop();
        }
        
        Interval *newOne = new Interval(newStart, newEnd);
        intervals.insert(intervals.begin()+pos, *newOne);

        return intervals;
    }
};