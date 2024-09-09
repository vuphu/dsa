#include <iostream>
#include <string>
#include <vector>
#include <cassert>

int lcs(std::string s1, std::string s2) {
    int m = s1.size(), n = s2.size();
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1));

    for (int i = 1; i < m + 1; i++) {
        for (int j = 1; j < n + 1; j++) {
            if (s1[i - 1] == s2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::string s1 = "Longest common subsequence";
    std::string s2 = "common";

    assert(lcs(s1, s2) == 6);

    return 0;
}