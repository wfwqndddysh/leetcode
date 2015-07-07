#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>
#include<climits>

class Solution
{
public:
    int threeSumClosest(std::vector<int>& nums, int target)
    {
        int sz=nums.size();
        std::sort(nums.begin(), nums.end());

        int diff=INT_MAX;
        for(int i=0; i<sz-2; )
        {
            int target2=target-nums[i];

            int front=i+1;
            int back=sz-1;

            diff = abs(target2-nums[front]-nums[back]) < abs(diff) ? abs(target2-nums[front]-nums[back]) : diff;

            while(front+1<back)
            {
                int f=front;
                int b=back;

                int i=0;
                for (int new_diff=diff; abs(new_diff)<=abs(diff) && front+i+1<back; i++)
                {
                    diff=new_diff;
                    new_diff=target2-nums[front+i+1]-nums[back];
                }
                front+=i-1;

                i=0;
                for (int new_diff=diff; abs(new_diff)<=abs(diff) && front<back-i-1; ++i)
                {
                    diff=new_diff;
                    new_diff=target2-nums[front]-nums[back-i-1];
                }
                back-=i-1;

                if(f==front && b==back) break;
            }
            for(i++; nums[i]==nums[i-1] && i<sz-2; ++i);
        }

        return target-diff;
    }
};

int main()
{
    Solution s;

    /*
    std::vector<int> nums{0, 0, 0};
    int sum=s.threeSumClosest(nums, 1);
    */

    //std::vector<int> nums{1,2,4,8,16,32,64,128};
    //int sum=s.threeSumClosest(nums, 82);

    /*
    std::vector<int> nums{1, 1, 1, 0};
    int sum=s.threeSumClosest(nums, 100);
    */

    std::vector<int> nums{1, 1, 1, 0};
    int sum=s.threeSumClosest(nums, -100);

    std::cout<<sum<<std::endl;
    return 0;
}

