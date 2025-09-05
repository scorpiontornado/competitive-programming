// Author: scorpiontornado
// Created: 2025-09-05 9:37pm (after 2 min reading)
// Source: https://atcoder.jp/contests/abc419/tasks/abc419_d

// IDEA: bruteforce, swap all -> ISSUE: 5e5 len, 2e5 swaps
// IDEA: bool array "swapped", only do swap at end
// IDEA: bitset, speed up flipping (XOR) -> ISSUE: length 5e5, ^ surely not O(1)
// IDEA: counting cards lec example inspired, 1 at start of range, -1 at end,
//       no need for range tree... basically prefix sum / linear sweep, then for
//       each index, swap if sum % 2 == 1
//  -> 9:46pm, quick test w sample
//  -> careful! [L, R], inclusive! -1 goes after R... (make sure array size +1)
// 9:51:00 coding
// 9:59:55 sub - AC!

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

    string s, t;
    cin >> s >> t;

    // bitset<n> swapped;
    vi swp(n + 1);  // 0-indexed, from [0, n+1]; zeroed
    rep(i, 0, m) {
        int l, r;
        cin >> l >> r;  // 1-indexed

        // increment prefix sum for [l, r]
        swp[--l] += 1;
        swp[r] -= 1;
    }

    //! BUG: forgot prefix lmao
    // rep(i, 0, n) { cout << (swp[i] % 2 == 0 ? s[i] : t[i]); }

    int sum = 0;
    rep(i, 0, n) {
        sum += swp[i];
        cout << (sum % 2 == 0 ? s[i] : t[i]);
    }
    cout << '\n';
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
