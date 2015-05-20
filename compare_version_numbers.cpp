#include<iostream>
#include<cassert>
#include<string>
#include<vector>

class Solution
{
public:
    int compareVersion(const std::string& ver1, const std::string& ver2)
    {
        if(ver1.empty() || ver2.empty()) return 0;

        std::vector<std::string> ver1_s;
        std::vector<std::string> ver2_s;
        std::vector<int> ver1_n;
        std::vector<int> ver2_n;

        split_to_num(ver1, ver1_s, ver1_n);
        split_to_num(ver2, ver2_s, ver2_n);

        size_t i=0, j=0;
        for(; i<ver1_n.size() && j<ver2_n.size(); ++i, ++j)
        {
            if(ver1_n[i]>ver2_n[i])
                return 1;
            else if(ver1_n[i]<ver2_n[i])
                return -1;
        }

        if(i==ver1_n.size() && j==ver2_n.size())
            return 0;
        else if(i==ver1_n.size())
        {
            for(; j<ver2_n.size(); ++j)
                if(ver2_n[j]!=0)
                    return -1;
        }
        else
        {
            for(; i<ver1_n.size(); ++i)
                if(ver1_n[i]!=0)
                    return 1;
        }
        return 0;
    }

    void split_to_num(const std::string& ver
            , std::vector<std::string>& ss
            , std::vector<int>& nums)
    {
        if(ver.empty()) return;

        std::string tmp;
        for(size_t i=0; i<ver.size(); ++i)
        {
            if(ver[i]!='.')
            {
                tmp += ver[i];
            }
            else
            {
                ss.push_back(tmp);
                nums.push_back(get_num(tmp));
                tmp.clear();
            }
        }
        if(!tmp.empty())
        {
            ss.push_back(tmp);
            nums.push_back(get_num(tmp));
        }
    }

    int get_num(std::string& s)
    {
        while(!s.empty() && s[0]=='0')
        {
            s.erase(0, 1);
        }
        return s.empty() ? 0 : std::stoi(s.c_str());
    }
};

int main()
{
    Solution s;
    //std::cout<<s.compareVersion("1.0", "1.1")<<std::endl;
    std::cout<<s.compareVersion("1.01.1", "1.1.1")<<std::endl;
    return 0;
}

