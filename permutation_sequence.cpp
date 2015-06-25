#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::string getPermutation(int n, int k)
    {
        n_ = n;
        k_ = k;
        found_ = false;
        std::vector<bool> flags(n+1, false);
        std::string perm;

        int nth=0;
        backtrack(0, nth, perm, flags);
        return perm;
    }
private:
    void backtrack(int cur, int& nth, std::string& perm, std::vector<bool>& flags)
    {
        if(cur==n_)
        {
            if(++nth==k_) found_ = true;
            return;
        }
        else
        {
            for(int i=1; i<=n_; ++i)
            {
                if(!flags[i])
                {
                    flags[i]=true;
                    perm.push_back(i-0+'0');
                    backtrack(cur+1, nth, perm, flags);

                    if(found_) break;

                    flags[i]=false;
                    perm.pop_back();
                }
            }
        }
    }

private:
    int n_;
    int k_;
    bool found_;
};

int main()
{
    Solution s;
    //std::cout<<s.getPermutation(3, 4)<<std::endl;
    std::cout<<s.getPermutation(9, 331987)<<std::endl;
    return 0;
}

