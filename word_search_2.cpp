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

    TrieNode* children_[26];
    bool is_end_;
};

class Trie
{
public:
    TrieNode* find(TrieNode* cur, int letter)
    {
    }

    void insert(const std::string& word)
    {
    }

private:
    TrieNode* root_;
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
                backtrack(board, i, j, trie.find(nullptr, board[i][j]), word);
            }
        }

        return res_;
    }

private:
    void backtrack(std::vector<std::vector<char>>& board
            , int i
            , int j
            , TrieNode* trie_node
            , std::string& found)
    {
        if(trie_node==nullptr) return;

        if(trie_node->is_end_)
        {
            res_.push_back(found);
        }

        int l=board.size();
        int c=board[0].size();

        if(i<0 || j<0 || i==l || j==c) return;

        char tmp=board[i][j];
        board[i][j] = '\0';
        
        backtrack(board, i, j+1, word, k+1);
        backtrack(board, i+1, j, word, k+1);
        backtrack(board, i-1, j, word, k+1);
        backtrack(board, i, j-1, word, k+1);

        board[i][j] = tmp;
    }

private:
    std::vector<std::string> res_;
};

int main()
{
    Solution s;
    std::vector<std::vector<char>> board{{'a', 'a'}};
    return 0;
}

