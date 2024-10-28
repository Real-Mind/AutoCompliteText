#include "Trie.h"

int main() {
    setlocale(LC_ALL, "rus");
    Trie trie;

    // ������� ���� � Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("apricot");
    trie.insert("banana");
    trie.insert("bat");
    trie.insert("batman");
    trie.insert("bathtub");
    trie.insert("ball");

    std::string prefix;
    std::cout << "������� ������� ��� ��������������: ";
    std::cin >> prefix;

    std::string results[10]; // �����������, ��� �������� 10 �����������
    int count = 0;

    trie.autoComplite(prefix, results, count);

    std::cout << "���������� ��������������:" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << results[i] << std::endl;
    }

    return 0;
}