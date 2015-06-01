#include<iostream>
#include<cassert>
#include<unordered_map>
#include<unordered_set>
#include<string>
#include<vector>
#include<stack>
#include<list>

/*
Backtrack-DFS(A, k)
    if A = (a1 , a2 , ..., ak ) is a solution, report it.
    else
        k = k + 1
        compute Sk
        while Sk != ∅ do
            ak = an element in Sk
            Sk = Sk − ak
            Backtrack-DFS(A, k)
*/

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
    std::vector<std::string> wordBreak(std::string s, const std::unordered_set<std::string> &dict)
    {
        s_ = s;
        dict_= dict;

        std::string sentence;
        backtrack(sentence, 0);
        return sentences_;
    }

private:
    void backtrack(std::string& sentence, size_t k)
    {
        std::vector<std::string> c;

        if(be_a_solution(sentence, k))
            process_solution(sentence);

        construct_candidates(k ,c);

        for(size_t i=0; i<c.size(); ++i)
        {
            //每次构造了一个新的sentence, 不需要make_move/unmake_move
            std::string s = sentence+c[i] + " ";
            backtrack(s, k+c[i].length());
        }
    }

    bool be_a_solution(const std::string& c, size_t k)
    {
        (void)c;
        return k==s_.length();
    }

    void process_solution(std::string& c)
    {
        c.erase(--c.end());
        sentences_.push_back(c);
    }

    void construct_candidates(size_t k, std::vector<std::string>& candidates)
    {
        if(!be_suffix(k))
            return;

        for(size_t len=1; len<=s_.length()-k; ++len)
        {
            const std::string word = s_.substr(k, len);
            if(dict_.count(word)>0)
                candidates.push_back(word);
        }
    }

    bool be_suffix(size_t k)
    {
        for(; k<s_.length(); ++k)
        {
            const std::string word = s_.substr(k);
            if(dict_.count(word)>0)
                return true;
        }
        return false;
    }

private:
    std::string s_;
    std::unordered_set<std::string> dict_;
    std::vector<std::string> sentences_;
};

int main()
{
    Solution s;

    //auto ss="leetcode";
    //std::unordered_set<std::string> m{"leet", "code"};

    //auto ss="ab";
    //std::unordered_set<std::string> m{"a", "b"};

    //auto ss="catsanddog";
    //std::unordered_set<std::string> m{"cat", "cats", "and", "sand", "dog"};

    auto ss = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
    std::unordered_set<std::string> m{"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};

    std::vector<std::string> ret = s.wordBreak(ss, m);
    for(const auto& sentence : ret)
    {
        std::cout<<sentence<<std::endl;
    }
    return 0;
}

