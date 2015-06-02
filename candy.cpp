#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    int candy(const std::vector<int>& ratings)
    {
        ratings_ = ratings;
        cnt_candy_ = 0;

        //rec(0, ratings.size());
        return cnt_candy_;
    }

private:
    void rec(size_t beg, size_t end, int l_rate, int l_candy, int r_rate, int r_candy)
    {
        if(beg<end)
            return;

        if(beg==end)
        {
            auto candy = 1;
            auto rate = ratings_[beg];

            candy = rate>l_rate ? l_candy+1 : l_candy;
            candy = rate>r_rate ? std::max(candy, r_candy+1) : std::max(candy, r_candy);
        }
        else
        {
            size_t index = 0;
            auto rate = find_min(beg, end, &index);
            
            if(index==beg)
            {
            }
            else if(index==end)
            {
            }
            else
            {
                auto n_end = index-1;
                auto n_r_rate = rate;
                auto n_r_candy = 1;
                cnt_candy_ += 1;
                rec(beg, n_end, l_rate, l_candy, n_r_rate, n_r_candy);

                auto n_beg = index+1;
                auto n_l_rate = rate;
                auto n_l_candy = 1;
                cnt_candy_ += 1;
                rec(n_beg, end, n_l_rate, n_l_candy, r_rate, r_candy);
            }
        }
    }

    int find_min(size_t beg, size_t end, size_t* index)
    {
        *index = 0;
        int min_rate =  ratings_[beg];
        for(auto i=beg; i<=end; ++i)
        {
            if(ratings_[i]<min_rate)
            {
                min_rate = ratings_[i];
                *index = i;
            }
        }
        return min_rate;
    }

private:
    std::vector<int> ratings_;
    int cnt_candy_;
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

