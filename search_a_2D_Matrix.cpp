#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target)
    {
        if(matrix.size()==0) return false;

        int row=matrix.size();
        int col=matrix[0].size();
        int in_row=-1;

        int low=0;
        int high=row-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;
            
            if(matrix[mid][0]>target)
            {
                high=mid-1;
            }
            else if(matrix[mid][col-1]>=target)
            {
                in_row = mid;
                break;
            }
            else
            {
                low=mid+1;
            }
        }

        if(in_row==-1) return false;

        low=0;
        high=col-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(matrix[in_row][mid]>target)
            {
                high=mid-1;
            }
            else if(matrix[in_row][mid]==target)
            {
                return true;
            }
            else
            {
                low=mid+1;
            }
        }

        return false;
    }
};

int main()
{
    Solution s;
    std::vector<std::vector<int>> matrix{{1}};
    std::cout<<s.searchMatrix(matrix, 1)<<std::endl;
    return 0;
}

