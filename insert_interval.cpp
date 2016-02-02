#include<iostream>
#include<cassert>
#include<vector>

/*
 * Given a set of non-overlapping intervals, insert a new interval into the 
 * intervals (merge if necessary).
 *
 * You may assume that the intervals were initially sorted according to their 
 * start times.
 *
 * Example 1:
 * Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
 *
 * Example 2:
 * Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
 *
 * This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
 */

struct Interval
{
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution
{
public:
    std::vector<Interval> insert(std::vector<Interval>& intervals, Interval newInterval)
    {
        std::vector<Interval> res;

        int start;
        int end;

        for(size_t i=0; i<intervals.size(); ++i)
        {
            if(newInterval.end<intervals[i].start)
            {
                res.push_back(newInterval);
                newInterval = intervals[i];
            }
            else if(newInterval.start>intervals[i].end)
            {
                res.push_back(intervals[i]);
            }
            else
            {
                start = std::min(newInterval.start, intervals[i].start);
                end = std::max(newInterval.end, intervals[i].end);
                newInterval = Interval(start, end);
            }
        }

        res.push_back(newInterval);

        return res;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

