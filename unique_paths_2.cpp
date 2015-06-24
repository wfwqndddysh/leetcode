#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& grid)
    {
        if(grid.size()==0) return 0;

        auto row=grid.size(); 
        auto col=grid[0].size(); 

        std::vector<int> path(col, 1);

        path[0]=grid[0][0]==1 ? 0 : 1;
        for(size_t i=1; i<col; ++i)
        {
            if(grid[0][i]==1)
                path[i]=0;
            else
                path[i]=path[i-1];
        }

        for(size_t i=1; i<row; ++i)
        {
            path[0] = grid[i][0]==1 ? 0 : path[0];
            for(size_t j=1; j<col; ++j)
            {
                if(grid[i][j]==1)
                    path[j]=0;
                else
                    path[j] = path[j]+path[j-1];
            }
        }

        return path[col-1];
    }
};

int main()
{
    Solution s;
    //std::vector<std::vector<int>> grid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    //std::vector<std::vector<int>> grid{{0, 1}};
    std::vector<std::vector<int>> grid{{0}, {1}};
    std::cout<<s.uniquePathsWithObstacles(grid)<<std::endl;
    return 0;
}

