#include<iostream>
#include<cassert>
#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>

class Solution
{
public:
    std::vector<std::string> anagrams(std::vector<std::string>& strs)
    {
        std::vector<std::string> res;
        std::unordered_map<std::string, int> groups;

        auto sz=strs.size();
        for(size_t i=0; i<sz; ++i)
        {
            std::string tmp = strs[i];
            std::sort(tmp.begin(), tmp.end());

            auto itr=groups.find(tmp);
            if(itr==groups.cend())
            {
                groups.insert(std::make_pair(tmp, i));
            }
            else
            {
                if(itr->second>=0)
                {
                    res.push_back(strs[itr->second]);
                    itr->second=-1;
                    res.push_back(strs[i]);
                }
                else
                {
                    res.push_back(strs[i]);
                }
            }
        }

        return res;
    }
};

int main()
{
    Solution s;
    std::vector<std::string> strs{"", ""};
    auto v = s.anagrams(strs);

    for(const auto& s : v)
        std::cout<<s<<" ";

    std::cout<<std::endl;
    return 0;
}

