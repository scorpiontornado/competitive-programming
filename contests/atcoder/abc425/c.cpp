// Author: scorpiontornado
// Created: 2025-09-207 10:53pm
// Problem: https://atcoder.jp/contests/abc425/tasks/abc425_c

// A:       1, 2, 3, 4, 5
// rot 2:         3, 4, 5, 1, 2
// query sum from index 3 to 5, i.e. sum({5, 1, 2})
//      = sum(A[5] to A[5] inclusive) + sum(A[1] to A[2] inclusive)
// perhaps cause sum(A[3 + 2] to A[5 + 2]), and anything above 5 wraps around

// 11:02:40pm try impl?
// 11:24pm submitting!!
//  -> fml, WA x18, passed 2 seen, 2 unseen....
// 11:27pm, changed pre & ans to ll, resubmit!! 12 min remaining

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

    // Both 1-indexed
    vi a(n + 1);
    vll pre(n + 1);
    repi(i, 1, n) {
        cin >> a[i];
        pre[i] = a[i] + pre[i - 1];
    }

    int rot = 0;
    repi(i, 1, q) {
        int qtype;
        cin >> qtype;

        if (qtype == 1) {
            int c;
            cin >> c;
            rot = (rot + c) % n;
        } else {
            int l, r;  // inclusive range of rotated array to sum
            cin >> l >> r;
            l += rot, r += rot;  //! had l twice, not r lol

            // (could use % if was 0-indexed or manually -1, +1)
            if (l > n) l -= n;
            if (r > n) r -= n;

            ll ans;
            if (l > r) {
                // split sum into two: A[l..n], and A[1..r]
                ans = (pre[n] - pre[l - 1]) + pre[r];
                // cerr << l << ' ' << r << ' ' << pre[l - 1] << ' ' << pre[r]
                // << '\n'; //! dbg
            } else {
                // just use sum(A[l..r])
                ans = pre[r] - pre[l - 1];
                // cerr << l << ' ' << r << ' ' << pre[l - 1] << ' ' << pre[r]
                // << '\n'; //! dbg
            }
            cout << ans << '\n';
        }
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
