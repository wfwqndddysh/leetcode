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

        std::vector<int> ver1_n;
        std::vector<int> ver2_n;

        split_to_num(ver1, ver1_n);
        split_to_num(ver2, ver2_n);

        size_t i=0, j=0;
        int num1 = 0;
        int num2 = 0;
        for(; i<ver1_n.size() || j<ver2_n.size(); ++i, ++j)
        {
            num1 = i<ver1_n.size() ? ver1_n[i] : 0;
            num2 = j<ver2_n.size() ? ver2_n[j] : 0;
            
            if(num1>num2)
                return 1;
            else if(num1<num2)
                return -1;
        }

        return 0;
    }

    void split_to_num(const std::string& ver
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
                nums.push_back(std::stoi(tmp));
                tmp.clear();
            }
        }
        if(!tmp.empty())
        {
            nums.push_back(std::stoi(tmp));
        }
    }

    //from leetcode
    int compareVersion_(const std::string& version1, const std::string& version2)
    {
        int i = 0;
        int j = 0;
        int n1 = version1.size();
        int n2 = version2.size();

        int num1 = 0;
        int num2 = 0;
        while(i<n1 || j<n2)
        {
            while(i<n1 && version1[i]!='.')
            {
                num1 = num1*10+(version1[i]-'0');
                i++;
            }

            while(j<n2 && version2[j]!='.')
            {
                num2 = num2*10+(version2[j]-'0');;
                j++;
            }

            if(num1>num2) return 1;
            else if(num1 < num2) return -1;

            num1 = 0;
            num2 = 0;
            i++;
            j++;
        }

        return 0;
    }
};

int main()
{
    Solution s;
    //std::cout<<s.compareVersion("1.0", "1.1")<<std::endl;
    std::cout<<s.compareVersion_("1.01", "1.1")<<std::endl;
    return 0;
}

