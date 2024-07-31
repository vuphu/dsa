#include <iostream>
#include <vector>

std::vector<int> sieve(int n) {
    std::vector<bool> primes(n + 1, true);
    int p = 2;
    while (p * p <= n) {
        if (primes[p]) {
            for (int i = p * p; i <= n; i += p) {
                primes[i] = false;
            }
        }
        p += 1;
    }
    
    std::vector<int> prime_numbers;
    for (int i = 2; i <= n; ++i) {
        if (primes[i]) {
            prime_numbers.push_back(i);
        }
    }
    
    return prime_numbers;
}

int main() {
    std::vector<int> nums = sieve(1000);
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}