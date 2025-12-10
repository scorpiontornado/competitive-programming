import math
from itertools import combinations


with open("input.txt") as f:
    # List of (X, Y) coordinates
    reds = [[int(coord) for coord in l.strip("\n").split(",")] for l in f.readlines()]

n = len(reds)

best = 0

for a in range(n):
    for b in range(a):  # avoid doing both ways (only connect directly once)
        width = abs(reds[a][0] - reds[b][0]) + 1
        height = abs(reds[a][1] - reds[b][1]) + 1
        area = width * height
        best = max(best, area)

print(best)
