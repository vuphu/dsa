#include <vector>
#include <cassert>

std::vector<int> factorize(int num) {
    std::vector<int> factors;
    for (int i = 2; i * i <= num; i++) {
        while (num % i == 0) {
            factors.push_back(i);
            num = num / i;
        }
    }
    if (num > 1) {
        factors.push_back(num);
    }
    return factors;
}

std::vector<int> factorize_with_sieve(int num) {
    // spf stands for smallest prime factors
    auto build_spf = [](int max_num) -> std::vector<int> {
        std::vector<int> spf(max_num + 1);
        for (int i = 0; i <= max_num; i++) {
            spf[i] = i;
        }
        for (int i = 2; i * i <= max_num; i++) {
            if (spf[i] == i) {
                for (int j = i * i; j <= max_num; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
        return spf;
    };

    std::vector<int> spf = build_spf(num);
    std::vector<int> factors;

    while (num != 1) {
        factors.push_back(spf[num]);
        num = num / spf[num];
    }

    return factors;
}

int main() {
    assert(factorize(120) == (std::vector<int>{2, 2, 2, 3, 5}));
    assert(factorize_with_sieve(120) == (std::vector<int>{2, 2, 2, 3, 5}));

    assert(factorize(5) == (std::vector<int>{5}));
    assert(factorize_with_sieve(5) == (std::vector<int>{5}));

    return 0;
}