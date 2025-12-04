ranges = input().split(",")

id_sum = 0
for r in ranges:
    start, end = map(int, r.split("-"))
    for x in range(start, end + 1):
        x_str = str(x)
        l = len(x_str)

        # TODO: find smarter way of determining sequence length
        for i in range(1, l // 2 + 1):
            if l % i == 0 and x_str[:i] * (l // i) == x_str:
                # print(x, l, i, x_str[:i])
                id_sum += x
                break

print(id_sum)
