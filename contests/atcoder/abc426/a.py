#! /usr/bin/env python3

# Author: scorpiontornado
# Created: 2025-10-04 10:00pm
# Problem: https://atcoder.jp/contests/abc426/tasks/abc426_a

versions = ["Ocelot", "Serval", "Lynx"]

x, y = input().split()

x_ind, y_ind = versions.index(x), versions.index(y)  # assumes x & y are in versions

print("Yes" if x_ind >= y_ind else "No")
