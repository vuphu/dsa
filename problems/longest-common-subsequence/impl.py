from functools import cache


def lcs(s1: str, s2: str) -> int:
    m, n = len(s1), len(s2)
    dp = [[0] * (n + 1) for _ in range(m + 1)]

    for i in range(1, m + 1):
        for j in range(1, n + 1):
            if s1[i - 1] == s2[j - 1]:
                dp[i][j] = dp[i - 1][j - 1] + 1
            else:
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1])

    return dp[-1][-1]


def lcs_memorization(s1: str, s2: str) -> int:
    m, n = len(s1), len(s2)

    @cache
    def memorize(i: int, j: int) -> int:
        if i < 0 or j < 0:
            return 0
        elif s1[i] == s2[j]:
            return 1 + memorize(i - 1, j - 1)
        else:
            return max(memorize(i - 1, j), memorize(i, j - 1))

    return memorize(m - 1, n - 1)


if __name__ == "__main__":
    s1 = 'Longest common subsequence'
    s2 = 'common'

    assert lcs(s1, s2) == 6
    assert lcs_memorization(s1, s2) == 6
