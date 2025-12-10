import math
from itertools import combinations


# https://www.geeksforgeeks.org/dsa/introduction-to-disjoint-set-data-structure-or-union-find-algorithm/
class UnionFind:
    def __init__(self, n):
        self.Parent = list(range(n))
        self.Size = [1] * n

    # Function to find the representative (or the root
    # node) for the set that includes i
    def find(self, i):

        root = self.Parent[i]

        if self.Parent[root] != root:
            self.Parent[i] = self.find(root)
            return self.Parent[i]

        return root

    # Unites the set that includes i and the set that
    # includes j by size
    # def unionBySize(self, i, j):
    def union(self, i, j):

        # Find the representatives (or the root nodes) for
        # the set that includes i
        irep = self.find(i)

        # And do the same for the set that includes j
        jrep = self.find(j)

        # Elements are in the same set, no need to unite
        # anything.
        if irep == jrep:
            return

        # Get the size of i’s tree
        isize = self.Size[irep]

        # Get the size of j’s tree
        jsize = self.Size[jrep]

        # If i’s size is less than j’s size
        if isize < jsize:

            # Then move i under j
            self.Parent[irep] = jrep

            # Increment j's size by i's size
            self.Size[jrep] += self.Size[irep]

        # Else if j’s size is less than i’s size
        else:

            # Then move j under i
            self.Parent[jrep] = irep

            # Increment i's size by j's size
            self.Size[irep] += self.Size[jrep]

    # Added by Nick, kinda inefficient, meh...
    def all_connected(self):
        for i, parent in enumerate(self.Parent):
            if i == parent and self.Size[i] <= 1:
                return False
        return True


def euclidean_distance(a: list[int], b: list[int]) -> float:
    sq_dist = (a[0] - b[0]) ** 2 + (a[1] - b[1]) ** 2 + (a[2] - b[2]) ** 2
    return math.sqrt(sq_dist)


with open("input.txt") as f:
    # List of (X, Y, Z) coordinates
    positions = [
        [int(coord) for coord in l.strip("\n").split(",")] for l in f.readlines()
    ]

n = len(positions)

distances = []
for a in range(n):
    for b in range(a):  # avoid doing both ways (only connect directly once)
        dist = euclidean_distance(positions[a], positions[b])
        distances.append((dist, a, b))
distances.sort()

unionFind = UnionFind(n)

for _, a, b in distances:
    unionFind.union(a, b)

    # if 1 not in unionFind.Size:
    if unionFind.all_connected():
        # All are in circuit with another junction (circuit size all > 1)
        print(positions[a][0] * positions[b][0])
        break
