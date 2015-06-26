#include<iostream>
#include<cassert>
#include<vector>

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

