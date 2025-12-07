import numpy as np

with open("input.txt") as f:
    nums: list[list[int]] = []
    operations: list[str] = []

    for line in f:
        row = line.strip().split()
        try:
            nums.append(list(map(int, row)))
        except ValueError:
            operations = line.strip().split()

arr = np.array(nums)

grand_total = 0

# Could vectorise: np array of operations, boolean column selection,
# sum / product, then sum each & add together. But, already fast enough.
for i, op in enumerate(operations):
    if op == "+":
        grand_total += arr[:, i].sum()
    else:
        grand_total += arr[:, i].prod()

print(grand_total)
