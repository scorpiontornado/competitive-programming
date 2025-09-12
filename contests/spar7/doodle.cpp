//! TLE, potentially a broken test case? doodle.in looks like malformed input

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

    string moves;
    cin >> moves;

    vector<vi> jmp(moves.size());
    vi most_recent(26, -1);  // index of most recent time to see this letter

    for (int i = sz(moves) - 1; i >= 0; i--) {
        jmp[i] = most_recent;
        most_recent[moves[i] - 'a'] = i;  //! CAREFUL!
    }

    // rep(i, 0, sz(moves)) {
    //     rep(j, 0, 26) { cerr << jmp[i][j] << ' '; }
    //     cerr << '\n';
    // }

    int n;
    cin >> n;

    int ans = 0;
    // assert(sz(moves) <= 106);
    //! why does this assert break it???

    rep(_, 0, n) {
        string enemy;
        cin >> enemy;

        ans++;
        int m = most_recent[enemy[0] - 'a'];
        if (m == -1) {
            ans--;
            continue;
        }
        for (int i = 1; i < sz(enemy); i++) {
            m = jmp[m][enemy[i] - 'a'];
            // cerr << "?? " << m << "\n";
            if (m == -1) {
                ans--;
                break;
            }
        }

        // int pos = 0;
        // for (char c : moves) {
        //     if (pos < sz(enemy) and c == enemy[pos]) {
        //         pos++;
        //     }
        //     if (pos >= sz(enemy)) {
        //         ans++;
        //         break;
        //     }
        // }
    }

    cout << ans << '\n';
}
