import sys, copy

PAPER = "@"
BLANK = "."


def remove_paper(grid: list[list[str]]) -> tuple[int, list[list[str]]]:
    grid_new = copy.deepcopy(grid)

    m = len(grid)
    total = 0

    for r in range(m):
        n = len(grid[r])

        for c in range(n):
            if grid[r][c] == BLANK:
                continue

            # Count number of neighbours that're paper
            num = 0

            for dr in (-1, 0, 1):
                for dc in (-1, 0, 1):
                    nr = r + dr
                    nc = c + dc
                    if nr < 0 or nr >= m or nc < 0 or nc >= n or (nr == r and nc == c):
                        continue
                    num += grid[nr][nc] == PAPER

            if num < 4:
                total += 1
                grid_new[r][c] = BLANK

    return total, grid_new


# TODO: clean up this monstrosity... needed mutable 2D array of chars
grid = list(map(list, map(str.strip, sys.stdin.readlines())))
total = 0

while True:
    num_removed, grid = remove_paper(grid)
    if num_removed == 0:
        break
    total += num_removed

print(total)
