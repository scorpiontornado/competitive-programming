// Author: scorpiontornado
// Created: 2025-09-207 10:08pm
// Problem: https://atcoder.jp/contests/abc425/tasks/abc425_a

// Registered 40 seconds late (after 10:05pm), cause I was filling in personal
// info for "UNIQUE VISION", some random Japanese company, rip... 10:10:00pm go!
// 10:18pm, submit after rabbithole trying to figure out how to use pow on ints

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
    int n;
    cin >> n;

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += round(pow(-1, i) * pow(i, 3));  // ??? pow is for floats/doubles?
    }

    cout << ans;
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
