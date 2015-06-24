#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if(m==0) return 0;

        std::vector<int> path(n, 1);

        for(int i=1; i<m; ++i)
        {
            path[0] = 1;
            for(int j=1; j<n; ++j)
            {
                path[j] = path[j]+path[j-1];
            }
        }

        return path[n-1];
    }
};

int main()
{
    Solution s;
    std::cout<<s.uniquePaths(2, 2)<<std::endl;
    return 0;
}

