#include<iostream>
#include<cassert>
#include<string>
#include<vector>

class Solution
{
public:
    std::string convert(std::string s, int numRows)
    {
        if(numRows<=1) return s;

        std::string res;
        int len=s.length();
        int cnt_cell = len/(2*numRows-2)+1;

        int step=2*numRows-2;
        for(int i=0; i<numRows; ++i)
        {
            for(int j=0; j<cnt_cell; ++j)
            {
                if(i==0)
                {
                    int index=j*step;
                    if(index<len)
                        res.push_back(s[index]);
                }
                else if(i==numRows-1)
                {
                    int index=j*step+i;
                    if(index<len)
                        res.push_back(s[index]);
                }
                else
                {
                    int index=j*step+i;
                    if(index<len)
                        res.push_back(s[index]);

                    index=(j+1)*step-i;
                    if(index<len)
                        res.push_back(s[index]);
                }
            }
        }

        return res;
    }
};

/*
求出s[i]在结果中的排数这种做法也很好，值得重视
*/
class SolutionLeetCode
{
public:
    std::string convert(std::string s, int nRows)
    {

        if (nRows <= 1)
            return s;

        const int len = (int)s.length();
        std::vector<std::string> str(nRows);

        int row = 0, step = 1;
        for (int i = 0; i < len; ++i)
        {
            str[row].push_back(s[i]);

            if (row == 0)
                step = 1;
            else if (row == nRows - 1)
                step = -1;

            row += step;
        }

        s.clear();
        for (int j = 0; j < nRows; ++j)
        {
            s.append(str[j]);
        }

        return s;
    }
};

int main()
{
    Solution s;
    std::cout<<std::endl;
    return 0;
}

