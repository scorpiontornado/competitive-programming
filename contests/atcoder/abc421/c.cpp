// TODO: fix... WA x3, TLE x2 (~4:11pm, started @ 3:30pm, 2 Sep 2025)

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

void solve() {
    int n;
    string s;  // length: 2n (n of 'A', n of 'B')... using sz(s) is safer though
    cin >> n >> s;

    ll swaps = 0;

    // Inspired by bubble sort
    for (int i = 1; i < sz(s); i++) {  // [0, i) is "sorted"
        if (s[i] == s[i - 1]) {
            // Find first one that's different & swap it down to position i
            int j = i + 1;
            while (j < sz(s) && s[i] == s[j]) {
                j++;
            }
            // XXX: what if can't find within n?
            assert(j < sz(s) && s[i] != s[j]);  //! check

            // Takes j-i swaps between adjacent elements to move s[j] to pos i
            // (can just swap directly as s[i..<j] is the same)
            swaps += j - i;
            swap(s[i], s[j]);
        }
    }

    cout << swaps << "\n";
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
