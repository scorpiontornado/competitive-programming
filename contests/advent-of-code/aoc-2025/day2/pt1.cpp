// Author: scorpiontornado
// Created: 2025-12-01 11:36pm
// Problem:

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
    ll sum = 0;
    int start, end;
    char sep;
    // TODO: investigate better way of handling comma/hyphen-separated inputs
    // https://stackoverflow.com/questions/21837521/how-to-read-in-user-entered-comma-separated-integers
    // https://www.reddit.com/r/adventofcode/comments/189l6nt/using_c_was_a_terrible_idea/

    // while (cin >> start >> sep >> end >> sep) {
        // cerr << start << ' ' << end << '\n';

        // for (int x = start; x <= end; x++) {
        //     int n_digits = floor(log10(x));

        //     // Check if second half of number is equal to first
        //     //if (n_digits % 2 == 0 && )
        // }
    }
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
