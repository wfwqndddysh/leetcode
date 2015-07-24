#include<iostream>
#include<cassert>
#include<vector>

class SolutionNative
{
public:
    std::vector<std::pair<int, int>> getSkyline(std::vector<std::vector<int>>& buildings)
    {
        std::vector<int> heights(1, 0);

        for(size_t i=0; i<buildings.size(); ++i)
        {
            for(int j=buildings[i][0]; j<=buildings[i][1]; ++j)
            {
                heights[j]=std::max(heights[j], buildings[i][2]);
            }
        }

        for(
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

