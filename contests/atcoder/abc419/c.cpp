// Author: scorpiontornado
// Created: 2025-09-05 9:19pm
// Source: https://atcoder.jp/contests/abc419/tasks/abc419_c

// OBS (9:21pm): each turn, each person can move 0/1 units horizontally, and 0/1
// units vertically. Aim to go to midpoint of the extremes... no point doing
// e.g. median, cater for "weakest link" (furthest person)
// -> max(xmax - xmin, ymax - ymin)? 9:24:00pm, test on samples
// -> oops forgot /2 (both extremes can travel towards each other @ same speed)
//      .... ceil? or just +1? e.g. 5+1/2 -> 3, 6+1/2 = 3 (truncated from 3.5)

// AC @ 21:35:01, 25 min for A-C!

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
    int n;
    cin >> n;

    //! BUG - had: int rmin = 1, rmax = 1, cmin = INF, cmax = INF;
    //! BUG - had ?min = 1, ?max = INF.... should be swapped! Gave 500000000
    int rmin = INF, rmax = 1;  // r, c <= 1e9 = INF
    int cmin = INF, cmax = 1;
    rep(i, 0, n) {
        int r, c;
        cin >> r >> c;
        rmin = min(rmin, r), rmax = max(rmax, r);
        cmin = min(cmin, c), cmax = max(cmax, c);
    }

    int delta = max(rmax - rmin, cmax - cmin);
    int ans = (delta + 1) / 2;  // ceil(delta/2);
    cout << ans << '\n';
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
