#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
// uint, ull
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
// pq, pq_min

#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define repi(i, a, b) for (int i = (a); i <= (b); ++i)
#define all(x) (x).begin(), (x).end()
// rall
#define sz(x) ((int)(x).size())
// pb

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<pll> mass(n + 1);  // 1-indexed
    repi(i, 1, n) {
        int m;
        cin >> m;
        mass[i] = pll(m, i);
    }

    sort(all(mass));

    vll pre(n + 1);  // prefix sum
    repi(i, 1, n) { pre[i] = mass[i].first + pre[i - 1]; }

    vector<bool> can_win(n + 1);  // original indices (before sort)
    can_win[mass[n].second] = true;

    for (int i = n - 1; i > 0; i--) {
        auto cur_og_ind = mass[i].second;
        auto nxt_og_ind = mass[i + 1].second;
        // cerr << cur_og_ind << ' ' << nxt_og_ind << '\n';

        if (pre[i] >= mass[i + 1].first && can_win[nxt_og_ind]) {
            can_win[cur_og_ind] = true;
        }
    }

    repi(i, 1, n) { cout << (can_win[i] ? 'W' : 'L'); }
    cout << '\n';
}
