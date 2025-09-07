// Author: scorpiontornado
// Created: 2025-09-07 2:56pm
// Source: https://atcoder.jp/contests/abc422/tasks/abc422_c

// Clarification: 'In the problem statement, "using a letter" means "consuming a
//  letter." Whenever Takahashi uses (consumes) a kind of letter, the number of
//  letters of that kind he has decreases by 1. Notably, whenever he holds a
//  contest, he needs to consume a total of three letters.'

// OBS: order doesn't matter, & dupes allowed (clarif)
// IDEA: prioritise taking B, to preserve A/C for later
// OBS: need O(1) for each test case (or O(log n))
// TIME: 3:15pm, distracted, back.. WA'd at 3:12pm.... 34 min remaining gg
//  - AC'd sample and 1 in all, odd, smth badly wrong... could try ll but in
//    theory should be bounded by 1e9?
//  - 3:17pm, realised, ... nvm thought maybe BBBB would mess it up, nah?
//  - surely is equal case, did have ???'s etc... 3:18pm 31 min rem gogogogo
//  - wait just that, what if na=5, nc=4: could make AAC, AAC, ACC
// TIME: 3:25pm, failed all but sample again???? wtf.. passed my na=5, nc=4 test
//  - 3:29pm got it!! idk how i missed, but take 2* off A in AAC
//  - 3:32pm 16 min rem, still ACx1, WAx13...????? Passing sample is annoying af

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
#pragma endregion

void solve() {
    ll na, nb, nc, ans;
    cin >> na >> nb >> nc;

    ll abc = ans = min({na, nb, nc});  // contests involving b
    na -= abc, nc -= abc;

    // rest must use A & C only, need 3 letters & at least one A & C
    // if (na > nc) {
    //     // AAC
    //     // XXX: check logic
    //     ans += min(na / 2, nc);
    // } else if (nc > na) {
    //     // ??? is this valid for na == nc?
    //     ans += min(nc / 2, na);
    // }

    // ??? order doesn't matter, right?
    ll aac = min(na / 2, nc);
    ans += aac;
    na -= aac * 2;
    nc -= aac; //! BUG: forgot * 2.. then separated to separate lines, paranoia

    ll acc = min(na, nc / 2);
    ans += acc;

    cout << ans << '\n';
    cerr << abc << ' ' << aac << ' ' << acc << endl; //! dbg
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
