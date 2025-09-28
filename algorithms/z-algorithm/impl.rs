// Ref: https://www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/

fn compute_z_array(s: &str) -> Vec<usize> {
    let length = s.len();
    let mut z_array = vec![0; length];
    let (mut left, mut right) = (0, 0);

    for i in 1..length {
        if i > right {
            left = i;
            right = i;
            while right < length && s.as_bytes()[right] == s.as_bytes()[right - left] {
                right += 1;
            }
            z_array[i] = right - left;
            right -= 1;
        } else {
            let match_length = i - left;
            if z_array[match_length] < right - i + 1 {
                z_array[i] = z_array[match_length];
            } else {
                left = i;
                while right < length && s.as_bytes()[right] == s.as_bytes()[right - left] {
                    right += 1;
                }
                z_array[i] = right - left;
                right -= 1;
            }
        }
    }

    z_array
}

fn z_algorithm_search(text: &str, pattern: &str) -> Vec<usize> {
    let concatenated = format!("{}#{}", pattern, text);
    let z_array = compute_z_array(&concatenated);
    let pattern_length = pattern.len();
    let mut match_indices = vec![];

    for i in (pattern_length + 1)..concatenated.len() {
        if z_array[i] == pattern_length {
            match_indices.push(i - pattern.len() - 1);
        }
    }

    match_indices
}

fn main() {
    let mut text = "Using the Z algorithm to search for text";
    let mut pattern = "search";
    assert!(z_algorithm_search(text, pattern) == vec![25]);

    text = "AAAAA";
    pattern = "AA";
    assert!(z_algorithm_search(text, pattern) == vec![0, 1, 2, 3]);
}
