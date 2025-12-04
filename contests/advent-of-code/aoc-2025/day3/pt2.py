import sys
from functools import cache
from itertools import combinations

### Attempt 1 ###
# @cache
# def max_joltage(bank: str, cur: str) -> int:
#     if len(cur) == 12:
#         return int(cur)

#     ret = 0
#     for i, battery in enumerate(bank):
#         ret = max(ret, max_joltage(bank[i + 1 :], cur + battery))

#     return ret

# ans = sum(max_joltage(bank, "") for bank in sys.stdin)
# print(ans)


### Attempt 2 ###
# ans = 0
# for bank in sys.stdin:
#     best = 0
#     combs = set(combinations(bank, 12))
#     print(len(combs))

#     for comb in combs:
#         best = max(best, int("".join(comb)))
#     ans += best

# print(ans)


### Attempt 3
ans = 0
for bank in sys.stdin:
    best = bank[:12]
    best_joltage = int(best)

    for battery in bank[12:]:
        # print(f"{battery = }"

        # Try to remove a battery to make room for this new one
        for i in range(12):
            new = best[:i] + best[i + 1 :] + battery
            new_joltage = int(new)
            # print(f"\t{new_joltage}")

            if new_joltage > best_joltage:
                best_joltage = new_joltage
                # print(f"\t{best_joltage = }")

        best = str(best_joltage)  # must keep it until exiting the loop

    ans += best_joltage

print(ans)
