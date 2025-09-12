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

    // TODO: rotate points around entrance clockwise by the angle of peanut from
    // entrance (CCW from positive "x-axis", if entrance were the origin)
    //  -> i.e., make entrance-peanut line segment horizontal

    // TODO: binary search for smallest radii that covers the segment

    // TODO: for a given radius, find circle-segment intersection for each dark
    // zone & check union of all of them = original segment (perhaps >=)
    //  - should be easier given the segment is now horizontal? take min of left
    //    points, max of right points
}
