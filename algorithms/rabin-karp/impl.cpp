#include <string>
#include <cassert>

const int mod = 1000000007;
const int base = 256;

int rabin_karp(std::string text, std::string pattern) {
    int text_length = text.size();
    int pattern_length = pattern.size();

    if (pattern_length > text_length) {
        return -1;
    }

    int64_t high_base = 1;
    for (int i = 0; i < pattern_length - 1; i++) {
        high_base = (high_base * base) % mod;
    }

    int64_t text_hash = 0, pattern_hash = 0;
    for (int i = 0; i < pattern_length; i++) {
        text_hash = (text_hash * base + text[i]) % mod;
        pattern_hash = (pattern_hash * base + pattern[i]) % mod;
    }

    for (int i = 0; i <= text_length - pattern_length; i++) {
        if (pattern_hash == text_hash && text.substr(i, pattern_length) == pattern) {
            return i;
        }
        if (i < text_length - pattern_length) {
            text_hash = (text_hash - text[i] * high_base) % mod;
            text_hash = (text_hash * base + text[i + pattern_length]) % mod;
            text_hash = (text_hash + mod) % mod;
        }
    }

    return -1;
}

int main() {
    std::string text = "abcdefghijklmnopqrstuvwxyz";

    assert(rabin_karp(text, "xyz") == 23);
    assert(rabin_karp(text, "yxz") == -1);

    return 0;
}