#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    void sortColors(std::vector<int>& nums)
    {
        int red = 0;
        int blue = nums.size()-1;
        int i = 0;

        while(red<blue+1)
        {
            if(nums[i]==0)
            {
                std::swap(nums[i++], nums[red++]);
            }
            else if(nums[i]==2)
            {
                std::swap(nums[i], nums[blue--]);
            }
            else
            {
                i++;
            }
        }
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

