// Author: scorpiontornado
// Created: 2025-09-05 10:01pm (A-D in 50 min, 270th)
// Source: https://atcoder.jp/contests/abc419/tasks/abc419_e

// OBS (10:03pm): n, m <= 500... perhaps DP? Maybe slow, but can't see flow sln?
//  - n^3 fine, n^3 log n not...
// OBS: L = N/2 is worst case? Many long subarrays... ~250, of len 250?
// too many states to have DP state be sequence (A)..?
//  - (10:08:55pm), maybe if portion already satisfied, exclude from state?
// IDEA: seems similar to ABC421G at surface level, which was min cost max flow
//  - tricky for an E? .... maybe move on, 10:11:30pm

// 10:34pm back, pondered F/G then yapped, looked @ standings/kenkoooo
// (difficulties 16, 31, 259, 251, 1298, ???, ???), ... 15:00 left, go! Samples
// -> ngl can't even figure out how to get 10 for sample 2... trying it on
//    paper, wrote down sums for each window, think might need DP or smth to
//    test how much to increment each value.... hang on!
// OBS: (10:42pm) - order doesn't matter, hence optimisation of DP...
//  - i.e., doesn't matter if +4 to i=1, then +3 to i=2 or vice versa... both
//    result in the same state, same # operations
// IDEA: DP state perhaps the # times each index has been incremented?
//  - can use that + original sequence/array to determine current state, what
//    more needs to be done...? for each index in a window not yet at threshold,
//    try incrementing & DP? base case = all done?
//  - can also ascertain # moves from that array (just sum)
//  - (5 min left, 10:45pm, unlikely to solve in this time but at least made
//    progress! (I think?))
//  - ISSUE: too many states? Can't have N-parameter DP lol (1 for ea. index),
//    would be 500 params!
//  - perhaps there's a way to take advantage of patterns, but each window
//    overlaps with other windows... complex .... 10:47pm
//  - 10:48:45pm, given up, read editorial. 1 min left on virtual participation

// 2025-09-06 ~~2:21pm~~ 2:55pm, upsolve!
//  - Uploaded problem statement, editorial, & my thoughts to chatgpt last
//    night, didn't read editorial, told it to give me hints. After ~2 hours(?),
//    managed to fully get the DP.
//  - Will now solve without looking at the chat to embed the learning! 2:58pm.
//  - 3:28pm, distracted, back! (see next "paragraph", starting with OBS etc)
//      - Fixed, had L+1 elements in each window not L, giving A_i+A{i+L+1} ≡ 0
//      - Also, should be - not + (was wondering why I got A_i ≡ -A_{i+L})
//  - 3:39pm, 4h 28m sleep last night, 4h 10m the night before rly catching up
//    to me... (7h 22 avg 31 aug - 6 sep, 6h 30 24-30 aug)...
//  - onto OBS #4, 3:41pm - music off. Basically re-solving the problem atp!
//  - 4:12pm, writing out recurrence... nah, break

// OBS: first window must be a multiple of M: A_1 + A_2 + ... + A_L ≡ 0 (mod M)
// OBS: all contiguous windows (of length L) must be multiples of M, so:
//      A_i + A_{i+1} +      ...      + A_{i+L-1}           ≡ 0    (mod M), and
//            A_{i+1} + A_{i+2} + ... + A_{i+L-1} + A_{i+L} ≡ 0    (mod M)
//      subtracting the two congruences, we get A_i - A_{i+L} ≡ 0  (mod M)
// OBS: A_i - A_{i+L} ≡ 0 (mod M) implies A_i ≡ A_{i+L} (mod M).
// OBS: after choosing the (increments/deltas for the) first window, the (deltas
//      for the) rest of the sequence is fixed - choose lowest that makes it
//      congruent to the element L before it (forming L "groups" of size N/L).
// IDEA: test all combinations of deltas for the first window (i=1..L), skip if
//      sum(A[i] + D[i]) % M != 0, then calculate deltas for rest of sequence.
//      Return the min total sum of deltas given a particular first window.
// OBS: after choosing deltas D[i] for i=1..L-1, D[L] is forced, as sum must be
//      divisible by M: (sum_{i=1..L-1}(A[i] + D[i])) + (A[L] + D[L])) mod M = 0
// OBS: D[i] is free for i = 1..L-1, can be any integer in [0, M).
// OBS: redundancy in bruteforce (overlapping subproblems - motivating DP):
//  1. to make first window sum to M, last item only needs to know the sum of
//     the previous items (actually just its "residual", sum mod M ∈ [0, M)).
//  2. second last item just needs to know the residual sum of the elements
//     before it to pass on the new residual sum to the last element
//  3. and so on, just need to know index, i, & residual sum, r, of [1, i) - no
//     need to know the exact D[1..i-1]. There may be multiple ways of reaching
//     the same residual sum using different D[1..i-1], but D[i] (and beyond)
//     can be calculated the same way in each case -> cache solutions, DP!

// 6:52pm, back, ceebs writing out the rest, see ChatGPT chat for DP explanation
// (subproblem, state, recurrence, base case, overall solution)
//  - only theoretical observation left to re-derive is how much to increment
//  - e.g. if M=4, have 1 (or 5, or 9 etc), need to increment by 3 (delta = 3)
//  - and if we have 0, 4, 8 etc, delta = 0. And for 2, 6, 10 etc, delta=2, etc
//  - i.e., given current value x, we want to find the smallest positive integer
//    d such that (x + d) mod M = 0.
//  - I remember deriving it intuitively by thinking about examples, but can do:
//      x + d ≡ 0   (mod M)
//          d ≡ -x  (mod M)
//*         d = ((-x % M) + M) % M
//  - Test...
//      - M = 4, x = 4 -> d = ((-4 % 4) + 4) % 4 = 0, yep!
//      - M = 4, x = 5 -> d = ((-5 % 4) + 4) % 4 = (-1 + 4) % 4 = 3, yep!
//          - fun fact: (-5 % 4) is -1 in C/C++, but 3 in Python (based)
//      - M = 4, x = 6, -> d = ((-6 % 4) + 4) % 4 = (-2 + 4) % 4 = 2
//  - In fact, I posit that the final % M is unnecessary, as A[i] >= 0 so
//    (-A[i] % M) will always be in the range (-M, 0]
//      - wait nvm, that means (-A[i] % M) + M will be in the range (0, M]
//        rather than [0, M), hence the last % M.
//  - 7:11pm, impl DP? Gonna be annoying, idk how ppl did this so quickly
//* - btw other thing was precomputing deltas/increments for a given residual
//    for each group, but should be fine without it as 1<=N,M<=500 and 1<=L<=N.
//  - 7:18pm dinner

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using uint = unsigned int;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pq_min = priority_queue<T, vector<T>, greater<>>;

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define repi(i, a, b) for (int i = (a); i <= (b); ++i)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define pb emplace_back

const int INF = 1e9;  // numeric_limits<int>::max();
const ll LINF = 4e18;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;

// ---

const int N = 500;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;

    vi A(N + 1);  // 1-indexed sequence

    repi(i, 1, n) { cin >> A[i]; }

    // TODO: precompute deltas?

    // TODO: dp
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int t = 1;
    // cin >> t;

    while (t--) {
        solve();
    }
}
