#ifndef DICTIONARYNODE_H
#define DICTIONARYNODE_H

#include <string>

struct DictionaryNode {
    std::string word;
    std::string translation;
    int accessCount;

    DictionaryNode(const std::string& w, const std::string& t)
        : word(w), translation(t), accessCount(0) {}
};

#endif // DICTIONARYNODE_H
