#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

std::vector<int> build_suffix_array(const std::string &s) {
    int n = s.size();
    std::vector<std::pair<std::string, int>> suffixes;

    for (int i = 0; i < n; i++) {
        suffixes.push_back(std::make_pair(s.substr(i), i));
    }

    std::sort(suffixes.begin(), suffixes.end());

    std::vector<int> suffix_array;
    for (auto &pair : suffixes) {
        suffix_array.push_back(pair.second);
    }

    return suffix_array;
}

int search_pattern(const std::string &s, const std::string &pattern) {
    int m = pattern.size(), n = s.size();
    int left = 0, right = n - 1;

    std::vector<int> suffix_indices = build_suffix_array(s);

    while (left <= right) {
        int mid = (left + right) / 2;
        int start_at = suffix_indices[mid];
        std::string candidate = s.substr(start_at, m);

        if (candidate == pattern) {
            return suffix_indices[mid];
        } else if (candidate < pattern) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1;
}

int main() {
    std::string text = "An implementation of the suffix array data structure.";
    assert(search_pattern(text, "implementation") == 3);
    assert(search_pattern(text, "prefix") == -1);
}
