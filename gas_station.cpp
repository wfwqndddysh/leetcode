#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
    {
        int sz=gas.size();

        int start = 0;
        int left_gas = 0;
        for(;start<sz;)
        {
            bool moved = false;
            int i = start;
            while((!moved ||i!=start) && gas[i]+left_gas-cost[i]>=0)
            {
                moved = true;
                left_gas = left_gas+gas[i]-cost[i];
                i=(i+1)%sz;
            }
            if(moved && i==start) return start;
            if(i<start) return -1;
            start = i+1;
        }
        return -1;
    }

    int canCompleteCircuitLeetCode(std::vector<int>& gas, std::vector<int>& cost)
    {
        int start(0),total(0),tank(0);
        //if car fails at 'start', record the next station
        for(int i=0;i<gas.size();i++)
        {
            if((tank=tank+gas[i]-cost[i])<0)
            {
                start=i+1;
                total+=tank;
                tank=0;
            }
        }
        return (total+tank<0) ? -1 : start;
    }
};

int main()
{
    Solution s;
    std::vector<int> gas{2, 4};
    std::vector<int> cost{3, 4};
    std::cout<<s.canCompleteCircuit(gas, cost)<<std::endl;
    return 0;
}

