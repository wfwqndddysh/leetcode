#include<iostream>
#include<cassert>
#include<vector>
#include<cstring>

struct TrieNode
{
    TrieNode() : is_end_(false)
    {
        memset(children_, 0, sizeof(children_));
    }

    bool is_end() const
    {
        return is_end_;
    }

    void set_end()
    {
        is_end_=true;
    }

    void clear_end()
    {
        is_end_=false;
    }

    TrieNode* find(char letter) const
    {
        return children_[letter-'a'];
    }

    TrieNode* insert(char letter)
    {
        children_[letter-'a']=new TrieNode();
        //std::cout<<children_[letter-'a']<<std::endl;
        return children_[letter-'a'];
    }

    TrieNode* children_[26];

private:
    bool is_end_;
};

class Trie
{
public:
    TrieNode* start()
    {
        return &root_;
    }

    void insert(const std::string& word)
    {
        auto node=&root_;
        for(char c : word)
        {
            node=node->find(c) ? node->find(c) : node->insert(c);
        }
        node->set_end();
    }

private:
    TrieNode root_;
};

class Solution
{
public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board
            , std::vector<std::string>& words)
    {
        if(board.size()==0) return {};
        std::vector<std::string> res;

        Trie trie;
        for(const auto& s : words)
            trie.insert(s);

        int l=board.size();
        int c=board[0].size();

        for(int i=0; i<l; ++i)
        {
            for(int j=0; j<c; ++j)
            {
                std::string word;
                backtrack(board, i, j, trie.start(), word);
            }
        }

        return res_;
    }

private:
    void backtrack(std::vector<std::vector<char>>& board
            , int i
            , int j
            , TrieNode* trie_node
            , std::string& word)
    {
        int l=board.size();
        int c=board[0].size();
        if(i<0 || j<0 || i==l || j==c) return;

        if(board[i][j]=='\0') return;

        char tmp=board[i][j];
        auto node=trie_node->find(tmp);
        if(!node) return;

        word.push_back(tmp);

        if(node->is_end())
        {
            res_.push_back(word);
            node->clear_end();
        }
        
        board[i][j] = '\0';

        backtrack(board, i, j+1, node, word),
        backtrack(board, i+1, j, node, word);
        backtrack(board, i-1, j, node, word);
        backtrack(board, i, j-1, node, word);

        word.pop_back();
        board[i][j] = tmp;
    }

private:
    std::vector<std::string> res_;
};

int main()
{
    Solution s;

    //std::vector<std::vector<char>> board{{'a', 'a'}};
    //std::vector<std::string> words{ "aaa" };

    //std::vector<std::vector<char>> board{{'a'}};
    //std::vector<std::string> words{ "a", "a" };

    //std::vector<std::vector<char>> board{{'a', 'a'}};
    //std::vector<std::string> words{ "a" };

    std::vector<std::vector<char>> board{{'a', 'b'},
                                         {'c', 'd'}};
    std::vector<std::string> words{ "ab","cb","ad","bd","ac","ca","da","bc","db","adcb","dabc","abb","acb" };

    /*
    std::vector<std::vector<char>> board{ {'b', 'a', 'a', 'b', 'a', 'b'},
                                          {'a', 'b', 'a', 'a', 'a', 'a'},
                                          {'a', 'b', 'a', 'a', 'a', 'b'},
                                          {'a', 'b', 'a', 'b', 'b', 'a'},
                                          {'a', 'a', 'b', 'b', 'a', 'b'},
                                          {'a', 'a', 'b', 'b', 'b', 'a'},
                                          {'a', 'a', 'b', 'a', 'a', 'b'} };

    std::vector<std::string> words{ {"bbaabaabaaaaabaababaaaaababb"},
                                    {"aabbaaabaaabaabaaaaaabbaaaba"},
                                    {"babaababbbbbbbaabaababaabaaa"},
                                    {"bbbaaabaabbaaababababbbbbaaa"},
                                    {"babbabbbbaabbabaaaaaabbbaaab"},
                                    {"bbbababbbbbbbababbabbbbbabaa"},
                                    {"babababbababaabbbbabbbbabbba"},
                                    {"abbbbbbaabaaabaaababaabbabba"},
                                    {"aabaabababbbbbbababbbababbaa"},
                                    {"aabbbbabbaababaaaabababbaaba"},
                                    {"ababaababaaabbabbaabbaabbaba"},
                                    {"abaabbbaaaaababbbaaaaabbbaab"},
                                    {"aabbabaabaabbabababaaabbbaab"},
                                    {"baaabaaaabbabaaabaabababaaaa"},
                                    {"aaabbabaaaababbabbaabbaabbaa"},
                                    {"aaabaaaaabaabbabaabbbbaabaaa"},
                                    {"abbaabbaaaabbaababababbaabbb"},
                                    {"baabaababbbbaaaabaaabbababbb"},
                                    {"aabaababbaababbaaabaabababab"},
                                    {"abbaaabbaabaabaabbbbaabbbbbb"},
                                    {"aaababaabbaaabbbaaabbabbabab"},
                                    {"bbababbbabbbbabbbbabbbbbabaa"},
                                    {"abbbaabbbaaababbbababbababba"},
                                    {"bbbbbbbabbbababbabaabababaab"},
                                    {"aaaababaabbbbabaaaaabaaaaabb"},
                                    {"bbaaabbbbabbaaabbaabbabbaaba"},
                                    {"aabaabbbbaabaabbabaabababaaa"},
                                    {"abbababbbaababaabbababababbb"},
                                    {"aabbbabbaaaababbbbabbababbbb"},
                                    {"babbbaabababbbbbbbbbaabbabaa"} };
                                    */

    //std::vector<std::vector<char>> board{ {'a'} };
    //std::vector<std::string> words{ "a" };

    auto vs=s.findWords(board, words);
    for(const auto& word : vs)
    {
        std::cout<<word<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

