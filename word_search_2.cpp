#include<iostream>
#include<cassert>
#include<vector>
#include<cstring>

struct TrieNode
{
    TrieNode() : is_end_(false)
    {
        memset(children_, '\0', sizeof(children_));
    }

    bool is_end() const
    {
        return is_end_;
    }

    void set_end()
    {
        is_end_=true;
    }

    TrieNode* find(char letter) const
    {
        return children_[letter-'a'];
    }

    TrieNode* insert(char letter)
    {
        children_[letter-'a']=new TrieNode();
        return children_[letter-'a'];
    }

    TrieNode* children_[26];

private:
    bool is_end_;
};

class Trie
{
public:
    TrieNode* start(int letter)
    {
        return root_.find(letter);
    }

    void insert(const std::string& word)
    {
        auto node=&root_;
        for(char c : word)
        {
            if(!node->find(c))
            {
                node=node->insert(c);
            }
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
                backtrack(board, trie, i, j, trie.start(board[i][j]), word);
            }
        }

        return res_;
    }

private:
    void backtrack(std::vector<std::vector<char>>& board
            , const Trie& trie
            , int i
            , int j
            , TrieNode* trie_node
            , std::string& word)
    {
        if(trie_node==nullptr) return;

        if(trie_node->is_end())
        {
            res_.push_back(word);
        }

        int l=board.size();
        int c=board[0].size();

        if(i<0 || j<0 || i==l || j==c) return;

        char tmp=board[i][j];
        word.push_back(tmp);
        board[i][j] = '\0';
        
        backtrack(board, trie, i, j+1, trie_node->find(tmp), word),
        backtrack(board, trie, i+1, j, trie_node->find(tmp), word);
        backtrack(board, trie, i-1, j, trie_node->find(tmp), word);
        backtrack(board, trie, i, j-1, trie_node->find(tmp), word);

        word.pop_back();
        board[i][j] = tmp;
    }

private:
    std::vector<std::string> res_;
};

int main()
{
    Solution s;
    std::vector<std::vector<char>> board{{'a', 'a'}};
    std::vector<std::string> words{ "aaa" };

    auto vs=s.findWords(board, words);

    for(const auto& s : vs)
    {
        std::cout<<s<<std::endl;
    }

    std::cout<<std::endl;
    return 0;
}

