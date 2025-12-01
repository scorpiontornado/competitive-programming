// Author: scorpiontornado
// Created: 2025-10-04 10:58pm
// Problem: https://atcoder.jp/contests/abc426/tasks/abc426_e

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

#define x first
#define y second
using pt = pair<double, double>;

/*
 * UNSW COMP4128 lecture code
 */
inline double sq(double t) { return t * t; }

double dist(pt p, pt q) { return sqrt(sq(p.x - q.x) + sq(p.y - q.y)); }
/* End UNSW COMP4128 lecture code */

// Position after time seconds, moving from start (s) to goal (g) at speed 1
pt get_pos(pt s, pt g, int time) {
    ld d = dist(s, g);
    ld proportion = min(ld(time), d) / d;

    pt vec = pt(g.x - s.x, g.y - s.y);  // g - s = vector from S to G

    double x = s.x + vec.x * proportion;
    double y = s.y + vec.y * proportion;

    return pt(x, y);
}

// Returns distance between segments [ts, tg] and [as, ag] at given time
double check(pt ts, pt tg, pt as, pt ag, int time) {
    pt t_pos = get_pos(ts, tg, time);
    pt a_pos = get_pos(as, ag, time);

    return dist(t_pos, a_pos);
}

void solve() {
    double tsx, tsy, tgx, tgy;
    cin >> tsx >> tsy >> tgx >> tgy;
    pt ts = pt(tsx, tsy);
    pt tg = pt(tgx, tgy);

    double asx, asy, agx, agy;
    cin >> asx >> asy >> agx >> agy;
    pt as = pt(asx, asy);
    pt ag = pt(agx, agy);

    // (-100, -100) to (100, 100): sqrt(200^2 + 200^2) = 282.8427124746 seconds
    int lo = 0, hi = 300;  // time
    double ans = -1;

    // Ternary search from UNSW COMP4128 lecture code, "lawn" (changed ld->int)
    // for (int it = 0; it < 70; it++) {
    while (lo <= hi) {
        int mid1 = (hi + 2 * lo) / 3;
        int mid2 = (2 * hi + lo) / 3;
        // if (check(ts, tg, as, ag, mid1) > check(ts, tg, as, ag, mid2)) {
        if ((ans = check(ts, tg, as, ag, mid1)) > check(ts, tg, as, ag, mid2)) {
            lo = mid1;
        } else {
            hi = mid2;
        }
    }

    assert(ans >= 0 - EPS);

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
