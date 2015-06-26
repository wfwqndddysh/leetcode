#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix)
    {
        std::vector<int> nums;
        int row=matrix.size();
        if(row==0) return nums;
        int col=matrix[0].size();

        for(int i=0, j=0; row>=1 && col>=1; row-=2, col-=2, ++i, ++j)
        {
            if(col==1 && row==1) nums.push_back(matrix[i][j]);

            for(int m=i, n=j; n<col+j-1; ++n)
            {
                nums.push_back(matrix[m][n]);
            }

            for(int m=i, n=col+j-1; m<row+i-1; ++m)
            {
                nums.push_back(matrix[m][n]);
            }

            for(int m=row+i-1, n=col+j-1; n>j; --n)
            {
                nums.push_back(matrix[m][n]);
                if(row==1) break;
            }

            for(int m=row+i-1, n=j; m>i; --m)
            {
                nums.push_back(matrix[m][n]);
                if(col==1) break;
            }
        }

        return nums;
    }
};

int main()
{
    Solution s;

    /*
    std::vector<std::vector<int>> matrix{{1, 2, 3},
                                         {4, 5, 6},
                                         {7, 8, 9}};
                                         */

    //std::vector<std::vector<int>> matrix{{1, 2, 3}};

    /*
    std::vector<std::vector<int>> matrix{{1}, {2}, {3},
                                         {4}, {5}, {6}};
                                         */

    //std::vector<std::vector<int>> matrix{{1, 2, 3, 4, 5, 6}};

    /*
    std::vector<std::vector<int>> matrix{{1, 2, 3},
                                         {4, 5, 6}};
                                         */


    std::vector<std::vector<int>> matrix{{1, 2, 3, 4},
                                         {5, 6, 7, 8},
                                         {9, 10, 11, 12},
                                         {13, 14, 15, 16}};

    auto v = s.spiralOrder(matrix);

    for(int n : v)
        std::cout<<n<<" ";

    std::cout<<std::endl;
    return 0;
}

