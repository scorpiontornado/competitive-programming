import logging
from functools import cache
import pulp

# logging.basicConfig(level=logging.DEBUG)

OFF = "."
ON = "#"


with open("input.txt") as f:
    machines = [l.strip("\n") for l in f.readlines()]

total = 0

for i, machine in enumerate(machines):
    print(f"Machine {i}", end="\r")

    tokens = machine.split()

    desired = [int(x) for x in tokens[-1][1:-1].split(",")]
    buttons = tokens[1:-1]
    sums = [[] for _ in range(len(desired))]

    prob = pulp.LpProblem("problem", pulp.LpMinimize)
    variables = [
        pulp.LpVariable(f"x_{i}", lowBound=0, cat="Integer")
        for i in range(len(buttons))
    ]
    prob += pulp.lpSum(variables)

    for i, button in enumerate(buttons):
        for j in button[1:-1].split(","):
            sums[int(j)].append(variables[i])

    for idx, s in enumerate(sums):
        print(idx, s, desired[idx])
        prob += pulp.lpSum(s) == desired[idx]

    cur = tuple(0 for _ in range(len(desired)))

    prob.solve(pulp.PULP_CBC_CMD(msg=False))

    # total += int(pulp.value(prob.variables))
    # TODO: fix?

    print([var.varValue for var in variables])
    total += sum(var.varValue for var in variables)
    print(total)

print(total)
