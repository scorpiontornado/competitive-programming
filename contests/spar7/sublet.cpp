// Upsolved with the help of ChatGPT
// https://chatgpt.com/share/68c44357-86f4-8006-ba5f-e11e9740023c
//
// (was originally gonna binary search distance of line from side to find the
// line parallel to that side that splits the area in two, e.g. checking using
// (AB x AC) / 2o, repeat for the other sides, then output the min line length)
//  - actually, in retrospect idek if this is possible given the input format

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
    cout << fixed << setprecision(15);  //! careful!

    int a, b, c;  // triangle side lengths
    cin >> a >> b >> c;

    // Smaller triangle is similar to the larger one, side lengths scaled by k
    // (the linear scale factor). Area scales by k^2, and we want the smaller
    // triangle to have half the area, so k^2 = 1/2, i.e. k = 1/sqrt(2).

    // Test dividing parallel to each side, scaled by k; min(a/k, b/k, c/k)
    cout << min({a, b, c}) / sqrt(2) << '\n';
}
