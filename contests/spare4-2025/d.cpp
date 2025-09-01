#include <bits/stdc++.h>
#include <utility>
using namespace std;

using ll = long long;
using pt = pair<int, int>;
#define x first
#define y second
#define INF 1e9 + 7

int main() {
  int n;
  cin >> n;

  // pt tL, tR, bL, bR;
  // bool init = false;

  int x1 = INF, x2 = 0; // left (lower x), right
  int y1 = INF, y2 = 0; // bottom (lower y), top

  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;

    // if (not init || x < tL.x && y < tL.y) {
    //   tL = pt(x, y);
    // }
    // if (not init || x > tR.x && y < tR.y) {
    //   tR = pt(x, y);
    // }

    x1 = min(x1, x);
    x2 = max(x2, x);
    y1 = min(y1, y);
    y2 = max(y2, y);
  }

  cout << "4\n";

  // counter-clockwise: bottom left, bottom right, top right, top left
  // (all consecutive points share an x or y coord as instructed)
  cout << x1 << ' ' << y1 << '\n';
  cout << x2 << ' ' << y1 << '\n';
  cout << x2 << ' ' << y2 << '\n';
  cout << x1 << ' ' << y2 << '\n';
}

// ---

//  - 2:03pm, immediately recognised as convex hull
//  - can't remember how to do it off the top of my head, asked Yiheng, not
//    _supposed_ to use pre-prepared code but let's pretend I printed it out
//    beforehand
//  - 2:05pm, impl! Feeling Graham scan vibes though ngl given the ccw input &
//  output
//  - looked @ sample, only want vertices of the polygon.
//  - Wondering if Andrew's monotone chain gives in clockwise/ccw order?
//    - otherwise, need to try & remember graham scan...
//    - wait, is alr in counterclockwise order, should use graham scan to avoid
//      an unnecessary sort... 2:14pm, go! ... & we want counterclockwise,
//      change ccw
//    - also makes it fairer, have to type out myself
//  - ll prob unnecessary, doubt the bounds are that tight...
//  - oh also, W - no three points are collinear. Dw too much abt ccw >=0 vs >0
// (btw, msft C/C++ intellisense wasn't working, chmod issue again. installed
//  clangd, disabled msft intellisense, working like a charm! Even type hints
//  for auto!)
//  - 2:23pm nearly done main function & pondering Graham scan impl
//  - 2:30pm, maybe done?? Think with points sorted in ccw order already,
//    half_hull gives a full convex hull! Vs Andrew's ..., sorts by x coord,
//    breaking ties by y coord - then reverses & repeats
//  - test, 2:31pm... have dropped to 8th btw, 7th on 3 solves, 5th & 6th on 4,
//    4th on 5, 2nd & 3rd on 7, 1st (sanctioned...) on 8 - KDHLGAFJ
//  - uh oh... 2:35pm, outputting 5 pts, all are correct but wrong order??
//    (nvm if there are multiple valid solutions, may output any one of them....
//    still wrong though?)
//  - ok looks like my points are in clockwise order, odd..
//  - wait, 2:38pm, my alg is just fundamentally flawed omg... no diagonals
//  allowed,
//    but some right turns are? Also, no need for points to be points on
//    original shape
//    - wonder if I could start w convex hull then quantise the points or smth?
//  - turns out my points ARE in clockwise order but yep, missing a corner...
//    - Note that two consecutive points must have either the same x-coordinate
//      or the same y-coordinate
// - 2:43pm, entirely new direciton.. consider sliding edges? Or, perhaps ..
// shortcut
//   if alr seen that x coord etc?
//  - 2:44pm, stumped ngl, felt so close rah.... leave it!
//  - idk wait quantising feels so promising... if a new pt would have a diff
//    x and y coord to the prev, insert another point.. where?
//  - wait, no three points are collinear, so sides must alternate vert/hori
//  - so, insert pseudo-point on stack based on the coord pts[i] and pts[i-1]
//  have in common,
//    with the other ... from the top of stack?
//  - 2:56pm, miraculously passing sample cases? (Just rotated)
//    - 2:57pm, submit!
//    - Rah!! wrong answer, passed samples... Did have a warning though, meh
//  - I could be REALLY close, or I could be incredibly far off... 2:59pm,
//    2 hours remaining, swap. & cut the yap!!

//  - 3:00pm, new idea.. edge sliding? Bit heartbreaking but oh well..
//    - ccw order, so we know if we go ..
//  - wait, ccw order of the shape doesn't mean ccw order vs origin?
//    - hard to know if impl issue vs algo issue
//  - Theorem: if the past 3 points are counter-clockwise, take them. Else, if
//    clockwise, extend the previous line..?
//    - or.. need a way to "cancel out" two clockwise turns in a row?
//      Promising, might have edge cases, very much influenced by sample
//    - Doesn't even need to be 2 in a row? If the points from x=5-7 were
//    removed,
//      still valid to only take ccw turns, 4x3 rectangle... Same min dist
//  - Realised I'm recreating something v similar to what I had, modified
//  Graham's
//  - 3:14pm stuck again, going in circles.... move on
//  - 4:59pm, just randomly had an idea... too late lol! Was thinking abt moving
//    (5:00pm!!) edges, realised you can just draw one big rectangle around the
//    whole shape? Kinda a rectangle hull, in a way? I hypothesise you just need
//    to take 4 points to optimally cover any shape. Threw me off, cause none of
//    the samples had m=4 !!
//    - But yeah think my Graham Scan algo was either fundamentally flawed
//    (bandaid patch
//      with the pseudo-points/snapping to grid), or it's related to - just
//      cause the points were given in ccw order on the shape, doesn't
//      necesarily mean they're polar sorted in ccw order around the first
//      point..? Even in the diagram! Polar sort would give (1,2), (1,5), (7,5),
//      (5,2), (7,1), (5,1)?
// But yeah no requirement the bike path has to hug the edges or anything, just
// must be as short as possible!!

// 5:09pm, talked to (Miles?) - sactioned country 3, came 1st - yeah, D was
// just: draw a rectangle around the whole thing, becaues it's manhattan
// distance - can slide edges
// 5:12pm, impl quickly

// Btw Cameron's tip - many people solved it, & solved it QUICKLY, e.g. top
// team solved it in 19 mins, after solving their first problem in 15. Implies
// the implementation isn't very complex, and there's probably some "trick" or
// or simple solution.

// 5:43pm, finally done! Didn't realise bottom = lower y, maths-like not coding
//  - "TOO-LATE", rip, go home!