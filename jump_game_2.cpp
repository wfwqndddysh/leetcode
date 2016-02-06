#include<iostream>
#include<cassert>
#include<vector>
#include<queue>

/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)

Note:
You can assume that you can always reach the last index.
*/

class SolutionBackword
{
public:
    int jump(std::vector<int>& nums)
    {
        int sz=nums.size();
        if(sz<2) return true;
        int steps=0;

        for(int i=sz-1; i>0;)
        {
            int next = i-1;
            for(int j=i-1; j>=0; --j)
            {
                if(nums[j]+j>=i) next=j;
            }
            i=next;
            steps++;
        }

        return steps;
    }
};


/*
 * BFS 方案
 */
int jump(int A[], int n) {
    if(n<2)return 0;
    int level=0,currentMax=0,i=0,nextMax=0;

    //i为当前level的第一个节点
    while(currentMax-i+1>0){       //nodes count of current level>0
        level++;
        for(;i<=currentMax;i++){   //traverse current level , and update the max reach of next level
            nextMax=std::max(nextMax,A[i]+i);
            if(nextMax>=n-1)return level;   // if last element is in level+1,  then the min jump=level
        }
        currentMax=nextMax;
    }
    return 0;
}

/*
class SolutionDP
{
public:
    int jump(std::vector<int>& nums)
    {
        int sz=nums.size();
        if(sz<2) return 0;

        std::vector<int> dp(sz-1, 0);
        int steps=1;

        for(int i=1; i<sz-1; ++i)
        {
            if(nums[dp[i-1]]+dp[i-1]<i)
            {
                int next = i;
                for(int j=i-1; j>dp[i-1]; --j)
                {
                    if(nums[j]+j>i)
                        next = j;
                }
                dp[i]=next;
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }

        for(int i=sz-2; i>0;)
        {
            i = dp[i-1];
            steps++;
        }

        return steps;
    }
};
*/

class SolutionDP
{
public:
    int jump(std::vector<int>& nums)
    {
        int sz=nums.size();
        if(sz<2) return 0;

        std::vector<int> dp(sz, 0);
        int steps=0;

        for(int i=2; i<sz; ++i)
        {
            if(nums[dp[i-1]]+dp[i-1]<i)
            {
                int next = i-1;
                for(int j=dp[i-1]+1; j<i-1; ++j)
                {
                    if(nums[j]+j>=i)
                    {
                        next = j;
                        break;
                    }
                }
                dp[i]=next;
            }
            else
            {
                dp[i] = dp[i-1];
            }
        }

        for(int i=sz-1; i>0;)
        {
            i = dp[i];
            steps++;
        }

        return steps;
    }
};

int main()
{
    SolutionDP s;
    //std::vector<int> nums{0, 1};
    //std::vector<int> nums{8,2,4,4,4,9,5,2,5,8,8,0,8,6,9,1,1,6,3,5,1,2,6,6,0,4,8,6,0,3,2,8,7,6,5,1,7,0,3,4,8,3,5,9,0,4,0,1,0,5,9,2,0,7,0,2,1,0,8,2,5,1,2,3,9,7,4,7,0,0,1,8,5,6,7,5,1,9,9,3,5,0,7,5};
    //std::vector<int> nums{1, 2, 1, 1, 1};
    //std::vector<int> nums{1, 2};
    //std::vector<int> nums{3, 2, 1};
    //std::vector<int> nums{1, 2, 3};
    std::vector<int> nums{7,0,9,6,9,6,1,7,9,0,1,2,9,0,3};
    std::cout<<s.jump(nums)<<std::endl;
    return 0;
}

