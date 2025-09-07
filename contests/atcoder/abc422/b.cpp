// Author: scorpiontornado
// Created: 2025-09-07 2:26pm
// Source: https://atcoder.jp/contests/abc422/tasks/abc422_b

// 2:39pm WA on 7/19, passed samples??
// 2:49pm back after pondering then mini break... re-read Q, idk...
// 2:53pm, found it! % 2 is no good, allows 0... 2nd task in a row slowed down
//  by tryna get too fancy w mod stuff.. -> AC! 2:54/55pm, 4027th

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

// ---

// const int N = 22; // 20 + buffer
// char grid[N][N];

const int di[] = {-1, 1, 0, 0};
const int dj[] = {0, 0, -1, 1};

void solve() {
    int h, w;
    cin >> h >> w;

    vector<string> grid(h);
    rep(i, 0, h) { cin >> grid[i]; }

    rep(i, 0, h) {
        rep(j, 0, w) {
            //! BUG: forgot
            if (grid[i][j] != '#') continue;  // only check black

            // Count num neighbouring black cells
            int count = 0;
            rep(n, 0, 4) {
                int ni = i + di[n];
                int nj = j + dj[n];  //! BUG: used i + not j +
                assert(abs(i - ni) + abs(j - nj) == 1);

                if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                if (grid[ni][nj] == '#') count++;
            }
            // if (count % 2 != 0) { //! BUG: allows 0
            if (not(count == 2 || count == 4)) {
                cout << "No\n";
                // cerr << i << ' ' << j << ' ' << count << endl; //! dbg
                return;
            }
        }
    }
    cout << "Yes\n";
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
