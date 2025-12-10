import pulp

with open("input.txt") as f:
    machines = [l.strip("\n") for l in f.readlines()]

total = 0

for i, machine in enumerate(machines):
    print(f"Machine {i}", end="\r")

    tokens = machine.split()

    desired = [int(x) for x in tokens[-1][1:-1].split(",")]
    buttons = tokens[1:-1]
    sums = [[] for _ in range(len(desired))]

    # Use linear programming to minimise the number of button presses needed to
    # make the numeric counters satisfy the desired joltage requirement, where
    # a given button press increments a particular set of counters.
    # -> the variables are the number of times each button is pressed
    # -> must minimise the sum of the variables (total num. of button presses)
    # -> subject to the constraints that for each counter, the resulting
    #    joltage must sum to the desired value
    prob = pulp.LpProblem("problem", pulp.LpMinimize)
    variables = [
        pulp.LpVariable(f"x_{i}", lowBound=0, cat="Integer")
        for i in range(len(buttons))
    ]

    # Want to minimise the sum of the variables
    prob += pulp.lpSum(variables)

    for button_idx, button in enumerate(buttons):
        # Add the counters this button increments to the corresponding sums
        counters = map(int, button[1:-1].split(","))
        for counter_idx in counters:
            sums[counter_idx].append(variables[button_idx])

    for idx, s in enumerate(sums):
        # Counter "idx" must have a joltage equal to the desired value after
        # all button presses for the solution to be valid
        prob += pulp.lpSum(s) == desired[idx]

    prob.solve(pulp.PULP_CBC_CMD(msg=False))
    total += sum(var.varValue for var in variables)

print()
print(f"{total=}")
