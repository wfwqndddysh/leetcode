#include<iostream>
#include<cassert>
#include<vector>

class Solution
{
public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        n_=n;
        std::vector<std::vector<bool>> flags(n, std::vector<bool>(n, false));

        std::vector<std::pair<int, int>> queens_loc;
        backtrack(0, flags, queens_loc);
        return solved_;
    }

private:
    void backtrack(int cur
            , std::vector<std::vector<bool>>& flags
            , std::vector<std::pair<int, int>>& queens_loc)
    {
        if(cur==n_)
        {
            construct_solution(queens_loc);
        }
        else
        {
            std::vector<std::pair<int, int>> candiates;
            size_t sz=construct_candiates(flags, candiates);
            for(size_t i=0; i<sz; ++i)
            {
                std::vector<std::pair<int, int>> sets;
                queens_loc.push_back({candiates[i].first, candiates[i].second});
                set_flags(candiates[i].first, candiates[i].second, sets, flags);

                backtrack(cur+1, flags, queens_loc);

                reset_flags(sets, flags);
                queens_loc.pop_back();
            }
        }
    }

    size_t construct_candiates(const std::vector<std::vector<bool>>& flags
            , std::vector<std::pair<int, int>>& candiates)
    {
        int i;
        int j;
        if(!find_first_candiate(flags, i, j)) return 0;

        candiates.push_back({i, j});

        for(int r=i, c=j-1; c>=0; --c)
        {
            if(!flags[r][c]) candiates.push_back({r, c});
        }
        for(int r=i, c=j+1; c<n_; ++c)
        {
            if(!flags[r][c]) candiates.push_back({r, c});
        }

        return candiates.size();
    }

    bool find_first_candiate(const std::vector<std::vector<bool>>& flags, int& r, int& c)
    {
        for(int i=0; i<n_; ++i)
        {
            for(int j=0; j<n_; ++j)
            {
                if(!flags[i][j])
                {
                    r=i;
                    c=j;
                    return true;
                }
            }
        }
        return false;
    }

    void construct_solution(const std::vector<std::pair<int ,int>>& queens_loc)
    {
        solved_.push_back(std::vector<std::string>(n_, std::string(n_, '.')));
        for(size_t i=0; i<queens_loc.size(); ++i)
        {
            solved_.back()[queens_loc[i].first][queens_loc[i].second]='Q';
        }
    }

    void set_flags(int i, int j
            , std::vector<std::pair<int ,int>>& sets
            , std::vector<std::vector<bool>>& flags)
    {
        flags[i][j]=true;
        sets.push_back({i, j});

        for(int r=i, c=0; c<n_; ++c)
        {
            if(!flags[r][c] && c!=j)
            {
                flags[r][c]=true;
                sets.push_back({r, c});
            }
        }

        for(int r=0, c=j; r<n_; ++r)
        {
            if(!flags[r][c] && r!=i)
            {
                flags[r][c]=true;
                sets.push_back({r, c});
            }
        }

        for(int r=(i<j?0:i-j), c=(i<j?j-i:0); r<n_ && c<n_; ++r, ++c)
        {
            if(!flags[r][c] && r!=i)
            {
                flags[r][c]=true;
                sets.push_back({r, c});
            }
        }

        for(int r=(i+j<n_?0:i+j-n_+1), c=(i+j<n_?i+j:n_-1); r<n_ && c>=0; ++r, --c)
        {
            if(!flags[r][c] && r!=i)
            {
                flags[r][c]=true;
                sets.push_back({r, c});
            }
        }
    }

    void reset_flags(const std::vector<std::pair<int, int>>& resets
            , std::vector<std::vector<bool>>& flags)
    {
        for(size_t i=0; i<resets.size(); ++i)
            flags[resets[i].first][resets[i].second]=false;
    }

private:
    int n_;
    std::vector<std::vector<std::string>> solved_;
};

int main()
{
    Solution s;
    auto vv = s.solveNQueens(4);
    for(const auto& v : vv)
    {
        for(const auto& s : v)
            std::cout<<s<<" "<<std::endl;

        std::cout<<std::endl;
        std::cout<<"---------------------------------------------\n";
        std::cout<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

