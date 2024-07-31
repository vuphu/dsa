#include <iostream>

int fast_power(int base, int power, int mod = 1000000007) {
    if (power == 0) {
        return 1;
    }

    int half = fast_power(base, power / 2, mod);
    int ans = (1LL * half * half) % mod;
    if (power % 2 == 1) {
        ans = (1LL * ans * base) % mod;
    }

    return ans;
}

int main() {
    std::cout << fast_power(2, 3) << std::endl;
    std::cout << fast_power(256, 1024) << std::endl;
    return 0;
}