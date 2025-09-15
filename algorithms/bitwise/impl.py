def is_even(n: int) -> bool:
    return n ^ 1 == n + 1


def is_power_of_two(n: int) -> bool:
    assert n > 0
    return n & (n - 1) == 0


def count_bits(n: int) -> int:
    bit_count = 0
    while n > 0:
        n &= (n - 1)
        bit_count += 1
    return bit_count


def get_right_most_set_bit(n: int) -> int:
    return n & -n


def next_power_of_two(n: int) -> int:
    assert n > 0
    return 1 << (n - 1).bit_length()


if __name__ == "__main__":
    assert is_even(1) == False
    assert is_even(2) == True

    assert is_power_of_two(1024) == True
    assert is_power_of_two(1000) == False

    assert count_bits(512) == 1
    assert count_bits(511) == 9

    assert get_right_most_set_bit(5) == 1
    assert get_right_most_set_bit(256) == 256

    assert next_power_of_two(5) == 8
    assert next_power_of_two(256) == 256
