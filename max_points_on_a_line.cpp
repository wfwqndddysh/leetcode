#include<iostream>
#include<cassert>
#include<vector>
#include<map>

struct Point
{
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

/*
 想到了用斜率，
 想到了hash/map计数
 想到了用最简分数做key
 想到了分数化简使用gcd
 想到了垂直线特殊处理

 没想到重复点的处理
 没想到其实只要使用斜率k做key，而不用管b
*/
//想到了用斜率，想到了
class Solution
{
public:
    int maxPoints(std::vector<Point>& points)
    {
        auto sz=points.size();
        if(sz<=1) return sz;

        int max_cnt = 0;
        for(size_t i=0; i<sz; ++i)
        {
            int local_max = 0;
            int vertical = 0;
            int overlap = 0;
            std::map<std::pair<int, int>, int> slope2cnt;
            for(size_t j=i+1; j<sz; ++j)
            {
                if(points[j].x==points[i].x && points[j].y==points[i].y)
                {
                    overlap++;
                }
                else if(points[j].x==points[i].x)
                {
                    vertical++;
                }
                else
                {
                    int numerator = points[j].y - points[i].y;
                    int denominator = points[j].x - points[i].x;
                    int gcd = gcd_internal(numerator, denominator);
                    numerator /= gcd;
                    denominator /= gcd;

                    auto key = std::make_pair(numerator, denominator);
                    local_max = std::max(local_max, ++slope2cnt[key]);
                }
            }

            local_max = std::max(local_max, vertical);
            max_cnt = std::max(max_cnt, local_max+overlap+1);
        }
        return max_cnt;
    }
private:
    int gcd_internal(int a, int b)
    {
        if(b==0) return a;
        else return gcd_internal(b, a%b);
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

