#include "Trie.h"

void Trie::deleteTrie(TrieNode* node) {
    for (int i = 0; i < ALPHABET_SIZE; ++i) {
        if (node->children[i]) {
            deleteTrie(node->children[i]);
        }
    }
    delete node;
}

void Trie::insert(const std::string& word) {
    TrieNode* node = root;
    for (char ch : word) {
        int index = ch - 'a';
        if (!node->children[index]) {
            node->children[index] = new TrieNode();
        }
        node = node->children[index];
    }
    node->isEndOfWord = true;
}

void Trie::findWords(TrieNode* node, const std::string& prefix, std::string currentWord, std::string result[], int& count) {
    if (node->isEndOfWord)
        result[count++] = currentWord;

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (node->children[i])
            findWords(node->children[i], prefix, currentWord + char('a' + i), result, count);
    }
}

void Trie::autoComplite(const std::string& prefix, std::string result[], int& count) {
    TrieNode* node = root;
    for (char ch : prefix) {
        int index = ch - 'a';
        if (!node->children[index])
            return; // если нет совпадений, выходим
        node = node->children[index];
    }
    findWords(node, prefix, prefix, result, count);
}