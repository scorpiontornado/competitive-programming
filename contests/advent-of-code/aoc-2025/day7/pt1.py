SOURCE = "S"
BEAM = "|"
SPLITTER = "^"
EMPTY = "."

with open("input.txt") as f:
    grid = [list(l.strip("\n")) for l in f.readlines()]

n_rows, n_cols = len(grid), len(grid[0])

total = 0

for r in range(1, n_rows):
    prev_row, row = grid[r - 1], grid[r]

    for c, char in enumerate(row):
        if prev_row[c] == SOURCE or prev_row[c] == BEAM:
            if char == EMPTY:
                grid[r][c] = BEAM
            elif char == SPLITTER:
                # No instances of "^^" occur in the input
                if c > 0:
                    grid[r][c - 1] = BEAM
                if c < n_cols - 1:
                    grid[r][c + 1] = BEAM
                total += 1

print(total)
