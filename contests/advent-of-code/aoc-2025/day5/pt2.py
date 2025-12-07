import sys

from intervaltree import Interval, IntervalTree

interval_tree = IntervalTree()

# Range updates
for line in sys.stdin:
    if line == "\n":
        break

    begin, end = map(int, line.strip().split("-"))
    # print(begin, end + 1)

    interval_tree.add(Interval(begin, end + 1))


interval_tree.merge_overlaps()

# Would ideally do this with a range tree & range query (e.g. range update all
# element in ranges to 1, then query the sum of the entire tree), but I
# couldn't be bothered writing one from scratch & the python rangetree library
# doesn't support overlapping ranges :(
total = 0
for iv in interval_tree:
    total += iv.end - iv.begin

print(total)
