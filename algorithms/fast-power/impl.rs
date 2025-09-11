const MOD: i64 = 1_000_000_007;

fn fast_power(base: i32, power: i32, modulo: i64) -> i32 {
    if power == 0 {
        return 1;
    }

    let half = fast_power(base, power / 2, modulo) as i64;
    let mut ans = (half * half) % modulo;
    if power % 2 == 1 {
        ans = (ans * (base as i64)) % modulo
    }

    ans as i32
}

fn main() {
    assert!(fast_power(2, 3, MOD) == 8);
    assert!(fast_power(256, 1024, MOD) == 112754241)
}
