#include<iostream>
#include<cassert>
#include<string>

class Solution
{
public:
    int lengthOfLastWord(std::string s)
    {
        int len = s.length();
        int last_len = 0;
        for(int i=len-1; i>=0; --i)
        {
            if(s[i]!=' ')
            {
                last_len++;
            }
            else if(last_len>0)
            {
                break;
            }
        }

        return last_len;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

