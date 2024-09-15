from typing import List


def build_suffix_array(s: str) -> List[int]:
    n = len(s)
    suffixes = [(s[i:], i) for i in range(n)]
    suffixes.sort()
    suffix_array = [suffix[1] for suffix in suffixes]
    return suffix_array


def search_pattern(s: str, pattern: str) -> int:
    m, n = len(pattern), len(s)
    left, right = 0, n - 1
    suffix_indices = build_suffix_array(s)

    while left <= right:
        mid = (left + right) // 2
        start_at = suffix_indices[mid]
        candidate = s[start_at:start_at + m]
        if candidate == pattern:
            return suffix_indices[mid]
        elif candidate < pattern:
            left = mid + 1
        else:
            right = mid - 1

    return -1


if __name__ == "__main__":
    text = 'An implementation of the suffix array data structure.'
    assert search_pattern(text, 'implementation') == 3
    assert search_pattern(text, 'prefix') == -1
