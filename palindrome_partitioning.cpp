#include<iostream>
#include<cassert>
#include<vector>
#include<string>

using namespace std;

class Solution
{
public:
    vector<vector<string>> partition(string s)
    {
        s_ = s;
        vector<string> v;
        backtrack(v, 0);
        return palindroms_;
    }

private:
    void backtrack(vector<string>& s, size_t s_end)
    {
        if(be_a_solution(s_end))
        {
            process_solution(s);
            return;
        }

        vector<string> v;
        vector<size_t> v_end;
        construct_candidates(s_end, v, v_end);

        for(size_t i=0; i<v.size(); ++i)
        {
            size_t sz=s.size();

            //make_move
            s.push_back(v[i]);

            backtrack(s, v_end[i]);

            //unmake_move
            while(s.size()>sz)
                s.pop_back();
        }
    }

    bool be_a_solution(size_t end)
    {
        return end>=s_.size();
    }

    void process_solution(const vector<string>& v)
    {
        palindroms_.push_back(v);
    }

    void construct_candidates(size_t start, vector<string>& v, vector<size_t>& v_end)
    {
        for(size_t len=1; len<=s_.size()-start; ++len)
        {
            if(be_palindrom(start, start+len-1))
            {
                v.push_back(s_.substr(start, len));
                v_end.push_back(start+len);
            }
        }
    }

    bool be_palindrom(size_t beg, size_t end)
    {
        for(; beg<end; ++beg, --end)
        {
            if(s_[beg]!=s_[end])
                return false;
        }
        return true;
    }

private:
    string s_;
    vector<vector<string>> palindroms_;
};

int main()
{
    Solution s;
    const std::string& ss{"aab"};
    auto vv = s.partition(ss);

    for(const auto& v : vv)
    {
        for(const auto& sss : v)
            std::cout<<sss<<" ";
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

