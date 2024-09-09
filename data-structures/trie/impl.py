import collections
from typing import List, Optional


class TrieNode:
    def __init__(self):
        self.children = collections.defaultdict(TrieNode)
        self.is_end = False


# noinspection PyShadowingNames
class Trie:
    def __init__(self):
        self.root = TrieNode()

    def build(self, words: List[str]) -> None:
        for word in words:
            node = self.root
            for char in word:
                if char not in node.children:
                    node.children[char] = TrieNode()
                node = node.children[char]
            node.is_end = True

    def __find_node(self, word: str) -> Optional[TrieNode]:
        node = self.root
        for char in word:
            if char not in node.children:
                return None
            node = node.children[char]
        return node

    def exists(self, word: str) -> bool:
        node = self.__find_node(word)
        return node is not None and node.is_end

    def starts_with(self, prefix: str) -> bool:
        node = self.__find_node(prefix)
        return node is not None


if __name__ == "__main__":
    words = ["dsa", "python", "data-structure", "trie", "impl"]

    trie = Trie()
    trie.build(words)

    assert trie.exists("python") == True
    assert trie.exists("algorithm") == False
    assert trie.starts_with("imp") == True
