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

void solve() {
    int n, m;
    cin >> n >> m;
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
