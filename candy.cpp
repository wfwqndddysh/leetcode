#include<iostream>
#include<cassert>
#include<vector>
#include<climits>

class Solution
{
public:
    int candy_n_space(const std::vector<int>& ratings)
    {
        auto sz=ratings.size();
        if(sz<2) return sz;

        std::vector<size_t> candies(sz, 1);

        for(size_t i=1; i<sz; ++i)
        {
            if(ratings[i] > ratings[i-1])
                candies[i] = candies[i-1] + 1;
        }
        for(int i=sz-1; i>0; i--)
        {
            if(ratings[i-1]>ratings[i])
                candies[i-1] = std::max(candies[i]+1, candies[i-1]);
        }

        int min_candies = 0;

        for(int n : candies)
            min_candies += n;

        return min_candies;
    }
};

/*
思路是一座山，一座山的处理，需要注意的是
判断何时到达peak，
记录上升区间的长度
记录下降区间的长度
如果下降区间的长度大于上升区间的长度，则peak的candies需要增加，以满足下降区间的需要
*/

class SolutionLeetCode
{
public:
    int candy(std::vector<int> &ratings){
        int n = ratings.size();
        int min_candies = n;

        int range = 0;
        for (size_t i = 0; i < n - 1; ) {
            int start = i;
            while (ratings[i] < ratings[i+1] && i < n-1) ++i;
            range = i - start;
            min_candies += (range * (range + 1)) / 2;
            if (i == n-1) break;

            start = i;
            while (ratings[i] > ratings[i+1] && i < n-1) ++i;
            int k = i - start - 1;
            min_candies += (k * (k + 1)) / 2;

            if (i - start > range) min_candies += (i - start - range);

            if (ratings[i] == ratings[i+1]) ++i;
        }
        return min_candies;
    }
};

int main()
{
    Solution s;
    //std::vector<int> v {0};
    //std::vector<int> v {2, 2};
    //std::vector<int> v {1, 2, 2};
    //std::vector<int> v {1, 2, 3};
    //std::vector<int> v {1, 3, 2};
    //std::vector<int> v {2, 1, 3};
    //std::vector<int> v {2, 3, 1};
    //std::vector<int> v {3, 1, 2};
    //std::vector<int> v {3, 2, 1};

    std::vector<int> v {58,21,72,77,48,9,38,71,68,77,82,47,25,94,89,54,26,54,54,99,64,71,76,63,81,82,60,64,29,51,87,87,72,12,16,20,21,54,43,41,83,77,41,61,72,82,15,50,36,69,49,53,92,77,16,73,12,28,37,41,79,25,80,3,37,48,23,10,55,19,51,38,96,92,99,68,75,14,18,63,35,19,68,28,49,36,53,61,64,91,2,43,68,34,46,57,82,22,67,89};
    std::cout<<s.candy_n_space(v)<<std::endl;
    return 0;
}

