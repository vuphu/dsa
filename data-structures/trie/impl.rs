use std::collections::HashMap;

struct TrieNode {
    pub children: HashMap<char, TrieNode>,
    pub is_end: bool,
}

impl TrieNode {
    pub fn new() -> Self {
        Self {
            children: HashMap::new(),
            is_end: false,
        }
    }

    pub fn next(&mut self, c: char) -> &mut TrieNode {
        self.children.entry(c).or_insert(TrieNode::new())
    }
}

struct Trie {
    root: TrieNode,
}

impl Trie {
    pub fn new() -> Self {
        Self {
            root: TrieNode::new(),
        }
    }

    pub fn build(&mut self, words: Vec<String>) {
        for word in words.iter() {
            let mut node = &mut self.root;
            for c in word.chars() {
                node = node.next(c);
            }
            node.is_end = true;
        }
    }

    pub fn exists(&self, word: String) -> bool {
        match self.find_node(word) {
            Some(node) => node.is_end,
            None => false,
        }
    }

    pub fn starts_with(&self, prefix: String) -> bool {
        self.find_node(prefix).is_some()
    }

    fn find_node(&self, word: String) -> Option<&TrieNode> {
        let mut node = &self.root;
        for c in word.chars() {
            node = node.children.get(&c)?;
        }
        Some(node)
    }
}

fn main() {
    let words: Vec<String> = vec!["dsa", "python", "data-structure", "trie", "impl"]
        .iter()
        .map(|s| s.to_string())
        .collect();

    let mut trie = Trie::new();
    trie.build(words);

    assert!(trie.exists("python".to_string()));
    assert!(!trie.exists("algorithm".to_string()));
    assert!(trie.starts_with("imp".to_string()));
}
