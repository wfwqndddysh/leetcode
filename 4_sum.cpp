#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<tuple>

class Solution
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        int sz=nums.size();
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>>  res;
        for(int i=0; i<sz-3;)
        {
            for(int j=i+1; j<sz-2;)
            {
                for(int k=j+1; k<sz-1;)
                {
                    int fouth=find_fouth(nums, k+1, target-nums[k]-nums[j]-nums[i]);
                    if(fouth>=0)
                    {
                        res.push_back({});
                        res.back().push_back(nums[i]);
                        res.back().push_back(nums[j]);
                        res.back().push_back(nums[k]);
                        res.back().push_back(nums[fouth]);
                    }
                    for(k++; nums[k]==nums[k-1] && k<sz-1; ++k);
                }
                for(j++; nums[j]==nums[j-1] && j<sz-2; ++j);
            }
            for(i++; nums[i]==nums[i-1] && i<sz-3; ++i);
        }

        return res;
    }

private:
    int find_fouth(std::vector<int>&  nums, int start, int target)
    {
        int low=start;
        int high=nums.size()-1;

        while(low<=high)
        {
            int mid=low+(high-low)/2;

            if(nums[mid]<target)
            {
                low=mid+1;
            }
            else if(nums[mid]==target)
            {
                return mid;
            }
            else
            {
                high=mid-1;
            }
        }

        return -1;
    }
};

