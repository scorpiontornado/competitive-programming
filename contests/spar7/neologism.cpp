// Thoughts: graph, if cycle -> infinite, else output longest path

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

const int N = 26;
const int UNSEEN = 0, ACTIVE = 1, COMPLETE = 2;
int status[N];  //! make sure to reset to UNSEEN!

vector<vll> g(26);

bool has_cycle(ll u) {
    if (status[u] != UNSEEN) return false;
    status[u] = ACTIVE;  // preorder: push to DFS stack

    for (auto v : g[u]) {
        if (status[v] == ACTIVE || has_cycle(v)) return true;
    }

    status[u] = COMPLETE;  // postorder: DFS stack pop
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    // for (int i = 0; i < n; i += 1) {

    rep(i, 0, n) {
        string s;
        cin >> s;
        g[s[0] - 'a'].emplace_back(s[1] - 'a');
    }

    rep(i, 0, 26) {
        fill(status, status + n, UNSEEN);
        if (has_cycle(i)) {
            cout << -1 << "\n";
            return 0;
        }
    }

    // Now g is a DAG

    ll ans = 0;
    rep(i, 0, 26) {
        deque<pll> q;

        q.emplace_back(i, 1);

        while (q.size()) {
            auto [u, d] = q.front();
            q.pop_front();

            for (auto v : g[u]) {
                q.emplace_back(v, d + 1);
            }
            if (!g[u].size()) {
                ans = max(ans, d);
            }
        }
    }

    deque<char> s;

    rep(i, 0, 26) {
        deque<pair<ll, ll>> q;
        vector<ll> prev(26, -1);

        q.emplace_back(i, 1);

        while (q.size()) {
            auto [u, d] = q.front();
            q.pop_front();

            for (auto v : g[u]) {
                q.emplace_back(v, d + 1);
                prev[v] = u;
            }
            if (!g[u].size()) {
                if (ans == d) {
                    auto w = u;
                    while (prev[w] != -1) {
                        s.emplace_front(w + 'a');
                        w = prev[w];
                    }
                    s.emplace_front(w + 'a');
                }
            }
        }
    }

    cout << ans << '\n';
    for (auto c : s) cout << c;
    cout << "\n";
    // cerr << "?? " << s.size() << "\n";
}
