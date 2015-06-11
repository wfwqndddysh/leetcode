#include<iostream>
#include<cassert>
#include<vector>
#include<climits>

class Solution
{
public:
    int minimumTotal(const std::vector<std::vector<int>>& triangle)
    {
        auto sz=triangle.size();
        if(sz==0) return 0;
        if(sz==1) return triangle[0][0];

        std::vector<int> cur_min(triangle[sz-1].size());
        cur_min[0]=triangle[0][0]+triangle[1][0];
        cur_min[1]=triangle[0][0]+triangle[1][1];

        for(size_t i=2; i<sz; ++i)
        {
            int tmp_0 = cur_min[0];
            int tmp_1 = cur_min[1];
            cur_min[0] = cur_min[0]+triangle[i][0];

            size_t j=1;
            for(; j<triangle[i].size()-1; ++j)
            {
                cur_min[j]=std::min(tmp_0+triangle[i][j], tmp_1+triangle[i][j]);
                tmp_0 = tmp_1;
                tmp_1 = cur_min[j+1];
            }
            cur_min[j] = tmp_0+triangle[i][j];
        }

        int min_sum = INT_MAX;
        
        for(int n : cur_min)
            min_sum = std::min(min_sum, n);

        return min_sum;
    }
};

int main()
{
    Solution s;

    //std::vector<int> v1{-1};
    //std::vector<int> v2{2, 3};
    //std::vector<int> v3{1, -1, -3};

    std::vector<int> v1{-1};
    std::vector<int> v2{2, 3};
    std::vector<int> v3{1, -1, -1};
    std::cout<<s.minimumTotal(std::vector<std::vector<int>>{v1, v2, v3})<<std::endl;
    return 0;
}

