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

class SolutionSort
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

        res.push_back(intervals[0]);
        for(size_t i=1; i<sz; ++i)
        {
            if(res.back().end<intervals[i].start)
            {
                res.push_back(intervals[i]);
            }
            else
            {
                res.back().end = std::max(res.back().end, intervals[i].end);
            }
        }

        return res;
    }
};

int main()
{
    SolutionSort s;

    std::vector<Interval> intervals{{1,4},{1,5}};
    auto v = s.merge(intervals);

    for(const auto& interval : v)
        std::cout<<"["<<interval.start<<","<<interval.end<<"]"<<" ";

    std::cout<<std::endl;
    return 0;
}

