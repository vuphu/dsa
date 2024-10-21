from typing import List

# Ref: https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/

def compute_z_array(s: str):
    length = len(s)
    z_array = [0] * length
    left, right = 0, 0

    for i in range(1, length):
        if i > right:
            left, right = i, i
            while right < length and s[right] == s[right - left]:
                right += 1
            z_array[i] = right - left
            right -= 1
        else:
            match_length = i - left
            if z_array[match_length] < right - i + 1:
                z_array[i] = z_array[match_length]
            else:
                left = i
                while right < length and s[right] == s[right - left]:
                    right += 1
                z_array[i] = right - left
                right -= 1

    return z_array


def z_algorithm_search(text: str, pattern: str) -> List[int]:
    concatenated = pattern + '#' + text
    z_array = compute_z_array(concatenated)
    pattern_length = len(pattern)

    match_indices = []
    for i in range(len(pattern) + 1, len(concatenated)):
        if z_array[i] == pattern_length:
            match_indices.append(i - len(pattern) - 1)

    return match_indices


if __name__ == "__main__":
    text = "Using the KMP algorithm to search for text"
    pattern = "search"
    assert z_algorithm_search(text, pattern) == [27]

    text = "AAAAA"
    pattern = "AA"
    assert z_algorithm_search(text, pattern) == [0, 1, 2, 3]
