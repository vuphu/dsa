def fast_power(base: int, power: int, mod: int = 10**9+7) -> int:
    if power == 0:
        return 1
    
    half = fast_power(base, power // 2, mod)
    ans = (half * half) % mod
    if power % 2 == 1:
        ans = (ans * base) % mod
    
    return ans

if __name__ == "__main__":
    print(fast_power(2, 3))
    print(fast_power(256, 1024))