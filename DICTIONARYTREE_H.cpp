#ifndef DICTIONARYTREE_H
#define DICTIONARYTREE_H

#include "DictionaryNode.h"
#include "BinaryTree.h"
#include <vector>

class DictionaryTree : public BinaryTree<DictionaryNode> {
public:
    void displayWord(const std::string& word);
    void addWord(const std::string& word, const std::string& translation);
    void replaceWord(const std::string& word, const std::string& newTranslation);
    void deleteWord(const std::string& word);
    std::vector<DictionaryNode> getTopWords(int count, bool popular) const;

private:
    void findNode(Node* node, const std::string& word, DictionaryNode*& result) const;
};

#endif // DICTIONARYTREE_H
