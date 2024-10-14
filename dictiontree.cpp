#include "DictionaryTree.h"
#include <algorithm>
#include <iostream>

void DictionaryTree::displayWord(const std::string& word) {
    DictionaryNode* node = nullptr;
    findNode(root, word, node);
    if (node) {
        std::cout << "Word: " << node->word << ", Translation: " << node->translation << std::endl;
        ++node->accessCount;
    } else {
        std::cout << "Word not found" << std::endl;
    }
}

void DictionaryTree::addWord(const std::string& word, const std::string& translation) {
    add(DictionaryNode(word, translation));
}

void DictionaryTree::replaceWord(const std::string& word, const std::string& newTranslation) {
    DictionaryNode* node = nullptr;
    findNode(root, word, node);
    if (node) {
        node->translation = newTranslation;
    } else {
        std::cout << "Word not found" << std::endl;
    }
}

void DictionaryTree::deleteWord(const std::string& word) {
    // Реалізація видалення вузла
}

std::vector<DictionaryNode> DictionaryTree::getTopWords(int count, bool popular) const {
    std::vector<DictionaryNode> words;
    // Перетворити дерево в вектор
    if (popular) {
        std::sort(words.begin(), words.end(), [](const DictionaryNode& a, const DictionaryNode& b) {
            return a.accessCount > b.accessCount;
        });
    } else {
        std::sort(words.begin(), words.end(), [](const DictionaryNode& a, const DictionaryNode& b) {
            return a.accessCount < b.accessCount;
        });
    }
    return std::vector<DictionaryNode>(words.begin(), words.begin() + count);
}

void DictionaryTree::findNode(Node* node, const std::string& word, DictionaryNode*& result) const {
    if (node) {
        if (node->data.word == word) {
            result = &node->data;
        } else if (word < node->data.word) {
            findNode(node->left, word, result);
        } else {
            findNode(node->right, word, result);
        }
    }
}
