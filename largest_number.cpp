#include<iostream>
#include<cassert>
#include<vector>
#include<list>
#include<algorithm>
#include<map>

class Solution
{
public:
    //可以ac，不过还是错误的
    //比如输入 [ 891, 892, 8928 ]
    //说明leetcode的测试用例也不完善的情况
    //次题如果不用广为流传的 a+b>b+a比较法
    //不知道还有什么好的方法
    std::string largestNumber(const std::vector<int>& nums)
    {
        std::string big_num;
        std::vector<std::vector<int>*> groups;

        group_by_highest(nums, groups);

        auto comp = [this](const std::vector<int>* l, const std::vector<int>* r)->bool
        {
            return get_highest(l->front())<get_highest(r->front());
        };

        std::sort(groups.begin(), groups.end(), comp);

        for(auto itr=groups.rbegin(); itr!=groups.rend(); ++itr)
        {
            std::sort((*itr)->begin(), (*itr)->end());
            eat_next(big_num, *itr);
            delete *itr;
        }
        return big_num;
    }

    void eat_next(std::string& big_num, std::vector<int>* group)
    {
        int highest = get_highest(group->front());
        std::sort(group->begin(), group->end());
        while(!group->empty())
        {
            auto to_eat = group->cbegin();
            for(auto next=to_eat+1; next!=group->cend(); ++next)
            {
                if(profit_more(highest, *next, *to_eat))
                {
                    to_eat = next;
                }
            }

            char buf[12] = {0};
            if(*to_eat!=0 || big_num.empty() || big_num.front()!='0')
            {
                snprintf(buf, 12, "%d", *to_eat);
                big_num += std::string(buf);
            }
            group->erase(to_eat);
        }
    }

    void group_by_highest(const std::vector<int>& nums
            , std::vector<std::vector<int>*>& groups)
    {
        std::map<int, std::vector<int>*> mgroups;
        for(auto itr=nums.cbegin(); itr!=nums.cend(); ++itr)
        {
            int highest = get_highest(*itr);
            auto l = mgroups.find(highest);
            if(l==mgroups.cend())
            {
                std::vector<int>* v = new std::vector<int>;
                v->push_back(*itr);
                mgroups[highest]=v;
            }
            else
            {
                l->second->push_back(*itr);
            }
        }

        for(auto itr=mgroups.cbegin(); itr!=mgroups.cend(); ++itr)
        {
            groups.push_back(itr->second);
        }
    }

    //whether a is more profit than b
    bool profit_more(int highest, int a, int b)
    {
        std::list<int> as;
        std::list<int> bs;

        get_singles(a, as);
        get_singles(b, bs);

        auto itr_a = as.cbegin();
        auto itr_b = bs.cbegin();


        for(size_t diff=as.size()-bs.size(); diff>0; --diff)
        {
            int padding = bs.back()<highest ? highest : bs.back();
            bs.push_back(padding);
        }

        for(; itr_b!=bs.cend(); ++itr_a, ++itr_b)
        {
            if(*itr_a>*itr_b)
                return true;
            else if(*itr_a<*itr_b)
                return false;
        }
        return true;
    }

    void get_singles(int num, std::list<int>& singles)
    {
        while(num>0)
        {
            int lowest = num % 10;
            singles.push_front(lowest);
            num /= 10;
        }
    }

    int get_highest(int num)
    {
        int highest = 0;
        while(num>0)
        {
            highest = num % 10;
            num /= 10;
        }
        return highest;
    }

    std::string largestNumber_comp(const std::vector<int>& nums)
    {
        std::vector<std::string> i2s;
        
        for(auto n : nums)
        {
            i2s.push_back(std::to_string(n));
        }

        std::sort(i2s.begin(), i2s.end(), [](const std::string& l
                    , const std::string& r) { return l+r>r+l; });

        std::string ret;
        for(const auto& s : i2s)
        {
            ret += s;
        }

        if(!ret.empty() && ret[0] == '0')
            return "0";

        return ret;
    }
};

int main()
{
    Solution s;
    //std::vector<int> nums{ 3, 30, 34, 5, 9 };
    //std::vector<int> nums{ 10, 2 };
    //std::vector<int> nums{ 0, 0, 0 };
    //std::vector<int> nums{  4704,6306,9385,7536,3462,4798,5422,5529,8070,6241,9094,7846,663,6221,216,6758,8353,3650,3836,8183,3516,5909,6744,1548,5712,2281,3664,7100,6698,7321,4980,8937,3163,5784,3298,9890,1090,7605,1380,1147,1495,3699,9448,5208,9456,3846,3567,6856,2000,3575,7205,2697,5972,7471,1763,1143,1417,6038,2313,6554,9026,8107,9827,7982,9685,3905,8939,1048,282,7423,6327,2970,4453,5460,3399,9533,914,3932,192,3084,6806,273,4283,2060,5682,2,2362,4812,7032,810,2465,6511,213,2362,3021,2745,3636,6265,1518,8398 };
    //std::vector<int> nums{ 121, 12 };
    //std::vector<int> nums{ 9051,5526,2264,5041,1630,5906,6787,8382,4662,4532,6804,4710,4542,2116,7219,8701,8308,957,8775,4822,396,8995,8597,2304,8902,830,8591,5828,9642,7100,3976,5565,5490,1613,5731,8052,8985,2623,6325,3723,5224,8274,4787,6310,3393,78,3288,7584,7440,5752,351,4555,7265,9959,3866,9854,2709,5817,7272,43,1014,7527,3946,4289,1272,5213,710,1603,2436,8823,5228,2581,771,3700,2109,5638,3402,3910,871,5441,6861,9556,1089,4088,2788,9632,6822,6145,5137,236,683,2869,9525,8161,8374,2439,6028,7813,6406,7519 };
    //std::vector<int> nums{ 8052,8161,8274,830,8308,8374,8382,8591,8597,8701,871,8775,8823,8902,8985,8995 }; 
    std::vector<int> nums{ 891, 892, 8928 }; 

    std::cout<<s.largestNumber_comp(nums)<<std::endl;
    return 0;
}

