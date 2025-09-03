// Author: scorpiontornado
// Created: 2025-09-04 1:39am, AC 2:00am
// Source: https://atcoder.jp/contests/abc420/tasks/abc420_b

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

char votes[111][111];

void solve() {
    int n, m;
    cin >> n >> m;

    // vector<string> votes(n);
    // vector<vector<char>> votes(n); // n x m matrix
    vi count0(m);  // number of 0's in each column (jth vote)

    rep(i, 0, n) {
        // votes[i] = vector<char>(m);
        rep(j, 0, m) {
            cin >> votes[i][j];

            //! BUG: changed counts to count0, forgot to change '1' to '0'
            if (votes[i][j] == '0') {
                count0[j]++;
            }
        }
    }

    vi points(n);
    int max_pts = 0;
    rep(i, 0, n) {
        rep(j, 0, m) {
            int x = count0[j];  // # 0's
            int y = n - x;      // # 1's

            // XXX: kinda messy ngl... might not need y, meh
            // (also, maybe could just remove x == 0 and y == 0, & use <=)
            if (x == 0 || y == 0 || (votes[i][j] == '0' && x < y) ||
                (votes[i][j] == '1' && y < x)) {
                points[i]++;
            }
        }
        max_pts = max(max_pts, points[i]);
    }

    // cerr << max_pts << endl;  //!

    // XXX: could use a set or smth rather than another loop
    rep(i, 0, n) {
        if (points[i] == max_pts) {
            cout << i + 1 << ' '; // XXX: trailing space
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
}
