#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

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
    std::vector<Interval> merge(std::vector<Interval>& intervals)
    {
        std::vector<Interval> res;
        auto sz=intervals.size();
        if(sz==0) return res;

        auto comp = [](const Interval& l, const Interval& r)
                { return l.start<r.start; };

        std::sort(intervals.begin(), intervals.end(), comp);

        int start;
        int end;

        auto newInterval = intervals[0];
        for(size_t i=1; i<sz; ++i)
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

    std::vector<Interval> intervals{{2,3},{4,5},{6,7},{8,9},{1,10}};
    auto v = s.merge(intervals);

    for(const auto& interval : v)
        std::cout<<"["<<interval.start<<","<<interval.end<<"]"<<" ";

    std::cout<<std::endl;
    return 0;
}

