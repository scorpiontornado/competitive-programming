#! /usr/bin/env python3

# Author: scorpiontornado
# Created: 2025-10-04 10:07pm
# Problem: https://atcoder.jp/contests/abc426/tasks/abc426_b

from collections import Counter

s = input()

counts = Counter(s)

print(counts.most_common()[-1][0])
