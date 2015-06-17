#include<iostream>
#include<cassert>
#include<string>
#include<vector>

/*
bool finished = FALSE;
backtrack(int a[], int k, data input)
{
    int c[MAXCANDIDATES];
    int ncandidates;
    int i;
    if (is_a_solution(a,k,input))
        process_solution(a,k,input);
    else {
        k = k+1;
        construct_candidates(a,k,input,c,&ncandidates);
        for (i=0; i<ncandidates; i++)
        {
            a[k] = c[i];
            make_move(a,k,input);
            backtrack(a,k,input);
            unmake_move(a,k,input);
            if (finished) return;
        }
    }
}
*/

class Solution
{
public:
    std::vector<std::string> restoreIpAddresses(const std::string& s)
    {
        s_ = s;
        std::string address;
        if(s.length()>12) return addresses_;

        dfs_backtrack(0, 1, address);
        return addresses_;
    }
private:
    void dfs_backtrack(size_t cur, int nth, std::string& address)
    {
        if(be_a_solution(cur, nth))
        {
            process_solution(address);
        }
        else
        {
            size_t cnt_candidates=0;
            std::vector<size_t> candidates;
            construct_candidates(cur, nth, candidates, cnt_candidates);

            for(size_t i=0; i<cnt_candidates; ++i)
            {
                auto len=address.length();

                if(nth>1) address.push_back('.');
                for(size_t j=0; j<candidates[i]; ++j)
                {
                    address.push_back(s_[cur+j]);
                }

                dfs_backtrack(cur+candidates[i], nth+1, address);

                while(address.length()>len)
                    address.pop_back();
            }
        }
    }

    bool be_a_solution(size_t cur, int nth)
    {
        return cur==s_.size() && nth==5;
    }

    void process_solution(const std::string& address)
    {
        addresses_.push_back(address);
    }

    void construct_candidates(size_t cur, int nth, std::vector<size_t>& candidates, size_t& cnt_candidates)
    {
        if(nth>4) return;

        if(s_[cur]=='0')
        {
            candidates.push_back(1);
            cnt_candidates = 1;
            return;
        }

        int ip_num = 0;
        for(size_t i=cur; i<s_.size(); ++i)
        {
            ip_num = ip_num*10+s_[i]-'0';

            if(ip_num<=255)
            {
                candidates.push_back(i-cur+1);
                cnt_candidates++;
            }
            else
            {
                break;
            }
        }
    }

private:

    std::vector<std::string> addresses_;
    std::string s_;
};

int main()
{
    Solution s;
    auto v = s.restoreIpAddresses("172162541");

    for(const auto& ss : v)
        std::cout<<ss<<std::endl;

    return 0;
}

