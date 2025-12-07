import sys

# from rangetree import RangeTree
from intervaltree import Interval, IntervalTree

# r = RangeTree()
interval_tree = IntervalTree()

# Range updates
for line in sys.stdin:
    if line == "\n":
        break

    begin, end = map(int, line.strip().split("-"))
    print(begin, end + 1)

    # r[begin : end + 1] = True
    # ^^^ Couldn't handle overlapping ranges :(

    interval_tree.add(Interval(begin, end + 1))

total = 0

# Point queries
for line in sys.stdin:
    if line == "\n":
        break

    id = int(line.strip())

    # if id in r:
    if interval_tree[id]:
        total += 1

print(total)
