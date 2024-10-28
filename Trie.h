#pragma once
#include <string>
#include <iostream>

const int ALPHABET_SIZE = 26;

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;

    TrieNode() : isEndOfWord(false) {
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            children[i] = nullptr;
        }
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    ~Trie() {
        deleteTrie(root);
    }

    void deleteTrie(TrieNode* node);
    void insert(const std::string& word);
    void findWords(TrieNode* node, const std::string& prefix, std::string currentWord, std::string result[], int& count);
    void autoComplite(const std::string& prefix, std::string result[], int& count);

private:
    TrieNode* root;
};



