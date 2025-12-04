import sys

PAPER = "@"

# Up, down, left, right
# dr = (-1, 1, 0, 0)
# dc = (0, 0, -1, 1)

grid = list(map(str.strip, sys.stdin.readlines()))

total = 0
m = len(grid)

for r in range(m):
    n = len(grid[r])

    for c in range(n):
        if grid[r][c] != PAPER:
            continue

        # Count number of neighbours that're paper
        num = 0

        # for d in range(4):
        #     nr = r + dr[d]
        #     nc = c + dc[d]
        #     if nr < 0 or nr >= m or nc < 0 or nc >= n:
        #         continue
        #     num += grid[nr][nc] == PAPER

        for dr in (-1, 0, 1):  # TODO: better variable names, lol... or 16, // 4, % 4
            for dc in (-1, 0, 1):
                nr = r + dr
                nc = c + dc
                if nr < 0 or nr >= m or nc < 0 or nc >= n or (nr == r and nc == c):
                    continue

                # print(nr, nc, m, n, grid[nr])
                num += grid[nr][nc] == PAPER

        if num < 4:
            total += 1

print(total)
