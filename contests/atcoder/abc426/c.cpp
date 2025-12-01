// Author: scorpiontornado
// Created: 2025-10-04 10:14pm
// Problem: https://atcoder.jp/contests/abc426/tasks/abc426_c

#pragma region template
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
#pragma endregion template

void solve() {
    int n, q;

    cin >> n >> q;

    // vi init_vers(n + 1);      // 1-indexed
    // iota(all(init_vers), 0);  // {0, 1, 2, ..., n}

    // auto versions = multiset<int>(all(init_vers));

    vi counts(n + 1, 1);  // 1-indexed, # PCs currently on version i
    int lowest = 1;

    while (q--) {
        int x, y;
        cin >> x >> y;

        // auto upper = versions.upper_bound(x);
        // int upgraded = versions.erase(versions.begin(), upper);  // [start,
        // end)
        // ^^^ doesn't return # elements removed.. could loop over values though
        // ... turns out PBDS doesn't support multisets natively...
        //
        // int upgraded = 0;
        // for (auto it = versions.begin(); it != versions.upper_bound(x);
        //      it = versions.erase(it)) {
        //     upgraded += versions.count(*it);  // kinda slow...
        // }
        //
        // versions.insert()
        // ^^^ realised would have to insert potentially many times bruh...

        // Each version # processed at most once, should be fine? (if not,
        // perhaps optimise by... all counts will be 1, apart from potentially
        // "lowest"?)
        int upgraded = 0;
        for (int v = lowest; v <= x; v++) {
            upgraded += counts[v];
            // counts[v] = 0;
        }

        lowest = max(x + 1, lowest);  // assuming x+1 has any?
        counts[y] += upgraded;
        cout << upgraded << '\n';
    }
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
