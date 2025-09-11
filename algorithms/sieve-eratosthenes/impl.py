def sieve(n: int) -> list[int]:
    primes = [True] * (n + 1)
    p = 2
    while p * p <= n:
        if primes[p]:
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1
    return [i for i in range(2, n + 1) if primes[i]]


if __name__ == "__main__":
    primes = sieve(1000)

    assert len(primes) == 168
