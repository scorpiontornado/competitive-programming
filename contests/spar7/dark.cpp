// Upsolving at 4:50pm, 2025-09-13. Came up w idea last night. Either use:
//  - codebook code for distance from point (centre) to segment, or
//  - codebook code for circle line intersection

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

// Codebook section 3.1
double INF = 1e100;  //! fits, surprisingly? IEEE-754
double EPS = 1e-12;

struct pt {
    double x, y;
    pt() {}
    pt(double _x, double _y) : x(_x), y(_y) {}
    pt(const pt &p) : x(p.x), y(p.y) {}
    // TODO: operator=
    pt operator+(const pt &p) const { return pt(x + p.x, y + p.y); }
    pt operator-(const pt &p) const { return pt(x - p.x, y - p.y); }
    pt operator*(double c) const { return pt(x * c, y * c); }  //! c, not p
    pt operator/(double c) const { return pt(x / c, y / c); }  //! c, not p
    bool operator<(const pt &p) const {
        //! untested, careful of floating point comparisons (-Wfloat-equal)
        // basically `x < p.x || (x == p.x && y < p.y)`
        return x + EPS < p.x || (x - p.x < EPS && y + EPS < p.y);

        //! "Avoid pt::operator< with EPS inside; it can break strict weak
        //! ordering and make sort undefined. When working in 1D with [tL, tR]
        //! you sort by doubles directly." - Copilot (GPT-5)
    }
    // partial_ordering operator<=>(const pt &p) const {
    //     return pair<double, double>(x, y) <=> pair<double, double>(p.x, p.y);
    //     //! issue with EPS n whatnot?
    // }
};
// 3 min to copy out

double dot(pt p, pt q) { return p.x * q.x + p.y * q.y; }
double dist2(pt p, pt q) { return dot(p - q, p - q); }
double cross(pt p, pt q) { return p.x * q.y - p.y * q.x; }
// 2 more min, nearly 4:46pm

ostream &operator<<(ostream &os, const pt &p) {
    return os << "(" << p.x << "," << p.y << ")";
}

// circle centred at c, radius r
vector<pt> circle_line_intersection(pt a, pt b, pt c, double r) {
    //? lowkey no idea how this works
    vector<pt> ret;
    b = b - a;
    a = a - c;

    double A = dot(b, b);
    double B = dot(a, b);
    double C = dot(a, a) - r * r;
    double D = B * B - A * C;

    if (D < -EPS) return ret;
    ret.push_back(c + a + b * (-B + sqrt(D + EPS)) / A);
    if (D > EPS) ret.push_back(c + a + b * (-B - sqrt(D)) / A);
    return ret;
}
// 5:08pm, but got distracted looking @ INF & doubles

pt rotateCCW(pt p, double t) {
    return pt(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}
// 5:09pm

// rotate a point by t radians around a given origin, o
//? (vaguely remembered from lec code, not in codebook...)
pt rotateCCW(pt p, double t, pt o) {
    // subtracting o from o moves it to the origin; subtracting from p moves it
    // to the same point relative to the origin as it was relative to o(?)
    return rotateCCW(p - o, t) + o;
}
// 5:13pm, 22 min so far... onto main I/O

// //! only compares x-coords, bit scuffed ngl, might not work properly
// bool within_segment(pt p, pt start, pt end) {
//     // TODO: generalise code to 1D projections on the segment rather than
//     //       needing to rotate it to be horizontal
//     cerr << "within_segment: " << p << ", " << start << ", " << end
//          << '\n';  //! dbg
//     return p.x + EPS >= start.x && p.x - EPS <= end.x;
// }

// Tests whether it's possible to cover the segment [`start`, `end`] using
// circles of radius `r` & centered at `centres`.
bool check(double r, pt &start, pt &end, vector<pt> &centres) {
    // (5:54pm)
    // Check end is right of start (or equal)
    assert(end.x + EPS > start.x && abs(end.y - start.y) < EPS);

    // ???: how to union intersections...? perhaps add to vector, sort? what on?
    vector<pair<pt, pt>> intersections;
    for (pt &c : centres) {
        auto intersect = circle_line_intersection(start, end, c, r);
        // auto filtered = intersect | views::filter([&](pt p) {
        //                     return within_segment(p, start, end);
        //                 });  //! check this works on moodle runner? C++20
        // intersect = vector(all(filtered));

        if (intersect.size() == 1) {
            intersections.emplace_back(intersect[0], intersect[0]);
        } else if (intersect.size() == 2) {
            if (intersect[0].x > intersect[1].x) {
                swap(intersect[0], intersect[1]);
            }
            intersections.emplace_back(intersect[0], intersect[1]);
        }
    }

    sort(all(intersections));
    double seen_until = start.x;  // XXX: what if start & end are the same?
    for (const auto &[a, b] : intersections) {
        // cerr << a << ' ' << b << '\n';  //! dbg

        // check same y-coordinate as start, & that a is left of b
        // assert(abs(a.y - start.y) < EPS && abs(b.y - start.y) < EPS);
        assert(a.x < b.x + EPS);

        if (a.x > end.x) break;

        if (seen_until + EPS < a.x) {
            // gap in segment that's not covered (between seen_until & a.x)
            return false;
        }
        seen_until = b.x;
    }
    return seen_until + EPS > end.x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int n;
    cin >> n;

    double x, y;
    vector<pt> centres;  // dark zones
    rep(i, 0, n) {
        cin >> x >> y;
        centres.emplace_back(x, y);
    }

    cin >> x >> y;
    pt start = pt(x, y);  // entrance

    cin >> x >> y;
    pt end = pt(x, y);  // Golden Peanut
    // 5:19:00pm

    // DONE: rotate points around entrance clockwise by the angle of peanut from
    // entrance (CCW from positive "x-axis", if entrance were the origin)
    //  -> i.e., make entrance-peanut line segment horizontal

    pt path = end - start;  // vector from start to end (move start to origin)
    double t = atan2(path.y, path.x);  // angle of end relative to start

    // rotate all points clockwise by t around start, so end is horizontally to
    // the right of start
    end = rotateCCW(end, -t, start);
    for (auto &p : centres) p = rotateCCW(p, -t, start);

    // DONE: binary search for smallest radii that covers the segment
    //  5:25pm... now ~~5:39pm~~ 5:47pm, finally got the binary search on reals?
    //  https://codeforces.com/blog/entry/73888
    //  https://codeforces.com/blog/entry/63085?#comment-470021
    //? 2e5 should be large enough right?
    double lo = 0, hi = 200200, best_so_far = -1;

    // Range [lo, hi]
    // while (lo <= hi) {
    /* 100 (/200) should be more than enough, could also use lo + eps < hi (?)*/
    for (int i = 0; i < 100; i++) {
        double mid = (lo + hi) / 2;
        if (check(mid, start, end, centres)) {
            best_so_far = mid;
            // hi = mid - 1;
            hi = mid;
        } else {
            // lo = mid + 1;
            lo = mid;
        }
    }

    // DONE: for a given radius, find circle-segment intersection for each dark
    // zone & check union of all of them = original segment (perhaps >=)
    //  - should be easier given the segment is now horizontal? take min of left
    //    points, max of right points
    assert(best_so_far > -EPS);
    cout << best_so_far << '\n';
}
