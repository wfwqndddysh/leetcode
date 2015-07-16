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

class SolutionDP
{
public:
    int maximalSquare(std::vector<std::vector<char>>& matrix)
    {
        if (matrix.empty()) return 0;

        int m = matrix.size();
        int n = matrix[0].size();

        std::vector<int> dp(m + 1, 0);
        int maxsize = 0;
        int pre = 0;

        for (int j = 0; j < n; j++)
        {
            for (int i = 1; i <= m; i++)
            {
                int temp = dp[i];
                if (matrix[i - 1][j] == '1')
                {
                    dp[i] = std::min(dp[i], std::min(dp[i - 1], pre)) + 1;
                    maxsize = std::max(maxsize, dp[i]);
                }
                else
                {
                    dp[i] = 0; 
                }
                pre = temp;
            }
        }
        return maxsize * maxsize;
    }
};


int main()
{
    SolutionDP s;

    /*
    std::vector<std::vector<char>> matrix{ {'0', '0'},
                                           {'0', '0'} };
                                           */

    /*
    std::vector<std::vector<char>> matrix{ {'1', '0'},
                                           {'1', '0'} };
                                           */

    //std::vector<std::vector<char>> matrix{ {'0'} };

    std::vector<std::vector<char>> matrix{ {'1', '1'},
                                           {'1', '1'} };
    
    std::cout<<s.maximalSquare(matrix)<<std::endl;
    return 0;
}

