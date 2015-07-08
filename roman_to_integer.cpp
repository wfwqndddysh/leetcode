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
            if(s[i]=='I' || s[i]=='X' || s[i]=='C' || s[i]=='M')
            {
                if(i-1>=0 && dict[s[i-1]]<dict[s[i]])
                {
                    res += right;
                    right = dict[s[i]];
                }
                else if(right==dict[s[i]]*5 || right==dict[s[i]]*10)
                {
                    res += right-dict[s[i]];
                    right=0;
                }
                else if(right>0 && right<dict[s[i]])
                {
                    res += dict[s[i]] + right;
                    right=0;
                }
                else
                {
                    right += dict[s[i]];
                }
            }
            else if(s[i]=='V' || s[i]=='L' || s[i]=='D')
            {
                if(i-1>=0 && dict[s[i-1]]<dict[s[i]])
                {
                    res += right;
                    right = dict[s[i]];
                }
                else if(right>0)
                {
                    res += dict[s[i]]+right;
                    right=0;
                }
                else
                {
                    right = dict[s[i]];
                }
            }
        }

        return res+right;;
    }
};

class SolutionLeetCode
{
public:
    int romanToInt(std::string s)
    {
        int sum=0;
        if(s.find("IV")!=std::string::npos){sum-=2;}
        if(s.find("IX")!=std::string::npos){sum-=2;}
        if(s.find("XL")!=std::string::npos){sum-=20;}
        if(s.find("XC")!=std::string::npos){sum-=20;}
        if(s.find("CD")!=std::string::npos){sum-=200;}
        if(s.find("CM")!=std::string::npos){sum-=200;}

        for(size_t i=0; i<s.length(); ++i)
        {
            if(s[i]=='M') sum+=1000;
            if(s[i]=='D') sum+=500;
            if(s[i]=='C') sum+=100;
            if(s[i]=='L') sum+=50;
            if(s[i]=='X') sum+=10;
            if(s[i]=='V') sum+=5;
            if(s[i]=='I') sum+=1;
        }

        return sum;
    }
};

class SolutionLeetCode2
{
public:
    int romanToInt(std::string s) {
        int num = 0;
        int size = s.size();

        for (int i = 0; i < size; i++)
        {
            if (i < (size - 1) && (
                        ('I' == s[i] && ('V' == s[i + 1] || 'X' == s[i + 1])) ||
                        ('X' == s[i] && ('L' == s[i + 1] || 'C' == s[i + 1])) ||
                        ('C' == s[i] && ('D' == s[i + 1] || 'M' == s[i + 1])) ))
            {
                num -= romanCharToInt(s[i]);
            }
            else
            {
                num += romanCharToInt(s[i]);
            }
        }
        return num;
    }

    int romanCharToInt(char c)
    {
        switch (c)
        {
            case 'I':   return 1;
            case 'V':   return 5;
            case 'X':   return 10;
            case 'L':   return 50;
            case 'C':   return 100;
            case 'D':   return 500;
            case 'M':   return 1000;
            default:    return 0;
        }
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

