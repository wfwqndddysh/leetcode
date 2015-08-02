#include<iostream>
#include<cassert>
#include<vector>

class SolutionDivideConquer
{
public:
    std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>>& buildings)
    {
        std::vector<std::pair<int, int>> skyline;
        divide_conquer(buildings, 0, buildings.size(), skyline);
        return skyline;
    }

private:
    void divide_conquer(const std::vector<std::vector<int>>& buildings
            , int beg
            , int end
            , std::vector<std::pair<int, int>>& skyline)
    {
        if(beg==end) return;

        if(end-beg==1)
        {
            skyline.push_back({buildings[beg][0], buildings[beg][2]});
            skyline.push_back({buildings[beg][1], 0});
            return;
        }

        int l_beg=beg;
        int l_end=beg+(end-beg)/2;
        int r_beg=l_end;
        int r_end=end;

        std::vector<std::pair<int, int>> l_skyline;
        divide_conquer(buildings, l_beg, l_end, l_skyline);

        std::vector<std::pair<int, int>> r_skyline;
        divide_conquer(buildings, r_beg, r_end, r_skyline);
        
        merge(l_skyline, r_skyline, skyline);
    }

    void merge(std::vector<std::pair<int, int>>& l
            , std::vector<std::pair<int, int>>& r
            , std::vector<std::pair<int, int>>& result)
    {
        int l_sz=l.size();
        int r_sz=r.size();
        int i=0;
        int j=0;

        int l_h=0;
        int r_h=0;
        for(; i<l_sz && j<r_sz; )
        {
            if(r[j].first<l[i].first)
            {
                int x=r[j].first;
                r_h=r[j].second;
                append(result, {x, std::max(l_h, r_h)});
                j++;
            }
            else
            {
                int x=l[i].first;
                l_h=l[i].second;
                append(result, {x, std::max(l_h, r_h)});
                i++;
            }
        }

        for(; i<l_sz; )
        {
            append(result, l[i++]);
        }

        for(; j<r_sz; )
        {
            append(result, r[j++]);
        }

        result.back().second=0;
    }

    void append(std::vector<std::pair<int, int>>& skyline
            , std::pair<int, int> point)
    {
        if(skyline.empty())
        {
            skyline.push_back(point);
        }
        else if(skyline.back().second==point.second)
        {
            return;
        }
        else if(skyline.back().first==point.first)
        {
            skyline.back().second=std::max(skyline.back().second, point.second);
            if(skyline.size()>1 && skyline[skyline.size()-2].second==skyline.back().second)
                skyline.pop_back();
        }
        else
        {
            skyline.push_back(point);
        }
    }
};

int main()
{
    SolutionDivideConquer s;

    //std::vector<std::vector<int>> buildings{ {0, 1, 3} };
    //std::vector<std::vector<int>> buildings{ {0, 2, 3}, {2, 5 ,3} };
    //std::vector<std::vector<int>> buildings{ {2,13,10}, {10,17,25}, {12,20,14} };
    std::vector<std::vector<int>> buildings{ {2,4,7}, {2,4,5}, {2,4,6} };

    auto vp=s.getSkyline(buildings);
    for(const auto& p : vp)
    {
        std::cout<<p.first<<","<<p.second<<" ";
    }

    std::cout<<std::endl;
    return 0;
}

