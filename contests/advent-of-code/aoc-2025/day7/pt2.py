SOURCE = "S"  # Changed to "1" later
BEAM = "|"
SPLITTER = "^"
EMPTY = "."  # Changed to "0" later

with open("input.txt") as f:
    grid = [
        list(l.strip("\n").replace(EMPTY, "0").replace(SOURCE, "1"))
        for l in f.readlines()
    ]

n_rows, n_cols = len(grid), len(grid[0])

for r in range(1, n_rows):
    prev_row, row = grid[r - 1], grid[r]

    for c, char in enumerate(row):
        if prev_row[c].isdigit():
            up = int(prev_row[c])

            if char == SPLITTER:
                # No instances of "^^" occur in the input
                if c > 0:
                    # Add # of timelines (ways of reaching "up") onto existing
                    left = int(grid[r][c - 1])
                    grid[r][c - 1] = str(left + up)
                if c < n_cols - 1:
                    right = int(grid[r][c + 1])
                    grid[r][c + 1] = str(right + up)
            else:
                # Same number of timelines as before
                cur = int(grid[r][c])
                grid[r][c] = str(cur + up)

total = 0
for char in grid[-1]:
    if char.isdigit():
        total += int(char)

print(total)