class Solution_
{
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
    {
        std::vector<std::vector<int>>  res;

        std::sort(nums.begin(), nums.end());
        std::vector<std::tuple<int, int, int>> twoSums;
        generate_all_two_sum(nums, twoSums);

        auto comp=[](const std::tuple<int, int, int>& l, const std::tuple<int, int, int>& r)
            {return std::get<0>(l)<std::get<0>(r); };

        std::sort(twoSums.begin(), twoSums.end(), comp);

        int sz=twoSums.size();
        for(int i=0; i<sz-1; ++i)
        {
            int to_be_found = target-std::get<0>(twoSums[i]);
            int start=find_second_start(twoSums, i+1, to_be_found);
            if(start>=0)
            {
                int i1=std::get<1>(twoSums[i]);
                int i2=std::get<2>(twoSums[i]);
                for(; std::get<0>(twoSums[start])==to_be_found && start<sz; ++start)
                {
                    int i3=std::get<1>(twoSums[start]);
                    int i4=std::get<2>(twoSums[start]);
                    if(i2<i3)
                    {
                        res.push_back({});
                        res.back().push_back(nums[i1]);
                        res.back().push_back(nums[i2]);
                        res.back().push_back(nums[i3]);
                        res.back().push_back(nums[i4]);
                    }
                }
            }
        }

        return res;
    }

private:
    int find_second_start(const std::vector<std::tuple<int, int, int>>& twoSums
            , int start
            , int target)
    {
        int sz=twoSums.size();

        int low=start;
        int high=twoSums.size()-1;
        int mid=-1;
        while(low<=high)
        {
            mid=low+(high-low)/2;

            if(std::get<0>(twoSums[mid])>=target)
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        
        if(std::get<0>(twoSums[mid])==target)
            return mid;

        if(mid+1<sz&& std::get<0>(twoSums[mid+1])==target)
            return mid+1;

        return -1;
    }

    void generate_all_two_sum(const std::vector<int>& nums
            , std::vector<std::tuple<int, int, int>>& twoSums)
    {
        int sz=nums.size();
        for(int i=0; i<sz-1; ++i)
        {
            if(nums[i+1]==nums[i])
            {
                twoSums.push_back(std::tuple<int, int, int>(nums[i]+nums[i+1], i, i+1));
                while(nums[i+1]==nums[i]) i++;
            }

            for(int j=i+1; j<sz; ++j)
            {
                twoSums.push_back(std::tuple<int, int, int>(nums[i]+nums[j], i, j));
            }
        }
    }
};

class SolutionLeetCode
{
public:
    std::vector<std::vector<int> > fourSum(std::vector<int> &num, int target)
    {
        std::vector<std::vector<int> > res;
        int sz=num.size();

        if (num.empty())
            return res;

        std::sort(num.begin(),num.end());
        for (int i = 0; i < sz; i++)
        {
            int target_3 = target - num[i];
            for (int j = i + 1; j < sz; j++)
            {
                int target_2 = target_3 - num[j];

                int front = j + 1;
                int back = num.size() - 1;

                while(front < back)
                {
                    int two_sum = num[front] + num[back];

                    if (two_sum < target_2) front++;
                    else if (two_sum > target_2) back--;
                    else
                    {
                        std::vector<int> quadruplet(4, 0);
                        quadruplet[0] = num[i];
                        quadruplet[1] = num[j];
                        quadruplet[2] = num[front];
                        quadruplet[3] = num[back];
                        res.push_back(quadruplet);

                        // Processing the duplicates of number 3
                        while (front < back && num[front] == quadruplet[2]) ++front;

                        // Processing the duplicates of number 4
                        while (front < back && num[back] == quadruplet[3]) --back;
                    }
                }
                // Processing the duplicates of number 2
                while(j + 1 < sz && num[j + 1] == num[j]) ++j;
            }
            // Processing the duplicates of number 1
            while (i + 1 < sz && num[i + 1] == num[i]) ++i;
        }
        return res;
    }
};

int main()
{
    //SolutionLeetCode s;
    Solution_ s;

    std::vector<int> nums{ 91277418,66271374,38763793,4092006,11415077,60468277,1122637,72398035,-62267800,22082642,60359529,-16540633,92671879,-64462734,-55855043,-40899846,88007957,-57387813,-49552230,-96789394,18318594,-3246760,-44346548,-21370279,42493875,25185969,83216261,-70078020,-53687927,-76072023,-65863359,-61708176,-29175835,85675811,-80575807,-92211746,44755622,-23368379,23619674,-749263,-40707953,-68966953,72694581,-52328726,-78618474,40958224,-2921736,-55902268,-74278762,63342010,29076029,58781716,56045007,-67966567,-79405127,-45778231,-47167435,1586413,-58822903,-51277270,87348634,-86955956,-47418266,74884315,-36952674,-29067969,-98812826,-44893101,-22516153,-34522513,34091871,-79583480,47562301,6154068,87601405,-48859327,-2183204,17736781,31189878,-23814871,-35880166,39204002,93248899,-42067196,-49473145,-75235452,-61923200,64824322,-88505198,20903451,-80926102,56089387,-58094433,37743524,-71480010,-14975982,19473982,47085913,-90793462,-33520678,70775566,-76347995,-16091435,94700640,17183454,85735982,90399615,-86251609,-68167910,-95327478,90586275,-99524469,16999817,27815883,-88279865,53092631,75125438,44270568,-23129316,-846252,-59608044,90938699,80923976,3534451,6218186,41256179,-9165388,-11897463,92423776,-38991231,-6082654,92275443,74040861,77457712,-80549965,-42515693,69918944,-95198414,15677446,-52451179,-50111167,-23732840,39520751,-90474508,-27860023,65164540,26582346,-20183515,99018741,-2826130,-28461563,-24759460,-83828963,-1739800,71207113,26434787,52931083,-33111208,38314304,-29429107,-5567826,-5149750,9582750,85289753,75490866,-93202942,-85974081,7365682,-42953023,21825824,68329208,-87994788,3460985,18744871,-49724457,-12982362,-47800372,39958829,-95981751,-71017359,-18397211,27941418,-34699076,74174334,96928957,44328607,49293516,-39034828,5945763,-47046163,10986423,63478877,30677010,-21202664,-86235407,3164123,8956697,-9003909,-18929014,-73824245 };
    auto vv = s.fourSum(nums, -236727523);

    /*
    std::vector<int> nums{ -79583480, -65863359, -70078020, -21202664 };
    auto vv = s.fourSum(nums, -236727523);
    */

    for(const auto& v : vv)
    {
        for(int n : v)
            std::cout<<n<<" ";
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

