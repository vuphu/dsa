mod = 10 ** 9 + 7
base = 256


def rabin_karp(text: str, pattern: str) -> int:
    text_length, pattern_length = len(text), len(pattern)

    if pattern_length > text_length:
        return -1

    high_base = pow(base, pattern_length - 1, mod)
    text_hash, pattern_hash = 0, 0

    for i in range(pattern_length):
        text_hash = (text_hash * base + ord(text[i])) % mod
        pattern_hash = (pattern_hash * base + ord(pattern[i])) % mod

    for i in range(text_length - pattern_length + 1):
        if pattern_hash == text_hash and text[i: i + pattern_length] == pattern:
            return i
        if i < text_length - pattern_length:
            text_hash = (text_hash - ord(text[i]) * high_base) % mod
            text_hash = (text_hash * base + ord(text[i + pattern_length])) % mod
            text_hash = (text_hash + mod) % mod

    return -1


if __name__ == "__main__":
    text = 'abcdefghijklmnopqrstuvwxyz'

    assert rabin_karp(text, 'xyz') == 23
    assert rabin_karp(text, 'yza') == -1
