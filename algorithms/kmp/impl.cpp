#include <iostream>
#include <vector>
#include <string>
#include <cassert>

std::vector<int> compute_prefix(const std::string &pattern) {
    int m = pattern.length();
    std::vector<int> prefix(m, 0);

    int j = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && pattern[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (pattern[i] == pattern[j]) {
            j++;
        }
        prefix[i] = j;
    }

    return prefix;
}

std::vector<int> kmp_search(const std::string &text, const std::string &pattern) {
    int m = pattern.length(), n = text.length();
    std::vector<int> prefix = compute_prefix(pattern);
    std::vector<int> match_indices;

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && text[i] != pattern[j]) {
            j = prefix[j - 1];
        }
        if (text[i] == pattern[j]) {
            j++;
        }
        if (j == m) {
            match_indices.push_back(i - m + 1);
            j = prefix[j - 1];
        }
    }

    return match_indices;
}

int main() {
    std::string text = "Using the KMP algorithm to search for text";
    std::string pattern = "search";
    assert(kmp_search(text, pattern) == std::vector<int>{27});

    text = "AAAAA";
    pattern = "AA";
    assert(kmp_search(text, pattern) == (std::vector<int>{0, 1, 2, 3}));

    return 0;
}
