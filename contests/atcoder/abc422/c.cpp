// Author: scorpiontornado
// Created: 2025-09-07 11:16pm, upsolve (full rewrite after c_fix.cpp failed)
// Source: https://atcoder.jp/contests/abc422/tasks/abc422_c

// 11:33pm, testing. Not 100% convinced, but it's worth a shot...

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
    int na, nb, nc;
    cin >> na >> nb >> nc;

    // Take as many ABC as possible
    int ans = min({na, nb, nc});
    na--, nb--, nc--;

    // Take AAC or ACC until delta == 0 (i.e. na == nc), or one of them is 0
    int delta = na - nc;

    if (delta > 0) {  // more A's
        int aac = min({delta, na / 2, nc});
        ans += aac;
        na -= aac * 2;
        nc -= aac;
    } else if (delta < 0) {  // more C's
        int acc = min({-delta, na, nc / 2});
        ans += acc;
        na -= acc;
        nc -= acc * 2;
    }

    assert(na == nc || na == 0 || nc == 0);

    // Alternate taking AAC and ACC until na == 0 or nc == 0
    if (na > 0 && nc > 0) {
        // Take complete groups of 3 (implicit floor), valid because na == nc
        ans += (na + nc) / 3;
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}
