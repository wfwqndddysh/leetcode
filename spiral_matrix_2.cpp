#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::vector<std::vector<int>> generateMatrix(int n)
    {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
        int row=n;
        int col=n;

        int cur=1;

        for(int i=0, j=0; row>=1 && col>=1; row-=2, col-=2, ++i, ++j)
        {
            if(col==1 && row==1) matrix[i][j]=cur++;

            for(int m=i, n=j; n<col+j-1; ++n)
            {
                matrix[m][n]=cur++;
            }

            for(int m=i, n=col+j-1; m<row+i-1; ++m)
            {
                matrix[m][n]=cur++;
            }

            for(int m=row+i-1, n=col+j-1; n>j; --n)
            {
                matrix[m][n]=cur++;
                if(row==1) break;
            }

            for(int m=row+i-1, n=j; m>i; --m)
            {
                matrix[m][n]=cur++;
                if(col==1) break;
            }
        }

        return matrix;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

