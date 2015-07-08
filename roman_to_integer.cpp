#include<iostream>
#include<cassert>
#include<string>
#include<map>

class Solution
{
public:
    int romanToInt(std::string s)
    {
        int res=0;

        auto len=s.length();

        std::map<char, int> dict{ {'I', 1},
                                  {'V', 5},
                                  {'X', 10},
                                  {'L', 50},
                                  {'C', 100},
                                  {'D', 500},
                                  {'M', 1000}};
        int right=0;
        for(int i=len-1; i>=0; --i)
        {
            if(s[i]=='I')
            {
                if(right==5 || right==10)
                {
                    res += right-1;
                    right = 0;
                }
                else
                    right += 1;
            }
            else if(s[i]=='X')
            {
                if(right==50 || right==100)
                {
                    res += right-10;
                    right=0;
                }
                else if(right>0 && right<10)
                {
                    res += 10 + right;
                    right=0;
                }
                else
                {
                    right += 10;
                }
            }
            else if(s[i]=='C')
            {
                if(i-1>=0 && dict[s[i-1]]<dict[s[i]])
                {
                    res += right;
                    right = dict[s[i]];
                }
                else if(right==500 || right==1000)
                {
                    res += right-100;
                    right=0;
                }
                else if(right>0 && right<100)
                {
                    res += 100 + right;
                    right=0;
                }
                else
                {
                    right += 100;
                }
            }
            else if(s[i]=='M')
            {
                if(i-1>=0 && dict[s[i-1]]<dict[s[i]])
                {
                    res += right;
                    right = dict[s[i]];
                }
                else if(right>0 && right<1000)
                {
                    res += 1000 + right;
                    right=0;
                }
                else
                {
                    right += 1000;
                }
            }
            else if(s[i]=='V')
            {
                if(i-1>=0 && dict[s[i-1]]<dict[s[i]])
                {
                    res += right;
                    right = dict[s[i]];
                }
                else if(right>0)
                {
                    res += 5+right;
                    right=0;
                }
                else
                {
                    res += right;
                    right += 5;
                }
            }
            else if(s[i]=='L')
            {
                if(i-1>=0 && dict[s[i-1]]<dict[s[i]])
                {
                    res += right;
                    right = dict[s[i]];
                }
                else if(right>0)
                {
                    res += 50+right;
                    right=0;
                }
                else
                {
                    res += right;
                    right = 50;
                }
            }
            else if(s[i]=='D')
            {
                if(i-1>=0 && dict[s[i-1]]<dict[s[i]])
                {
                    res += right;
                    right = dict[s[i]];
                }
                else if(right>0)
                {
                    res += 500+right;
                    right=0;
                }
                else
                {
                    res += right;
                    right = 500;
                }
            }
        }

        return res+right;;
    }
};

int main()
{
    Solution s;

    //std::string roman("IV");
    //std::string roman("MDCCCLXXXIV");
    //std::string roman("MMCCCXCIX");
    //std::string roman("MMCDXXV");
    //std::string roman("CMLII");
    std::string roman("MCMXCVI");
    std::cout<<s.romanToInt(roman)<<std::endl;

    return 0;
}

