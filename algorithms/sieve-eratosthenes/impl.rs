fn sieve(n: i32) -> Vec<i32> {
    let mut primes = vec![true; (n as usize) + 1];
    let mut p = 2;

    while p * p <= n {
        if primes[p as usize] {
            for i in ((p * p)..=n).step_by(p as usize) {
                primes[i as usize] = false;
            }
        }
        p += 1;
    }

    (2..=n).filter(|&i| primes[i as usize]).collect()
}

fn main() {
    let primes = sieve(1000);
    assert!(primes.len() == 168)
}
