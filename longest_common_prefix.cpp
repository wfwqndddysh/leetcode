#include<iostream>
#include<cassert>
#include<vector>
#include<string>

class Solution
{
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs)
    {
        if(strs.size()==0) return "";

        size_t longest=0;
        for(;;)
        {
            char cur_char;

            if(strs[0].size()==longest)
                return strs[0].substr(0, longest);
            else
                cur_char = strs[0][longest];

            for(size_t i=1; i<strs.size(); ++i)
            {
                if(strs[i].size()<=longest || strs[i][longest]!=cur_char)
                    return strs[0].substr(0, longest);
            }
            longest++;
        }

        return strs[0].substr(0, longest);
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

