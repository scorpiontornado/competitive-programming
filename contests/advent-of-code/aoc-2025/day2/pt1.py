ranges = input().split(",")

id_sum = 0
for r in ranges:
    start, end = map(int, r.split("-"))
    for x in range(start, end+1):
        # TODO: try with log10 for length & "left shifting" by dividing
        # by 10**(length/2) to get top half, & compare numerically w bottom
        x_str = str(x)
        l = len(x_str)

        if x_str[:l//2] == x_str[l//2:]:
            id_sum += x

print(id_sum)
