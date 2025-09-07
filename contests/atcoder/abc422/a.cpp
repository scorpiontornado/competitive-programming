// Author: scorpiontornado
// Created: 2025-09-07 2:12pm (2:10 started contest), AC 2:25pm (throwing)
// Source: https://atcoder.jp/contests/abc422/tasks/abc422_a

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
    int i, j;
    cin >> i >> j;  // world-stage
    j *= -1;        // XXX: hacky workaround to ignore separating hyphen

    // int comb = i * 8 + j;
    // cerr << i << ' ' << j << ' ' << comb << endl; //! dbg
    // // int nxt = comb + 1;
    // cout << (nxt / 8) << '-' << (nxt % 8 ? nxt % 8 : 8) << '\n';
    // // XXX: hacky workaround to make 8 not be 0
    // //  -> prob would've been faster to just use if statements, meh

    //! BUG: don't want stage 7 -> (world+1)-0

    // 2:21pm abandon, to if statement.. KISS
    int nxt_world = i, nxt_stage = j;
    if (j < 8) {
        nxt_stage++;
    } else if (j == 8) {
        nxt_world++;
        nxt_stage = 1;
    }
    // i = 8, j = 8 won't occur

    cout << nxt_world << '-' << nxt_stage << '\n';
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
