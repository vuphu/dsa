#include <iostream>
#include <vector>
#include <string>
#include <cassert>

// Ref: https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/

std::vector<int> compute_z_array(const std::string& s) {
    int length = s.length();
    std::vector<int> z_array(length, 0);
    int left = 0, right = 0;

    for (int i = 1; i < length; ++i) {
        if (i > right) {
            left = right = i;
            while (right < length && s[right] == s[right - left]) {
                ++right;
            }
            z_array[i] = right - left;
            --right;
        } else {
            int match_length = i - left;
            if (z_array[match_length] < right - i + 1) {
                z_array[i] = z_array[match_length];
            } else {
                left = i;
                while (right < length && s[right] == s[right - left]) {
                    ++right;
                }
                z_array[i] = right - left;
                --right;
            }
        }
    }

    return z_array;
}

std::vector<int> z_algorithm_search(const std::string& text, const std::string& pattern) {
    std::string concatenated = pattern + '#' + text;
    std::vector<int> z_array = compute_z_array(concatenated);
    int pattern_length = pattern.length();

    std::vector<int> match_indices;
    for (int i = pattern_length + 1; i < concatenated.length(); ++i) {
        if (z_array[i] == pattern_length) {
            match_indices.push_back(i - pattern_length - 1);
        }
    }

    return match_indices;
}

int main() {
    std::string text = "Using the KMP algorithm to search for text";
    std::string pattern = "search";
    assert(z_algorithm_search(text, pattern) == std::vector<int>{27});

    text = "AAAAA";
    pattern = "AA";
    assert(z_algorithm_search(text, pattern) == (std::vector<int>{0, 1, 2, 3}));

    return 0;
}
