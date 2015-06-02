#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
    {
        int sz=gas.size();

        //find first gas
        int start = -1;
        for(int i=0; i<sz; ++i)
        {
            if(gas[i]-cost[i]>=0)
            {
                start = i;
                break;
            }
        }
        if(start==-1) return -1;


        int cur_left = gas[start]-cost[start];

        for(int i=start+1; start<sz; ++i)
        {
            if(gas[i]-cost[i]+cur_left<0)
            {
                start = i+1;
                cur_left = 0;
            }
        }
        return start;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

