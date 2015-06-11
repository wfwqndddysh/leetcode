#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::vector<int> getRow(int rowIndex)
    {
        std::vector<int> row;

        for(int i=1; i<=rowIndex+1; ++i)
        {
            row.push_back(1);
            if(i>2)
            {
                int tmp_0 = row[0];
                int tmp_1 = row[1];
                for(int j=1; j<i-1; ++j)
                {
                    row[j] = tmp_0+tmp_1;
                    tmp_0 = tmp_1;
                    tmp_1 = row[j+1];
                }
            }
        }

        return row;
    }
};

int main()
{
    Solution s;
    auto v = s.getRow(4);
    for(int n : v)
        std::cout<<n<<" ";
    std::cout<<std::endl;
    return 0;
}

