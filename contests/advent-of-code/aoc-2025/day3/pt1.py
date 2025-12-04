import sys

def max_joltage(bank: str, cur: str) -> int:
    if len(cur) == 2:
        return int(cur)

    ret = 0
    for i, battery in enumerate(bank):
        ret = max(ret, max_joltage(bank[i+1:], cur + battery))

    return ret

ans = sum(max_joltage(bank, "") for bank in sys.stdin)
print(ans)
