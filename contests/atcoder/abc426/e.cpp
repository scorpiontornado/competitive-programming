// Author: scorpiontornado
// Created: 2025-10-04 10:58pm
// Problem: https://atcoder.jp/contests/abc426/tasks/abc426_e

// - Was super close during the contest, submitted (to D, not E!!!) with like 10
//   seconds to spare, having not even compiled it & just finishing get_pos().
//   - Had an infinite loop... was iterating until lo <= hi because I changed ld
//     (from the ternary search in UNSW COMP4128 lec code, "lawn") to int.
// - Realised afterwards that the answer is a real number, not integer, anyway -
//   just look at the sample output!
// - Changed back to double, had to change ans (final answer) to be the average
//   of lo & hi after finishing, rather than setting it to be one of the check()
//   values in the while loop.
// - Confused by getting 2.000000000141492 for the second test case (1, 4 0 2 0,
//   6 0 8 0) rather than 2.000000000000000. Tried many things to fix it:
//   - Changing dist to distsqr (squared distance) in check(), as done by lawn.
//     Rationale: more accurate comparisons. Required sqrt'ing the final answer.
//   - Changing double to ld (long double)
//   - Raising the iterations from 70 to 100 (have also seen 200 thrown around
//     on codeforces as an "obscenely high bound, never need to worry abt it
//     again" type thing) -> worked!!!
//     - Realised it didn't have enough time for hi to get close enough to 0.
//     - Turns out it wasn't even necessary!! Error can be within 10^-6...
// - Submit! 1:28am (finished maybe 15 mins ago? But had 10^-6 maybe 1hr ago)
//   - WA'd all but sample??? wtf???

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
using pt = pair<ld, ld>;

/*
 * UNSW COMP4128 lecture code (changed double -> ld, unnecessary though?)
 */
inline ld sq(ld t) { return t * t; }

ld dist(pt p, pt q) { return sqrt(sq(p.x - q.x) + sq(p.y - q.y)); }
/* End UNSW COMP4128 lecture code */

// ld distsqr(pt p, pt q) { return sq(p.x - q.x) + sq(p.y - q.y); }

// Position after time seconds, moving from start (s) to goal (g) at speed 1
pt get_pos(pt s, pt g, ld time) {
    ld d = dist(s, g);
    ld proportion = min(time, d) / d;  // ??? check - want value in [0, 1]

    pt vec = pt(g.x - s.x, g.y - s.y);  // g - s = vector from S to G

    ld x = s.x + vec.x * proportion;
    ld y = s.y + vec.y * proportion;

    return pt(x, y);
}

// Returns distance between segments [ts, tg] and [as, ag] at given time
ld check(pt ts, pt tg, pt as, pt ag, ld time) {
    pt t_pos = get_pos(ts, tg, time);
    pt a_pos = get_pos(as, ag, time);

    return dist(t_pos, a_pos);
    // return distsqr(t_pos, a_pos);
    // (doesn't rly help - lec code for Lawn does it, & sqrt final answer)
}

void solve() {
    ld tsx, tsy, tgx, tgy;
    cin >> tsx >> tsy >> tgx >> tgy;
    pt ts = pt(tsx, tsy);
    pt tg = pt(tgx, tgy);

    ld asx, asy, agx, agy;
    cin >> asx >> asy >> agx >> agy;
    pt as = pt(asx, asy);
    pt ag = pt(agx, agy);

    // (-100, -100) to (100, 100): sqrt(200^2 + 200^2) = 282.8427124746 seconds
    // int lo = 0, hi = 300;  // time
    // double ans = -1; // ??? double or ld?
    ld lo = 0, hi = 300;  // time

    // Ternary search from UNSW COMP4128 lecture code, "lawn" (changed ld->int)
    //! oops... ld -> int was a bad idea fml... infinite loop and also you can
    //! have non-integer outputs, just look at the samples!!
    //* (See e_contest.cpp for original code, upsolved shortly after contest)

    // while (lo <= hi) {
    // for (int it = 0; it < 70; it++) {
    for (int it = 0; it < 100; it++) {
        ld mid1 = (hi + 2 * lo) / 3;
        ld mid2 = (2 * hi + lo) / 3;

        // cerr << lo << ' ' << hi << ' ' << mid1 << ' ' << mid2 << ' '
        //      << check(ts, tg, as, ag, mid1) << ' '
        //      << check(ts, tg, as, ag, mid2) << endl;  //! dbg

        if (check(ts, tg, as, ag, mid1) > check(ts, tg, as, ag, mid2)) {
            lo = mid1;
        } else {
            hi = mid2;
        }
    }

    // assert(ans >= 0 - EPS);

    ld closest_time = (lo + hi) / 2;
    ld ans = check(ts, tg, as, ag, closest_time);
    // cerr << closest_time << ' ' << ans << endl;  //! dbg

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);
    cerr << fixed << setprecision(11);

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }
}
