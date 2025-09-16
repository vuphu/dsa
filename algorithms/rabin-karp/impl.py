MOD = 10 ** 9 + 7


def rabin_karp(text: str, pattern: str, base: int = 256) -> int:
    text_length, pattern_length = len(text), len(pattern)

    if pattern_length > text_length:
        return -1

    high_base = pow(base, pattern_length - 1, MOD)
    text_hash, pattern_hash = 0, 0

    for i in range(pattern_length):
        text_hash = (text_hash * base + ord(text[i])) % MOD
        pattern_hash = (pattern_hash * base + ord(pattern[i])) % MOD

    for i in range(text_length - pattern_length + 1):
        if pattern_hash == text_hash and text[i: i + pattern_length] == pattern:
            return i
        if i < text_length - pattern_length:
            text_hash = (text_hash - ord(text[i]) * high_base) % MOD
            text_hash = (text_hash * base + ord(text[i + pattern_length])) % MOD
            text_hash = (text_hash + MOD) % MOD

    return -1

if __name__ == "__main__":
    text = 'abcdefghijklmnopqrstuvwxyz'

    assert rabin_karp(text, 'xyz') == 23
    assert rabin_karp(text, 'yza') == -1
