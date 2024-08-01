#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

class TrieNode {
public:
  std::unordered_map<char, TrieNode *> children;
  bool is_end;

  TrieNode() : is_end(false) {}

  ~TrieNode() {
    for (auto &pair : children) {
      delete pair.second;
    }
  }
};

class Trie {
private:
  TrieNode *root;

  TrieNode *find_node(const std::string &word) const {
    TrieNode *node = root;
    for (char ch : word) {
      if (node->children.find(ch) == node->children.end()) {
        return nullptr;
      }
      node = node->children[ch];
    }
    return node;
  }

public:
  Trie() { root = new TrieNode(); }

  ~Trie() { delete root; }

  void build(const std::vector<std::string> &words) {
    for (const std::string &word : words) {
      TrieNode *node = root;
      for (char ch : word) {
        if (node->children.find(ch) == node->children.end()) {
          node->children[ch] = new TrieNode();
        }
        node = node->children[ch];
      }
      node->is_end = true;
    }
  }

  bool exists(const std::string &word) const {
    TrieNode *node = find_node(word);
    return node != nullptr && node->is_end;
  }

  bool starts_with(const std::string &prefix) const {
    TrieNode *node = find_node(prefix);
    return node != nullptr;
  }
};


int main() {
  std::vector<std::string> words = {"dsa", "python", "data-structure", "trie", "impl"};
  Trie *trie = new Trie();

  trie->build(words);
  std::cout << std::boolalpha << trie->exists("python") << std::endl;
  std::cout << std::boolalpha << trie->exists("algorithm") << std::endl;
  std::cout << std::boolalpha << trie->starts_with("imp") << std::endl;

  return 0;
}
