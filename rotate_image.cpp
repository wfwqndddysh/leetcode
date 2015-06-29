#include<iostream>
#include<cassert>
#include<vector>
#include<string>

class Solution
{
public:
    void rotate(std::vector<std::vector<int>>& matrix)
    {
        auto sz=matrix.size();
        if(sz<2) return;

        for(size_t i=0; i<sz/2; ++i)
        {
            for(size_t j=i; j<i+sz-2*i-1; ++j)
            {
                int tmp = matrix[i][j];

                int i4=sz-1-i-(j-i);
                int j4=i;
                matrix[i][j] = matrix[i4][j4];

                int i3=sz-1-i;
                int j3=sz-1-j;
                matrix[i4][j4] = matrix[i3][j3];

                int i2=j;
                int j2=sz-1-i;
                matrix[i3][j3] = matrix[i2][j2];

                matrix[i2][j2] = tmp;
            }
        }
    }
};

int main()
{
    Solution s;
    //std::vector<std::vector<int>> matrix{{1, 2}, {3, 4}};


    std::vector<std::vector<int>> matrix{{1, 2, 3, 4},
                                         {5, 6, 7, 8},
                                         {9, 10, 11, 12},
                                         {13, 14, 15, 16}};

    s.rotate(matrix);

    for(const auto& v : matrix)
    {
        for(int n : v)
            std::cout<<n<<" ";
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
    return 0;
}

