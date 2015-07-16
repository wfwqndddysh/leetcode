#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix)
    {
        if(matrix.empty()) return 0;

        int max_square=0;
        int row=matrix.size();
        int col=matrix[0].size();

        for(int i=0; i<row; ++i)
        {
            for(int j=0; j<col; ++j)
            {
                if(matrix[i][j]=='1')
                    max_square=std::max(max_square, get_max_square(matrix, i, j));
            }
        }

        return max_square;
    }

private:
    int get_max_square(const std::vector<std::vector<char>>& matrix, int r, int c)
    {
        int l=1;
        int row=matrix.size();
        int col=matrix[0].size();

        for(; (r+l)<row && (c+l)<col; ++l)
        {
            for(int i=0; i<=l; ++i)
            {
                if(matrix[r+l][c+i]!='1')
                    return l*l;
            }

            for(int i=0; i<=l; ++i)
            {
                if(matrix[r+i][c+l]!='1')
                    return l*l;
            }
        }

        return l*l;
    }
};

int main()
{
    Solution s;

    /*
    std::vector<std::vector<char>> matrix{ {'0', '0'},
                                           {'0', '0'} };
                                           */

    std::vector<std::vector<char>> matrix{ {'1', '0'},
                                           {'1', '0'} };

    std::cout<<s.maximalSquare(matrix)<<std::endl;
    return 0;
}

