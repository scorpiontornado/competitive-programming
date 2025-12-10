import math
from itertools import combinations
import shapely

RED = "#"
GREEN = "X"
NEITHER = "."


with open("input.txt") as f:
    # List of (X, Y), i.e. (col, row), coordinates
    reds = []

    for l in f.readlines():
        x, y = map(int, l.strip("\n").split(","))
        reds.append((x, y))

n = len(reds)
poly = shapely.Polygon(reds)
best = 0

for a in range(n):
    x1, y1 = reds[a]

    for b in range(a):
        x2, y2 = reds[b]
        rect = shapely.geometry.box(min(x1, x2), min(y1, y2), max(x1, x2), max(y1, y2))

        if rect.within(poly):
            width = abs(reds[a][0] - reds[b][0]) + 1
            height = abs(reds[a][1] - reds[b][1]) + 1
            area = width * height
            best = max(best, area)

print(best)
