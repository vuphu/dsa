fn factorize(mut num: i32) -> Vec<i32> {
    let mut factors = vec![];

    for i in 2..=(num as f64).sqrt() as i32 {
        while num % i == 0 {
            factors.push(i);
            num = num / i;
        }
    }

    if num > 1 {
        factors.push(num);
    }

    factors
}

fn factorize_with_sieve(mut num: i32) -> Vec<i32> {
    // spf stands for smallest prime factors
    fn build_spf(max_num: i32) -> Vec<i32> {
        let mut spf = (0..=max_num).collect::<Vec<_>>();
        for i in 2..=(max_num as f64).sqrt() as usize {
            if spf[i] == i as i32 {
                for j in ((i * i)..=max_num as usize).step_by(i) {
                    if spf[j] == j as i32 {
                        spf[j] = i as i32
                    }
                }
            }
        }
        spf
    }

    let spf = build_spf(num);
    let mut factors = vec![];
    while num != 1 {
        factors.push(spf[num as usize]);
        num = num / spf[num as usize];
    }

    factors
}

fn main() {
    assert!(factorize(120) == vec![2, 2, 2, 3, 5]);
    assert!(factorize_with_sieve(120) == vec![2, 2, 2, 3, 5]);

    assert!(factorize(5) == vec![5]);
    assert!(factorize_with_sieve(5) == vec![5]);
}
