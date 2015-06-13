#include<iostream>
#include<cassert>
#include<string>
#include<unordered_set>
#include<vector>

class SolutionBruteForce
{
public:
    int numDistinct(const std::string& s, const std::string& t)
    {
        std::string ts;
        std::string tt;
        std::unordered_set<std::string> subsequences_s;
        std::unordered_set<std::string> subsequences_t;
        generate_subsequences(s, 0, ts, subsequences_s);
        generate_subsequences(t, 0, tt, subsequences_t);

        int nums=0;
        for(const auto& ts : subsequences_t)
        {
            if(subsequences_s.count(ts)==0)
                nums++;
        }

        return nums;
    }

private:
    void generate_subsequences(const std::string& from
            , int index
            , std::string& to
            , std::unordered_set<std::string>& subsequences)
    {
        if(be_a_solution(from, index))
        {
            process_solution(to, subsequences);
        }
        else
        {
            //construct_candidates
            char candidates[2] = {from[index], '\0'};
            int sz=to.size();
            for(size_t i=0; i<2; ++i)
            {
                if(candidates[i]!='\0')
                    to.push_back(candidates[i]);
                //make_move
                generate_subsequences(from, index+1, to, subsequences);
                unmake_move(to, sz);
            }
        }
    }

    bool be_a_solution(const std::string& from, size_t index)
    {
        return from.size()==index;
    }

    void process_solution(const std::string& solution, std::unordered_set<std::string>& subsequences)
    {
        if(!solution.empty())
            subsequences.insert(solution);
    }

    void unmake_move(std::string& to, int sz)
    {
        while((int)to.size()>sz)
        {
            to.pop_back();
        }
    }
};

class SolutionLeetCode
{
public:
    int numDistinct(std::string s, std::string t)
    {
        int m = t.length();
        int n = s.length();
        if (m > n) return 0;// impossible for subsequence

        std::vector<int> path(m+1, 0);
        path[0] = 1;// initial condition

        for (int j = 1; j <= n; j++)
        {
            // traversing backwards so we are using path[i-1] from last time step
            for (int i = m; i >= 1; i--) {
                path[i] = path[i] + (t[i-1] == s[j-1] ? path[i-1] : 0);
            }
        }

        return path[m];
    }
};

int main()
{
    SolutionLeetCode s_;
    std::string a="anacondastreetracecar";
    std::string b="contra";
    std::cout<<s_.numDistinct(a, b)<<std::endl;
    return 0;
}

