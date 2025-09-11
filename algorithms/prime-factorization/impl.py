from math import sqrt


def factorize(num: int) -> list[int]:
    factors = []
    for i in range(2, int(sqrt(num)) + 1):
        while num % i == 0:
            factors.append(i)
            num = num // i
    return factors


def factorize_with_sieve(num: int) -> list[int]:
    # spf stands for smallest prime factors
    def build_spf(max_num: int) -> list[int]:
        spf = list(range(max_num + 1))
        for i in range(2, int(sqrt(num)) + 1):
            if spf[i] == i:
                for j in range(i * i, max_num + 1, i):
                    if spf[j] == j:
                        spf[j] = i
        return spf

    spf = build_spf(num)
    factors = []
    while num != 1:
        factors.append(spf[num])
        num = num // spf[num]

    return factors


if __name__ == "__main__":
    assert factorize(120) == [2, 2, 2, 3, 5]
    assert factorize_with_sieve(120) == [2, 2, 2, 3, 5]
