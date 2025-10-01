const BASE: i64 = 256;
const MOD: i64 = 1_000_000_007;

fn rabin_karp(text: &str, pattern: &str) -> isize {
    let (text_length, pattern_length) = (text.len(), pattern.len());

    if pattern_length > text_length {
        return -1;
    }

    let mut high_base: i64 = 1;
    for _ in 0..(pattern_length - 1) {
        high_base = (high_base * BASE) % MOD;
    }

    let (mut text_hash, mut pattern_hash) = (0, 0);
    for i in 0..pattern_length {
        text_hash = (text_hash * BASE + text.as_bytes()[i] as i64) % MOD;
        pattern_hash = (pattern_hash * BASE + pattern.as_bytes()[i] as i64) % MOD;
    }

    for i in 0..=(text_length - pattern_length) {
        if text_hash == pattern_hash && &text[i..i + pattern_length] == pattern {
            return i as isize;
        }
        if i < text_length - pattern_length {
            text_hash = (text_hash - (text.as_bytes()[i] as i64 * high_base) % MOD) % MOD;
            text_hash = (text_hash * BASE + text.as_bytes()[i + pattern_length] as i64) % MOD;
            text_hash = (text_hash + MOD) % MOD;
        }
    }

    -1
}

fn main() {
    let text = "abcdefghijklmnopqrstuvwxyz";

    assert!(rabin_karp(text, "xyz") == 23);
    assert!(rabin_karp(text, "yxz") == -1);
}
