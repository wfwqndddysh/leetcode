#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    void setZeroes(std::vector<std::vector<int>>& matrix)
    {
        if(matrix.size()==0) return;

        auto row=matrix.size();
        auto col=matrix[0].size();

        bool row_0_has_zero=false;
        for(size_t i=0; i<col; ++i)
        {
            if(matrix[0][i]==0)
            {
                row_0_has_zero=true;
                break;
            }
        }

        bool col_0_has_zero=false;
        for(size_t i=0; i<row; ++i)
        {
            if(matrix[i][0]==0)
            {
                col_0_has_zero=true;
                break;
            }
        }

        for(size_t i=1; i<row; ++i)
        {
            for(size_t j=1; j<col; ++j)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(size_t i=1; i<row; ++i)
        {
            for(size_t j=1; j<col; ++j)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }

        if(row_0_has_zero)
        {
            for(size_t i=0; i<col; ++i)
            {
                matrix[0][i]=0;
            }
        }

        if(col_0_has_zero)
        {
            for(size_t i=0; i<row; ++i)
            {
                matrix[i][0]=0;
            }
        }
    }
};

int main()
{
    Solution s;
    /*
    std::vector<std::vector<int>> matrix{ {3,5,5,6,9,1,4,5,0,5},
                                          {2,7,9,5,9,5,4,9,6,8},
                                          {6,0,7,8,1,0,1,6,8,1},
                                          {7,2,6,5,8,5,6,5,0,6},
                                          {2,3,3,1,0,4,6,5,3,5},
                                          {5,9,7,3,8,8,5,1,4,3},
                                          {2,4,7,9,9,8,4,7,3,7},
                                          {3,5,2,8,8,2,2,4,9,8}};
                                          */

    std::vector<std::vector<int>> matrix{ {0,0,0,5},
                                          {4,3,1,4},
                                          {0,1,1,4},
                                          {1,2,1,3},
                                          {0,0,1,1} };

    s.setZeroes(matrix);
    std::cout<<std::endl;
    return 0;
}

