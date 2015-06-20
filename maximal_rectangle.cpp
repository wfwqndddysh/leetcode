#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

class Solution
{
public:
    int maximalRectangle(std::vector<std::vector<char>>& matrix)
    {
        int l = matrix.size();
        int c = l > 0 ? matrix[0].size() : 0;
        if(l==0 || c==0) return 0;

        std::vector<std::vector<int>> dp(c, std::vector<int>(c, 0));

        int max_rect = 0;

        for(int i=0; i<l; ++i)
        {
            for(int j=0; j<c; ++j)
            {
                if(matrix[i][j]=='0')
                {
                    for(int k=j; k<c; ++k)
                    {
                        dp[j][k] = 0;
                    }
                }
                else
                {
                    for(int k=j; k<c; ++k)
                    {
                        if(matrix[i][k]=='1')
                        {
                            dp[j][k] += 1;
                            max_rect = std::max(max_rect, dp[j][k]*(k-j+1));
                        }
                        else
                        {
                            while(k<c) dp[j][k++] = 0;
                        }
                    }
                }
            }
        }

        return max_rect;
    }
};

class SolutionLeetCode
{
public:
    int maximalRectangle(std::vector<std::vector<char> > &matrix)
    {
        if(matrix.empty()) return 0;
        const int m = matrix.size();
        const int n = matrix[0].size();
        int left[n], right[n], height[n];
        std::fill_n(left,n,0); std::fill_n(right,n,n); std::fill_n(height,n,0);
        int maxA = 0;
        for(int i=0; i<m; i++) {
            int cur_left=0, cur_right=n; 
            for(int j=0; j<n; j++) { // compute height (can do this from either side)
                if(matrix[i][j]=='1') height[j]++; 
                else height[j]=0;
            }
            for(int j=0; j<n; j++) { // compute left (from left to right)
                if(matrix[i][j]=='1') left[j]=std::max(left[j],cur_left);
                else {left[j]=0; cur_left=j+1;}
            }
            // compute right (from right to left)
            for(int j=n-1; j>=0; j--) {
                if(matrix[i][j]=='1') right[j]=std::min(right[j],cur_right);
                else {right[j]=n; cur_right=j;}    
            }
            // compute the area of rectangle (can do this from either side)
            for(int j=0; j<n; j++)
                maxA = std::max(maxA,(right[j]-left[j])*height[j]);
        }
        return maxA;
    }
};

int main()
{
    SolutionLeetCode s;
    /*
    std::vector<std::vector<char>> matrix{{'1', '0', '1', '1', '0', '1'},
                                          {'1', '1', '1', '1', '1', '1'},
                                          {'0', '1', '1', '0', '1', '1'},
                                          {'1', '1', '1', '0', '1', '0'},
                                          {'0', '1', '1', '0', '1', '1'},
                                          {'1', '1', '0', '1', '1', '1'}};
                                          */

    /*
    std::vector<std::vector<char>> matrix{{'0', '1'},
                                          {'1', '0'}};
                                          */

    std::vector<std::vector<char>> matrix{{'1', '1', '0', '1'},
                                          {'1', '1', '0', '1'},
                                          {'1', '1', '1', '1'}};
    s.maximalRectangle(matrix);
    std::cout<<std::endl;
    return 0;
}

