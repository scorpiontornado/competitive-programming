// Author: scorpiontornado
// Created: 2025-09-04 2:28/29am, 44 min left... read D-G. 3:10/11am AC!! 2 min
// Source: https://atcoder.jp/contests/abc420/tasks/abc420_d

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

const int N = 505;
char grid[N][N];  // h x w
// bool seen[N][N];
int dist[N][N][2];  // row, col, switch active (0 = no); doubles as seen matrix

// up, down, left, right
int dr[] = {-1, 1, 0, 0};
int dc[] = {0, 0, -1, 1};

void solve() {
    int h, w;
    cin >> h >> w;

    pii start, goal;

    rep(r, 0, h) {
        rep(c, 0, w) {
            cin >> grid[r][c]; //! BUG: was reading into grid[h][w]

            if (grid[r][c] == 'S') {
                start = pii(r, c);
            } else if (grid[r][c] == 'G') {
                goal = pii(r, c);
            }

            fill(dist[r][c], dist[r][c] + 2, INF);  // XXX
        }
    }
    // cerr << "start: " << start.first << ' ' << start.second << endl;  //!
    // cerr << "goal: " << goal.first << ' ' << goal.second << endl;     //!

    queue<pair<pii, bool>> q;  // ((row, col), switch active)
    q.emplace(start, false);
    dist[start.first][start.second][0] = 0;

    while (q.size()) {
        auto [u, active] = q.front();
        q.pop();
        // cerr << u.first << ' ' << u.second << ' ' << active << endl;  //!

        // visit neighbours
        rep(i, 0, 4) {
            int nr = u.first + dr[i];
            int nc = u.second + dc[i];
            if (nr < 0 || nr > h || nc < 0 || nc > w) continue;

            char ncell = grid[nr][nc];
            if (ncell == '#' || (ncell == 'x' && !active) ||
                (ncell == 'o' && active)) {
                continue;
            }
            // can move to neighbour

            bool new_active = (ncell == '?') ? !active : active;
            // perhaps could use xor..? new_active = active ^ (ncell == '?')

            if (dist[nr][nc][new_active] < INF) continue; //! BUG: forgot

            dist[nr][nc][new_active] = dist[u.first][u.second][active] + 1;
            q.emplace(pii(nr, nc), new_active);

            // check goal reachable - if so, must be shortest path (BFS)
            if (nr == goal.first && nc == goal.second) {
                cout << dist[nr][nc][new_active] << '\n';
                return;
            }
        }
    }

    // goal is unreachable
    cout << -1 << '\n';
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
