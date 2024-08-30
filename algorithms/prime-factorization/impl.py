from math import sqrt
from typing import List


def factorize(num: int) -> List[int]:
    factors = []
    for i in range(2, int(sqrt(num)) + 1):
        while num % i == 0:
            factors.append(i)
            num = num // i
    return factors


def factorize_with_sieve(num: int) -> List[int]:
    # spf stands for smallest prime factors
    def build_spf(max_num = 10**5) -> List[int]:
        spf = list(range(max_num + 1))
        for i in range(2, int(max_num**0.5) + 1):
            if spf[i] == i:
                for j in range(i * i, max_num + 1, i):
                    if spf[j] == j:
                        spf[j] = i
        return spf
    
    spf = build_spf()
    factors = []
    while num != 1:
        factors.append(spf[num])
        num = num // spf[num]
    
    return factors
        

if __name__ == "__main__":
    print(factorize(120))
    print(factorize_with_sieve(120))
