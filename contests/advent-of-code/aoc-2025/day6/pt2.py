from math import prod

with open("input.txt") as f:
    lines = [l.strip("\n") for l in f.readlines()]

n_rows, n_cols = len(lines), len(lines[0])
n_digits = n_rows - 1

grand_total = 0
nums: list[int] = []

col = n_cols - 1
while col >= 0:
    # Turns out rows don't directly correspond to positions (1's, 10's etc),
    # e.g. "1  " (1 in the top row and nothing else) is the same as "  1"
    num = ""
    for row in range(n_rows - 1):
        if lines[row][col].isdigit():
            num += lines[row][col]
    nums.append(int(num) if num else 0)

    operation = lines[-1][col]
    if operation != " ":
        # print(operation, nums, grand_total)
        if operation == "+":
            grand_total += sum(nums)
        elif operation == "*":
            grand_total += prod(nums)
        # print(f"After: {grand_total}")

        nums = []
        col -= 1  # skip empty column

    col -= 1

print(grand_total)


# === Graveyard ===
# Treats "1  " (1 in top row & nothing else) as 100, not 1...
#     num = 0
#     for row in range(n_rows - 1):
#         char = lines[row][col]
#         digit = 0 if char == " " else int(char)
#         position = n_digits - row - 1  # last row -> 0, 2nd last -> 1...

#         # (or, could've appended to a string - marginally slower)
#         num += digit * (10**position)

#     nums.append(num)
