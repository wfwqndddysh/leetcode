#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int minPathSum(std::vector<std::vector<int>>& grid)
    {
        if(grid.size()==0) return 0;

        auto row=grid.size();
        auto col=grid[0].size();

        std::vector<int> min_path(col+1, 0);

        for(size_t i=1; i<col+1; ++i)
        {
            min_path[i] = min_path[i-1] + grid[0][i-1];
        }

        for(size_t i=1; i<row; ++i)
        {
            min_path[1] = min_path[1]+grid[i][0];
            for(size_t j=2; j<col+1; ++j)
            {
                min_path[j] = std::min(min_path[j], min_path[j-1])+grid[i][j-1];
            }
        }

        return min_path[col];
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> grid{{1, 2}, {1, 1}};
    std::cout<<s.minPathSum(grid)<<std::endl;
    return 0;
}

