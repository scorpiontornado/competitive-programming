// Author: scorpiontornado
// Created: 2025-09-05 9:13pm
// Source: https://atcoder.jp/contests/abc419/tasks/abc419_b

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
    int q;
    cin >> q;

    multiset<int> balls;
    while (q--) {
        int type, x;
        cin >> type;

        if (type == 1) {
            cin >> x;
            balls.insert(x);
        } else { // 2
            // guaranteed balls isn't empty
            auto min_it = balls.begin();
            cout << *min_it << '\n';
            balls.erase(min_it);
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
