#include "Trie.h"

int main() {
    setlocale(LC_ALL, "rus");
    Trie trie;

    // Вставка слов в Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("banana");
    trie.insert("bat");
    trie.insert("batman");
    trie.insert("bathtub");
    trie.insert("ball");

    std::string prefix;
    std::cout << "Введите префикс для автодополнения: ";
    std::cin >> prefix;

    std::string results[10]; // Предположим, что максимум 10 результатов
    int count = 0;

    trie.autoComplite(prefix, results, count);

    std::cout << "Результаты автодополнения:" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << results[i] << std::endl;
    }

    return 0;
}