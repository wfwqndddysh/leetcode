#include<iostream>
#include<cassert>
#include<vector>
#include<string>

class Solution
{
public:
    std::vector<std::string> letterCombinations(std::string digits)
    {
        if(digits.empty()) return res_;

        std::vector<std::string> dict(10, "");
        dict[2]="abc";
        dict[3]="def";
        dict[4]="ghi";
        dict[5]="jkl";
        dict[6]="mno";
        dict[7]="pqrs";
        dict[8]="tuv";
        dict[9]="wxyz";

        std::string combination;
        backtrack(dict, digits, 0, combination);
        return res_;
    }

private:
    void backtrack(std::vector<std::string>& dict, std::string& digits, size_t cur, std::string& combination)
    {
        if(cur==digits.length())
        {
            res_.push_back(combination);
        }
        else
        {
            for(size_t i=0; i<dict[digits[cur]-'0'].size(); ++i)
            {
                combination.push_back(dict[digits[cur]-'0'][i]);
                backtrack(dict, digits, cur+1, combination);
                combination.pop_back();
            }
        }
    }

private:
    std::vector<std::string> res_;
};

int main()
{
    Solution s;
    auto vs = s.letterCombinations("2");

    for(const auto str : vs)
        std::cout<<str<<std::endl;

    std::cout<<std::endl;
    return 0;
}

