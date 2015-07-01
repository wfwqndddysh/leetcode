#include<iostream>
#include<cassert>

class Solution
{
public:
    std::string countAndSay(int n)
    {
        if(n<=1) return "";

        std::string solution{"1"};
        if(n==1) return solution;

        for(int i=1; i<n; ++i)
        {
            std::string tmp;

            char c=solution[0];
            int cnt=1;
            for(size_t j=1; j<solution.size(); ++j)
            {
                if(solution[j]==c)
                    cnt++;
                else
                {
                    tmp.push_back(cnt+'0');
                    tmp.push_back(c);
                    c=solution[j];
                }
            }

            tmp.push_back(cnt+'0');
            tmp.push_back(c);

            solution=tmp;
        }

        return solution;
    }
};

int main()
{
    Solution s;
    std::cout<<s.countAndSay(5)<<std::endl;
    return 0;
}

