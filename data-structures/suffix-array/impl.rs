fn build_suffix_array(s: &str) -> Vec<usize> {
    let mut suffixes: Vec<(&str, usize)> = (0..s.len()).map(|i| (&s[i..], i)).collect();

    suffixes.sort_by(|a, b| a.0.cmp(b.0));

    suffixes.into_iter().map(|(_, i)| i).collect()
}

fn search_pattern(s: &str, pattern: &str) -> isize {
    let (m, n) = (pattern.len(), s.len());
    let (mut left, mut right) = (0, n as isize - 1);
    let suffix_indices = build_suffix_array(s);

    while left <= right {
        let mid = (left + right) / 2;
        let start_at = suffix_indices[mid as usize];
        let end_at = std::cmp::min(start_at + m, s.len());
        let candidate = &s[start_at..end_at];

        if candidate == pattern {
            return start_at as isize;
        } else if candidate < pattern {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    -1
}

fn main() {
    let text = "An implementation of the suffix array data structure.";
    assert_eq!(search_pattern(text, "implementation"), 3);
    assert_eq!(search_pattern(text, "prefix"), -1);
}
