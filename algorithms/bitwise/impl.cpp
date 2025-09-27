#include <cassert>

bool is_even(int n) {
    return (n ^ 1) == n + 1;
}

int get_bit_length(unsigned int n) {
    if (n == 0) {
        return 0;
    }
    int bit_length = 0;
    while (n > 0) {
        n >>= 1;
        bit_length += 1;
    }
    return bit_length;
}

int count_bits(unsigned int n) {
    int bit_count = 0;
    while (n > 0) {
        n &= (n - 1);
        bit_count += 1;
    }
    return bit_count;
}

int get_right_most_set_bit(int n) {
    return n & (-n);
}

bool is_power_of_two(unsigned int n) {
    assert(n > 0);
    return (n & (n - 1)) == 0;
}

int next_power_of_two(unsigned int n) {
    assert(n > 0);
    return 1 << get_bit_length(n - 1);
}

int main() {
    assert(is_even(1) == false);
    assert(is_even(2) == true);

    assert(get_bit_length(256) == 9);
    assert(get_bit_length(255) == 8);

    assert(count_bits(512) == 1);
    assert(count_bits(511) == 9);

    assert(get_right_most_set_bit(5) == 1);
    assert(get_right_most_set_bit(256) == 256);

    assert(is_power_of_two(1024) == true);
    assert(is_power_of_two(1000) == false);

    assert(next_power_of_two(5) == 8);
    assert(next_power_of_two(256) == 256);
}
