def compute_prefix(pattern: str) -> list[int]:
    m = len(pattern)
    prefix = [0] * m

    j = 0
    for i in range(1, m):
        while j > 0 and pattern[i] != pattern[j]:
            j = prefix[j - 1]
        if pattern[i] == pattern[j]:
            j += 1
        prefix[i] = j

    return prefix


def kmp_search(text: str, pattern: str) -> list[int]:
    m, n = len(pattern), len(text)
    prefix = compute_prefix(pattern)
    match_indices = []

    j = 0
    for i in range(n):
        while j > 0 and text[i] != pattern[j]:
            j = prefix[j - 1]
        if text[i] == pattern[j]:
            j += 1
        if j == m:
            match_indices.append(i - m + 1)
            j = prefix[j - 1]

    return match_indices


if __name__ == "__main__":
    text = "Using the KMP algorithm to search for text"
    pattern = "search"
    assert kmp_search(text, pattern) == [27]

    text = "AAAAA"
    pattern = "AA"
    assert kmp_search(text, pattern) == [0, 1, 2, 3]
