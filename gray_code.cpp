#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::vector<int> grayCode(int n)
    {
        std::vector<int> v(1,0);
        for (int i=1;i<(1<<n);i++) v.push_back(v[i-1]^(i&-i));
        return v;
    }
};

class SolutionFor
{
public:
    std::vector<int> grayCode(int n)
    {
        std::vector<int> result(1, 0);
        for (int i = 0; i < n; i++)
        {
            int sz = result.size();
            for(int j=sz-1; j>=0; --j)
            {
                int cur = result[j];
                cur += (1<<i);
                result.push_back(cur);
            }
        }
        return result;
    }
};


int main()
{
    SolutionFor s;
    auto v = s.grayCode(4);

    for(int n : v)
        std::cout<<std::boolalpha<<n<<std::endl;

    std::cout<<std::endl;
    return 0;
}

