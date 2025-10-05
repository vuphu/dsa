use std::cmp::max;
use std::collections::HashMap;

fn lcs(s1: &str, s2: &str) -> usize {
    let (m, n) = (s1.len(), s2.len());
    let mut dp = vec![vec![0; n + 1]; m + 1];

    for i in 1..=m {
        for j in 1..=n {
            if s1.as_bytes()[i - 1] == s2.as_bytes()[j - 1] {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

fn lcs_memorization(s1: &str, s2: &str) -> usize {
    let (m, n) = (s1.len(), s2.len());

    fn memorize(
        i: isize,
        j: isize,
        s1: &str,
        s2: &str,
        cache: &mut HashMap<(isize, isize), usize>,
    ) -> usize {
        if i < 0 || j < 0 {
            return 0;
        } else if cache.contains_key(&(i, j)) {
            return *cache.get(&(i, j)).unwrap();
        } else if s1.as_bytes()[i as usize] == s2.as_bytes()[j as usize] {
            return 1 + memorize(i - 1, j - 1, s1, s2, cache);
        } else {
            return max(
                memorize(i - 1, j, s1, s2, cache),
                memorize(i, j - 1, s1, s2, cache),
            );
        }
    }

    return memorize(m as isize - 1, n as isize - 1, s1, s2, &mut HashMap::new());
}

fn main() {
    let s1 = "Longest common subsequence";
    let s2 = "common";

    assert!(lcs(&s1, &s2) == 6);
    assert!(lcs_memorization(&s1, &s2) == 6);
}
