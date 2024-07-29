from typing import List


def sieve(n: int) -> List[int]:
    primes = [True for _ in range(n + 1)]
    p = 2
    while p * p <= n:
        if primes[p]:
            for i in range(p * p, n + 1, p):
                primes[i] = False
        p += 1
    return [i for i in range(2, n + 1) if primes[i]]

if __name__ == "__main__":
    nums = sieve(1000)
    print(nums)