#include<iostream>
#include<cassert>
#include<vector>
#include<climits>
#include<tuple>

class Solution
{
public:
    using Elem = std::tuple<int, int, int, int>;

    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon)
    {
        if(dungeon.size()==0)
            return 0;


        auto rows = dungeon.size();
        auto columns = dungeon.front().size();
        //first: mini to here, second:hp when leave here
        //third: mini to here where hp is largest
        //four: largest hp
        std::vector<std::vector<Elem>> mini_hp;
        mini_hp.resize(rows);
        for(auto& n : mini_hp)
        {
            n.resize(columns);
        }

        for(size_t r=0; r<rows; ++r)
        {
            for(size_t c=0; c<columns; ++c)
            {
                if(c==0 && r==0)
                {
                    int cur = dungeon[r][c];
                    bool hurt = cur <= 0;
                    int mini = hurt ? std::abs(cur)+1 : 0;
                    int hp = hurt ? 1 : cur;
                    mini_hp[r][c] = std::make_tuple(mini, hp, mini, hp);
                    continue;
                }
                else if(r==0)
                {
                    const auto& right = mini_hp[r][c-1];
                    do_one(dungeon[r][c], right, mini_hp[r][c]);
                }
                else if(c==0)
                {
                    const auto& up = mini_hp[r-1][c];
                    do_one(dungeon[r][c], up, mini_hp[r][c]);
                }
                else
                {
                    const auto& up = mini_hp[r-1][c];
                    const auto& right = mini_hp[r][c-1];
                    do_it(dungeon[r][c], up, right, mini_hp[r][c]);
                }
            }
        }
        int init_hp = std::get<0>(mini_hp[rows-1][columns-1]);
        return init_hp > 0 ? init_hp : 1;
    }

    void do_it(int hp
            , const Elem& up
            , const Elem& right
            , Elem& cur)
    {
        Elem from_up;
        Elem from_right;

        do_one(hp, up, from_up);
        do_one(hp, right, from_right);

        int mini_up = std::get<0>(from_up);
        int mini_up_hp = std::get<1>(from_up);
        int mini_right = std::get<0>(from_right);
        int mini_right_hp = std::get<1>(from_right);

        if(mini_up < mini_right)
        {
            std::get<0>(cur) = mini_up;
            std::get<1>(cur) = mini_up_hp;
        }
        else if(mini_up > mini_right)
        {
            std::get<0>(cur) = mini_right;
            std::get<1>(cur) = mini_right_hp;
        }
        else
        {
            if(mini_up_hp > mini_right_hp)
            {
                std::get<0>(cur) = mini_up;
                std::get<1>(cur) = mini_up_hp;
            }
            else
            {
                std::get<0>(cur) = mini_right;
                std::get<1>(cur) = mini_right_hp;
            }
        }

        int more_hp_up = std::get<2>(from_up);
        int more_hp_up_hp = std::get<3>(from_up);
        int more_hp_right = std::get<2>(from_right);
        int more_hp_right_hp = std::get<3>(from_right);

        if(more_hp_up_hp-more_hp_up>more_hp_right_hp-more_hp_right)
        {
            std::get<2>(cur) = more_hp_up;
            std::get<3>(cur) = more_hp_up_hp;
        }
        else if(more_hp_up_hp-more_hp_up<more_hp_right_hp-more_hp_right)
        {
            std::get<2>(cur) = more_hp_right;
            std::get<3>(cur) = more_hp_right_hp;
        }
        else
        {
            if(more_hp_up<more_hp_right)
            {
                std::get<2>(cur) = more_hp_up;
                std::get<3>(cur) = more_hp_up_hp;
            }
            else
            {
                std::get<2>(cur) = more_hp_right;
                std::get<3>(cur) = more_hp_right_hp;
            }
        }
    }

    void do_one(int hp, const Elem& prev, Elem& cur)
    {
        int a=0;
        int b=0;
        int c=0;
        int d=0;

        int diff = std::get<1>(prev)+hp;
        if(diff>0)
        {
            a = std::get<0>(prev);
            b = diff;
        }
        else
        {
            a = std::get<0>(prev)+std::abs(diff)+1;
            b = 1;
        }

        diff = std::get<3>(prev)+hp;
        if(diff>0)
        {
            c = std::get<2>(prev);
            d = diff;
        }
        else
        {
            c = std::get<2>(prev)+std::abs(diff)+1;
            d = 1;
        }

        if((d-c)<(b-a))
        {
            c = a;
            d = b;
        }

        if(c<a)
        {
            int tmp = a;
            a = c;
            c = tmp;
            tmp = b;
            b = d;
            d = tmp;
        }

        std::get<0>(cur) = a;
        std::get<1>(cur) = b;
        std::get<2>(cur) = c;
        std::get<3>(cur) = d;
    }

    //其实这个题的关键之一在于你需要从后往前算，而不是从前王后，像上面一样
    //关键之二是需要归纳的是在hp[r][c]代表的是在r,c处需要的最小值
    //从前往后更容易想到，但是从后往前更加简单
    int calculateMinimumHP_back(std::vector<std::vector<int>>& dungeon)
    {
        if(dungeon.size()==0 || dungeon[0].size()==0)
            return 0;

        int rows = dungeon.size();
        int columns = dungeon.front().size();
        //使用dummy技术使得代码清晰是非常重要的
        std::vector<std::vector<int>> hp(rows+1, std::vector<int>(columns+1, INT_MAX));
        hp[rows][columns-1] = 1;
        hp[rows-1][columns] = 1;

        for(int r=rows-1; r>=0; --r)
        {
            for(int c=columns-1; c>=0; --c)
            {
                int need = std::min(hp[r][c+1], hp[r+1][c])-dungeon[r][c];
                hp[r][c] = need <=0 ? 1 : need;
            }
        }
        return hp[0][0];
    }
};

int main()
{
    Solution s;
    //std::vector<std::vector<int>> dungeon {{0,-3}};
    //std::vector<std::vector<int>> dungeon {{0,5}, {-2, -3}};
    //std::vector<std::vector<int>> dungeon {{1}, {-2}, {1}};
    std::vector<std::vector<int>> dungeon {{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}};
    std::cout<<s.calculateMinimumHP(dungeon)<<std::endl;
    return 0;
}

