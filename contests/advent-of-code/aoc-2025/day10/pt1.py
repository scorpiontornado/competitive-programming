import math
import logging
from functools import cache

# logging.basicConfig(level=logging.DEBUG)

OFF = "."
ON = "#"


# Memoise function calls with cache to avoid repeated calculation (DP)
# (tuples are used rather than lists because they're hashable)
@cache
def min_presses(cur: int, desired: int, buttons: tuple[int, ...]) -> int | float:
    """Given a bitmask 'cur' representing the current state of lights
    (0 for off, 1 for on), a bitmask representing the desired state, and
    a list of bitmasks of buttons (which lights to toggle), represents
    the minimum number of button presses to reach 'desired'.
    """
    if cur == desired:
        return 0

    best = math.inf
    for i, mask in enumerate(buttons):
        # Never press same button twice, remove to avoid exceeding recursion
        # depth (state is small enough that it's fine, computation-wise)
        new_buttons = buttons[:i] + buttons[i + 1 :]
        n_presses = min_presses(cur ^ mask, desired, new_buttons) + 1
        best = min(best, n_presses)

    return best


with open("input.txt") as f:
    machines = [l.strip("\n") for l in f.readlines()]

total = 0

for machine in machines:
    tokens = machine.split()

    # Construct bitmask of desired state, e.g. ".#.#" -> 0b1010
    desired = 0
    for i, light in enumerate(tokens[0][1:-1]):
        if light == ON:
            desired |= 1 << i
    logging.debug(bin(desired))

    buttons = []
    for button in tokens[1:-1]:
        bitmask = 0
        light_idxs = map(int, button[1:-1].split(","))

        for idx in light_idxs:
            bitmask |= 1 << idx

        buttons.append(bitmask)

    logging.debug([bin(b) for b in buttons])

    n_presses = min_presses(0, desired, tuple(buttons))
    total += n_presses

print(total)
