fn compute_prefix(pattern: &str) -> Vec<usize> {
    let m = pattern.len();
    let mut prefix = vec![0; m];

    let mut j = 0;
    for i in 1..m {
        while j > 0 && pattern.as_bytes()[i] != pattern.as_bytes()[j] {
            j = prefix[j - 1];
        }
        if pattern.as_bytes()[i] == pattern.as_bytes()[j] {
            j += 1;
        }
        prefix[i] = j;
    }

    prefix
}

fn kmp_search(text: &str, pattern: &str) -> Vec<usize> {
    let (m, n) = (pattern.len(), text.len());
    let prefix = compute_prefix(pattern);
    let mut match_indices = vec![];

    let mut j = 0;
    for i in 0..n {
        while j > 0 && text.as_bytes()[i] != pattern.as_bytes()[j] {
            j = prefix[j - 1];
        }
        if text.as_bytes()[i] == pattern.as_bytes()[j] {
            j += 1;
        }
        if j == m {
            match_indices.push(i + 1 - m);
            j = prefix[j - 1];
        }
    }

    match_indices
}

fn main() {
    let mut text = "Using the KMP algorithm to search for text";
    let mut pattern = "search";
    assert!(kmp_search(text, pattern) == vec![27]);

    text = "AAAAA";
    pattern = "AA";
    assert!(kmp_search(text, pattern) == vec![0, 1, 2, 3]);
}
