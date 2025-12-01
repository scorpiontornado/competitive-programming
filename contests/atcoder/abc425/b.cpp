// Author: scorpiontornado
// Created: 2025-09-207 10:22pm
// Problem: https://atcoder.jp/contests/abc425/tasks/abc425_b

// 10:51pm, submitting!! Took way too long, few rewrites...

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
    int n;
    cin >> n;

    vi a(n);

    // could/should use iota or a loop instead, or perhaps a bool array
    set<int> nums{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // vector<bool> seen(n + 1);

    // Was gonna track which nums are left to be seen or which ones have to be
    // seen or w/e... can't just check nums has leftovers, all -1 is valid but
    // nums would still be full
    //  -> wait still need to do that, to reconstruct P... "seen" now redundant?
    //     could just find in nums? meh... logic still relevant. 10:39pm

    rep(i, 0, n) {
        cin >> a[i];
        if (a[i] != -1) {
            assert(a[i] >= 1 && a[i] <= n);

            // OBS: P contains all integers in [1, N] exactly once
            // OBS: all elements of A must either be -1, or a unique integer in
            // [1, N]
            // -> if we've seen a particular non -1 element before, impossible

            // if (seen[a[i]]) {
            //     cout << "No\n";
            //     return;
            // }
            // seen[a[i]] = true;

            auto it = nums.find(a[i]);
            if (it == nums.end()) {
                cout << "No\n";
                return;
            }
            nums.erase(it);
        }
    }

    cout << "Yes\n";

    // Reconstruct a valid P so that i = 1..N, if A[i] != -1, then P[i] == A[i]
    auto nxt = nums.begin();
    rep(i, 0, n) {
        if (a[i] == -1) {
            // allocate an unused number from 1 to N (inclusive)
            assert(nxt != nums.end());
            // p[i] = *nxt;
            cout << *nxt;
            nxt++;
        } else {
            // p[i] = a[i];
            cout << a[i];
        }
        cout << " \n"[i == n - 1];
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
