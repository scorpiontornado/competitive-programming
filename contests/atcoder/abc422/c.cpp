// Author: scorpiontornado
// Created: 2025-09-07 11:16pm, upsolve (full rewrite after c_fix.cpp failed)
// Source: https://atcoder.jp/contests/abc422/tasks/abc422_c

// 11:33pm, testing. Not 100% convinced, but it's worth a shot...
// 2025-09-08 10:28pm, debugging.. how tf -1? For 100 0 0. Also overcounting for
//  sample 3/4, outputting 2 -1 1666666 60 1. 11:15pm, go fr!
// 11:27pm, fixed? Remove debug prints & submit!
// 11:31pm, AC!!!! Let's goooooooooo!!! Satisfying af, didn't read editorial.

// What worked well?
//  - Was stuck reasoning abt correctness of my o.g. alg & was WA'ing, so I...
//      - Re-read the Q multiple times & started again from a fresh slate
//      - Visualised it differently - allocating beads from piles A, B, C to
//        piles ABC, AAC, and ACC
//      - Tried to only use things I could be confident about their correctness:
//          1. Take as many ABCs as possible (greedy stays ahead, in a way? Only
//             way to use the B's, and the alternative is taking an A/C that
//             could be used elsewhere)
//          2. Was quite confident in my ability to manually solve cases w equal
//             A's & C's, alternate. Rough proof in ob 2025-09-07 daily note(?)
//          3. Was quite confident in my ability to reduce any case to that
//             specific one (na == nc), as each AAC decreases delta = na - nc,
//             and each ACC increases it. Just take one or the other until delta
//             == 0 (or na == 0 or nc == 0)
//  - Not 100% sure why I failed originally, prob smth to do with taking too
//    many AAC's over ACC's (or vice versa if nc > na)? ... 11:45pm, try D?

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
    // na--, nb--, nc--; //! BUG (caused the -1 for 100 0 0, made it 99 -1 -1)
    na -= ans, nb -= ans, nc -= ans;

    //! dbg
    // cerr << "ans: " << ans << ", " << na << ' ' << nb << ' ' << nc << '\n';

    // Take AAC or ACC until delta == 0 (i.e. na == nc), or one of them is 0
    int delta = na - nc;

    if (delta > 0) {  // more A's
        int aac = min({delta, na / 2, nc});
        ans += aac;
        na -= aac * 2;
        nc -= aac;

        // cerr << "aac: " << aac << ", ans: " << ans << ", " << na << ' ' << nb
        //      << ' ' << nc << '\n';  //! dbg
    } else if (delta < 0) {  // more C's
        int acc = min({-delta, na, nc / 2});
        ans += acc;
        na -= acc;
        nc -= acc * 2;

        // cerr << "acc: " << acc << ", ans: " << ans << ", " << na << ' ' << nb
        //      << ' ' << nc << '\n';  //! dbg
    }

    assert(na == nc || na == 0 || nc == 0);

    // Alternate taking AAC and ACC until na == 0 or nc == 0
    if (na > 0 && nc > 0) {
        // Take complete groups of 3 (implicit floor), valid because na == nc
        ans += (na + nc) / 3;
        // cerr << "ans: " << ans << ", " << na << ' ' << nb << ' ' << nc
        //      << '\n';  //! dbg
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
