bit = [0] * n

def bit_range(p, down=True):
    while p >= 0 and p < len(bit):
        yield p
        p = (p & (p + 1)) - 1 if down else p | (p + 1)        

def get_max(p: int) -> int:
    return max(bit[i] for i in bit_range(p))

def update(p, val):
    for idx in bit_range(p, False):
        bit[idx] = max(bit[idx], val);