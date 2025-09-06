// Author: scorpiontornado
// Created: 2025-09-06 10:05pm... 10:09pm, start reading problem!
// Source: https://atcoder.jp/contests/arc205/tasks/arc205_a

// TIME: 10:20pm, still fully wrapping my head around the problem, bit stuck...
// current thought process is maybe DP because the same state can appear
// multiple times (prune the problem space)... or flow. Also considered union
// find for a sec but nah...
//  - for now, try flow - maximisation & saturation by turning black..? Perhaps
//    one edge per group of 4, etc? .... hard to say, cause one black saturates
//    several quads? ... 10:25pm try drawing diagrams anyway. nvm 10:29, go!
//  - 10:50pm, still stumped, move on... read B, C, then stop if still stuck
//  - (gave up at 11:20pm ish btw, no idea how to do B in 10^5... surely some
//    observation to make it linear-ish, ig need to read in input at least...)
//      - But any thoughts I've had like DP, flow, graph traversal... all
//        immediately shut down by complexity. Tried to look for patterns
//        drawing cases, black edged being drawn edges, white edges omitted...
//        couldn't rly see anything, not enough samples & not enough intuition
//        ngl... interested to see the editorial though!)
//      - Unrated participation anyway, Rated Range: 1200 - 2399, current
//        (provisional) rating: 32 lol (only rated contest was ABC416, got A-C,
//        rank 6055, performance: 588)

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

void solve() {}

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
