#include<iostream>
#include<cassert>
#include<string>
#include<vector>
#include<unordered_map>

class Solution
{
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words)
    {
        std::vector<int> ret;
        if(s.empty() || words.empty()) return ret;
        std::unordered_map<std::string, int> dict;
        make_dict(words, dict);
        std::unordered_map<std::string, int> orignal_dict(dict);

        int sz=s.size();
        int word_len=words[0].size();
        int cnt_words=words.size();
        int cnt_chars=word_len*cnt_words;

        for(int start=0; start<=sz-cnt_chars; ++start)
        {
            int cnt=0;
            int cur=start;
            for(; cnt<cnt_words; ++cnt, cur+=word_len)
            {
                auto itr=dict.find(s.substr(cur, word_len));

                if(itr==dict.cend() || itr->second==0)
                    break;
                else
                    itr->second--;
            }
            if(cnt==cnt_words) ret.push_back(start);

            if(cnt>0) reset_dict(orignal_dict, dict);
        }

        return ret;
    }

private:
    void make_dict(const std::vector<std::string>& words
            , std::unordered_map<std::string, int>& dict)
    {
        for(const auto& w : words)
        {
            dict[w]++;
        }
    }

    void reset_dict (std::unordered_map<std::string, int>& orignal_dict
            , std::unordered_map<std::string, int>& dict)
    {
        for(auto itr_o=orignal_dict.begin(), itr=dict.begin(); itr_o!=orignal_dict.cend(); ++itr_o, ++itr)
        {
            itr->second=itr_o->second;
        }
    }
};

class SolutionLeetCode
{
public:
    std::vector<int> findSubstring(std::string S, std::vector<std::string> &L) {
        std::vector<int> ans;
        int n = S.size(), cnt = L.size();
        if (n <= 0 || cnt <= 0) return ans;

        // init word occurence
        std::unordered_map<std::string, int> dict;
        for (int i = 0; i < cnt; ++i) dict[L[i]]++;

        // travel all sub string combinations
        int wl = L[0].size();
        for (int i = 0; i < wl; ++i)//关键的地方在于明白为什么只要wl就够了
        {
            int left = i, count = 0;
            std::unordered_map<std::string, int> tdict;
            
            for (int j = i; j <= n - wl; j += wl)
            {
                std::string str = S.substr(j, wl);
                if (dict.count(str))// a valid word, accumulate results
                {
                    tdict[str]++;
                    if (tdict[str] <= dict[str])
                        count++;
                    else
                    {
                        // a more word, advance the window left side possiablly
                        while (tdict[str] > dict[str])
                        {
                            std::string str1 = S.substr(left, wl);
                            tdict[str1]--;
                            if (tdict[str1] < dict[str1]) count--;
                            left += wl;
                        }
                    }
                    // come to a result
                    if (count == cnt)
                    {
                        ans.push_back(left);
                        // advance one word
                        tdict[S.substr(left, wl)]--;
                        count--;
                        left += wl;
                    }
                }
                else// not a valid word, reset all vars
                {
                    tdict.clear();
                    count = 0;
                    left = j + wl;
                }
            }
        }

        return ans;
    }
};

int main()
{
    Solution s;

    //std::string str("a");
    //std::vector<std::string> words{"a", "a"};

    //std::string str("barfoothefoobarman");
    //std::vector<std::string> words{"foo","bar"};

    std::string str("wordgoodgoodgoodbestword");
    std::vector<std::string> words{"word","good","best","good"};

    auto v=s.findSubstring(str, words);

    for(int n : v)
        std::cout<<n<<" ";

    std::cout<<std::endl;
    return 0;
}

