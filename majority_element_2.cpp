#include<iostream>
#include<cassert>
#include<vector>
#include<map>

class Solution
{
public:
    std::vector<int> majorityElement(std::vector<int>& nums)
    {
        std::vector<int> majorities;
        if(nums.size()==0) return majorities;
        if(nums.size()==1) return nums;;

        if(nums.size()==2)
        {
            majorities.push_back(nums[0]);
            if(nums[1]!=majorities[0]) majorities.push_back(nums[1]);
            return majorities;
        }

        int a=nums[0];
        int an=1;
        int b, bn=0;
        int c, cn=0;

        if(nums[1]==a) an++;
        else { b=nums[1]; bn++; }

        if(nums[2]==a) an++;
        else if(nums[2]==b) bn++;
        else { c=nums[2]; cn++; }

        int sz=nums.size();
        for(int i=3; i<sz; ++i)
        {
            process_tuple(a, an , b, bn , c, cn, nums[i]);
        }

        if(an>0 && be_majority(nums, a)) majorities.push_back(a);
        if(bn>0 && be_majority(nums, b)) majorities.push_back(b);
        if(cn>0 && be_majority(nums, c)) majorities.push_back(c);

        return majorities;
    }

private:
    void process_tuple(int& a, int& an
            , int& b, int& bn
            , int& c, int& cn
            , int num)
    {
        if(an>0 && num==a) an++;
        else if(bn>0 && num==b) bn++;
        else if(cn>0 && num==c) cn++;
        else if(an==0) a=num, an=1;
        else if(bn==0) b=num, bn=1;
        else if(cn==0) c=num, cn=1;

        if(an>0 && bn>0 && cn>0)
            an--, bn--, cn--;
    }

    bool be_majority(const std::vector<int>& nums, int candiate)
    {
        int lowest=nums.size()/3;
        int cnt=0;

        for(int n : nums)
            if(n==candiate)
                cnt++;

        return cnt>lowest;
    }
};

class SolutionLeetCode
{
public:
    std::vector<int> majorityElement(std::vector<int> &a)
    {
        int y = 0, z = 1, cy = 0, cz = 0;
        for (auto x: a)
        {
            if (x == y) cy++;
            else if (x == z) cz++;
            else if (! cy) y = x, cy = 1;
            else if (! cz) z = x, cz = 1;
            else cy--, cz--;
        }
        cy = cz = 0;
        for (auto x: a)
        {
            if (x == y) cy++;
            else if (x == z) cz++;
        }
        std::vector<int> r;
        if (cy > (int)a.size()/3) r.push_back(y);
        if (cz > (int)a.size()/3) r.push_back(z);
        return r;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

