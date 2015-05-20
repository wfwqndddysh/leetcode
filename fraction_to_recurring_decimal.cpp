#include<iostream>
#include<cassert>
#include<unordered_map>
#include<vector>
#include<algorithm>

class Solution
{
public:
    std::string fractionToDecimal_my(int numerator, int denominator)
    {
        assert(denominator!=0);
        std::string ret;

        //before dot
        
        bool positive = (numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0);
        long long numerator_ = std::abs((long)numerator);
        long long denominator_ = std::abs((long)denominator);
        long long q = numerator_ / std::abs(denominator_);
        long long m = numerator_ %  std::abs(denominator_);
        if(positive)
            ret.push_back('-');

        ret += std::to_string(q);

        if(m==0)
        {
            return ret;
        }
        else
        {
            ret.push_back('.');
        }

        //after dot
        std::vector<std::pair<int, int>> m2q;
        auto itr = m2q.cbegin();
        while(m!=0)
        {
            for(bool be_first=true; m<denominator_; m *=10)
            {
                if(be_first)
                {
                    be_first = false;
                    continue;
                }
                ret.push_back('0');
                m2q.push_back(std::make_pair(0, 0));
            }

            q = m / denominator_;
            m = m % denominator_;

            itr = std::find_if(m2q.cbegin()
                    , m2q.cend()
                    , [m, q](const std::pair<int, int>& mq)
                        {
                        return m==mq.first && q==mq.second;
                        });

            if(itr!=m2q.cend())
            {
                auto diff = m2q.cend()-itr;
                while(ret[ret.size()-1]=='0')
                {
                    ret.erase(ret.size()-1, 1);
                }
                ret.insert(ret.size()-diff, 1, '(');
                ret.push_back(')');
                break;
            }

            ret.push_back(q-0+'0');
            m2q.push_back(std::make_pair(m, q));
        }
        return ret;
    }

    //more simple
    std::string fractionToDecimal_(int numerator, int denominator)
    {
        std::string ret;
        if(numerator==0) return ret;

        if((long)numerator < 0 ^ (long)denominator < 0) ret += '-';

        long long numerator_ = std::abs((long)numerator);
        long long denominator_ = std::abs((long)denominator);

        //before dot
        long long q = numerator_ / denominator_;
        long long m = numerator_ %  denominator_;

        ret += std::to_string(q);
        if(m==0) return ret;

        ret += '.';

        //after dot
        std::unordered_map<int, int> m2index;
        while(m!=0)
        {
            if(m2index.count(m)>0)
            {
                ret.insert(m2index[m], 1, '(');
                ret += ')';
                break;
            }

            m2index[m] = ret.size();
            m *= 10;
            ret += std::to_string(m / denominator_);
            m %= denominator_;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    //std::cout<<s.fractionToDecimal(1, 99)<<std::endl;
    //std::cout<<s.fractionToDecimal(1, 6)<<std::endl;
    //std::cout<<s.fractionToDecimal(-50, 8)<<std::endl;
    //std::cout<<s.fractionToDecimal(7, -12)<<std::endl;
    //std::cout<<s.fractionToDecimal(-1, -2147483648)<<std::endl;
    std::cout<<s.fractionToDecimal_(1, 5)<<std::endl;
    return 0;
}

