#include<iostream>
#include<cassert>
#include<string>

class Solution
{
public:
    int numDecodings(std::string s)
    {
        auto len = s.length();
        if(len==0 || s[0]=='0') return 0;

        int cnt_eat_one(0);
        int cnt_eat_two(1);
        int cnt_all(0);
        int invalid = 1;

        if(s[len-1]!='0')
        {
            cnt_eat_one = 1;
            cnt_all = 1;
            invalid = 0;
        }

        for(int i=s.length()-2; invalid<2 && i>=0; --i)
        {
            if(s[i]=='0')
            {
                cnt_eat_two = cnt_eat_one;
                cnt_eat_one = 0;
                cnt_all = 0;
                invalid++;
            }
            else if((s[i]=='1' && s[i+1]!='0') || (s[i]=='2' && s[i+1]>'0' && s[i+1]<'7'))
            {
                invalid = 0;
                cnt_all = cnt_eat_one + cnt_eat_two;
                cnt_eat_two = cnt_eat_one;
                cnt_eat_one = cnt_all;
            }
            else if((s[i]=='1' && s[i+1] =='0') || (s[i]=='2' && s[i+1]=='0'))
            {
                invalid = 0;
                cnt_all = cnt_eat_one = cnt_eat_two;
                cnt_eat_two = 0;
            }
            else
            {
                invalid = 0;
                cnt_all = cnt_eat_two = cnt_eat_one;
            }
        }

        return invalid==2 ? 0 : cnt_all;
    }
};

int main()
{
    Solution s;

    //std::string ss="110";

    //std::string ss="1";

    //std::string ss="27";

    //std::string ss="26";

    //std::string ss="101";

    //std::string ss="1010";

    //std::string ss="5243";

    //std::string ss="12120";

    std::string ss="111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";

    std::cout<<s.numDecodings(ss)<<std::endl;
    return 0;
}

