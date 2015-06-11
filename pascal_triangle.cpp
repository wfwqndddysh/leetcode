#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        std::vector<std::vector<int>> triangle;
        if(numRows>=1) triangle.push_back(std::vector<int>(1, 1));
        if(numRows>=2) triangle.push_back(std::vector<int>(2, 1));

        for(int i=3; i<=numRows; ++i)
        {
            triangle.push_back(std::vector<int>(i, 1));

            for(int j=1; j<i-1; ++j)
            {
                triangle.back()[j] = triangle[i-2][j-1]+triangle[i-2][j];
            }
        }

        return triangle;
    }
};

int main()
{
    Solution s;
    s.generate(4);
    std::cout<<std::endl;
    return 0;
}

