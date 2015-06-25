#include<iostream>
#include<cassert>
#include<vector>
#include<algorithm>

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

class SolutionNext
{
public:
    std::string getPermutation(int n, int k)
    {
        std::string perm;
        if(k<=0) return perm;

        for(int i=1; i<=n; ++i)
        {
            perm.push_back(i-0+'0');
        }

        for(int i=2; i<=k; ++i)
        {
            int j=n-2;
            for(; j>=0; --j)
            {
                if(perm[j]<perm[j+1]) break;
            }

            if(j==-1) break;

            int min_i=-1;
            char min = '9'+1;
            for(int m=n-1; m>j; --m)
            {
                if(perm[m]>perm[j] && perm[m]<min)
                {
                    min_i = m;
                    min = perm[m];
                }
            }

            std::swap(perm[j], perm[min_i]);

            std::reverse(perm.begin()+j+1, perm.end());
        }

        return perm;
    }
};

class SolutionLeetCode
{
public:
    std::string getPermutation(int n, int k)
    {
        int i,j,f=1;
        //left part of s is partially formed permutation, right part is the leftover chars.
        std::string s(n,'0');
        for(i=1;i<=n;i++)
        {
            f*=i;
            s[i-1]+=i; // make s become 1234...n
        }
        for(i=0,k--;i<n;i++)
        {
            f/=n-i;
            j=i+k/f; // calculate index of char to put at s[i]
            char c=s[j];
            // remove c by shifting to cover up (adjust the right part).
            for(;j>i;j--)
                s[j]=s[j-1];
            k%=f;
            s[i]=c;
        }
        return s;
    }
};

int main()
{
    Solution s;
    SolutionNext sn;
    SolutionLeetCode sl;
    //std::cout<<s.getPermutation(3, 4)<<std::endl;
    //std::cout<<s.getPermutation(9, 331987)<<std::endl;
    std::cout<<sl.getPermutation(8, 8590)<<std::endl;
    return 0;
}

