#include<iostream>
#include<cassert>
#include<vector>
#include<string>

class Solution
{
public:
    std::vector<int> diffWaysToCompute(std::string input)
    {
        std::vector<int> res;
        divide_conquer(input, 0, input.size(), res);
        return res;
    }

private:
    void divide_conquer(const std::string& input, int beg, int end, std::vector<int>& result)
    {
        if(beg==end) return;

        int tmp=beg;
        int a=input_to_num(input, tmp);
        if(tmp==end)
        {
            result.push_back(a);
            return;
        }

        int cnt_candiates=get_candiates_cnt(input, beg, end);
        for(int i=0; i<cnt_candiates; ++i)
        {
            int l_beg=beg;
            int l_end=-1;
            int r_beg=-1;
            int r_end=end;
            divide(input, beg, i, l_end, r_beg);

            std::vector<int> l_result;
            divide_conquer(input, l_beg, l_end, l_result);

            std::vector<int> r_result;
            divide_conquer(input, r_beg, r_end, r_result);

            //merge
            int op=input[l_end];
            for(auto l_n : l_result)
            {
                for(auto r_n : r_result)
                    result.push_back(cal(l_n, op, r_n));
            }
        }
    }

    int get_candiates_cnt(const std::string& input, int beg, int end)
    {
        int cnt=0; 
        
        for(; beg!=end; ++beg)
        {
            if(!(input[beg]>='0' && input[beg]<='9'))
                cnt++;
        }
        return cnt;
    }

    void divide(const std::string& input, int beg, int op_nth, int& l_end, int &r_beg)
    {
        for(int i=-1; i<op_nth; ++beg)
        {
            if(!(input[beg]>='0' && input[beg]<='9'))
            {
                ++i;
            }
        }
        l_end=beg-1;
        r_beg=beg;
    }

    int input_to_num(const std::string& input, int& cur)
    {
        int res=0;
        while(input[cur]>='0' && input[cur]<='9')
        {
            res = res*10+input[cur]-'0';
            cur++;
        }
        return res;
    }

    int cal(int a, char op, int b)
    {
        if(op=='+') return a+b;
        else if(op=='-') return a-b;
        else return a*b; //(op=='*')
    }
};

int main()
{
    Solution s;
    //std::string input("0+1");
    //std::string input("11");
    //std::string input("1+2+3");
    //std::string input("2-1-1");
    //std::string input("2*3-4*5");
    //std::string input("3-4");
    std::string input("10+5");

    auto v=s.diffWaysToCompute(input);

    for(int n : v)
    {
        std::cout<<n<<" ";
    }

    std::cout<<std::endl;
    return 0;
}

