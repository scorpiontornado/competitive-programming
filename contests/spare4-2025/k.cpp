// 3:40pm pondering again, just noticed the bounds, n=1000??? I was looking for
// a greedy or smth, but could do at least n^2, maybeee n^3.
//  - def can't test all perms though
//  - lowkey reminds me of a lecture example, filling with water or smth
//  - on left, is length of .. LIS or smth..
//    - 1 5 2 3 4 -> 2 from left, goes to 1, 5, then cause n = 5, can't see
//    higher
//                   1 from right, 5 blocks all
//    - 1 2 3 4 5 -> 5 from left. 1 from right
//    - 1 3 2 4 5 -> 4 from left (3 blocks the 2), 1 from right
// Observation: if a clue is 1, the 5 must be placed on that side
//  - if a clue is 2 (& n = 5), could have... 1 5 2 3 4, 2 5 x x x, 3 5 x x x
//  - wait, does that mean the skyscraper of height n must be placed {left clue}
//    distance from the left?
//  - no... consider, 2 1 5 x x, 3 2 1 5 4, 4 3 2 1 5
//    - all 2 from left, but from right they're 2/3, 2, and 1 respectively
//    - can't have 2 from left, 4 from right? nvm 1 5 4 3 2
// - Feels like rooks ngl, can't place in same row/col? bounds throwing me off,
//   & the left/right clues
// Smaller example? n = 3 ... 3:49pm gah heart pounding again!
//  - 1 2 3          -> L = 3, R = 1
//  - 1 3 2          -> L = 2, R = 2
//  - 2 1 3          -> L = 2, R = 1
//  - 2 3 1 (mirror) -> L = 2, R = 2
//  - 3 1 2 (mirror) -> L = 1, R = 2
//  - 3 2 1 (mirror) -> L = 1, R = 3
// Note: it's impossible to get L = 1, R = 1 and L = 3, R = 3. Only 2/2,
// twice... knowing L = 3 means we can rule out possibilities ending in 3, but
// not much else 3:53pm, I feel dumb ngl,, 1st place team got it in 15, 2nd
// place in 17 mins...

// Could it be DP??? assuming I place a 1 here, is it possible to get L & R?
//  - what states are we reusing?

// 3:56pm, staring at samples - given 6, look for patterns.
// - if either clue is 1, the largest must be at that side
// - it doesn't really matter what heights the obscured skyscrapers are
// - if only had one clue, would be triv - e.g. if n=5, L=3, do 3 4 5 x x
//    - ok consider L=3... (implies 5 must be >= position 3)
//      - what if R=1? 3 4 1 2 5 (must put the 5 at end)
//      - R=2? 3 4 5 1 2
//      - R=3? 3 4 5 2 1
//      - R=4? impossible.. for L=3, need 5 to be position >= 3... but for R=4,
//        need 5 to be position <= n-4
//  - n=5, L=2 - posit could do 4 5 x x x
//    - R=1, breaking case!!! need 4 x x x 5
//    - R=2, could do 4 5 1 2 3, or 4 5 2 1 3
//    - R=3, could do 4 5 3 1 2, or 4 5 2 3 1 or 4 5 1 3 2
//    - R=4, could do 4 5 3 2 1 only.
//    - R=5, impossible!
// lowkey giving insertion sort (O(n^2)) vibes?
// 4:04pm feel like I'm getting closer but not generalised....
//  - ok for the R=1 case, why must put 5 at end? more "pressing"? Maybe cause
//    it's lower?
//  - consider again L=3, R=2. Try to allocate R first. x x x 5 4
//    - then, to get L=3, would do... 1 2 3 5 4 -> yep, works!
//  - formula: pick the lower of the two clues and allocate n=from edge to
//  centre,
//    n - clue + 1, n - clue + 2, ..., n ?
//  - then, only have access to 1..(n-clue) for the other side. Repeat, n -=
//  clue
//    - ngl that's the bit that's still hazy...
// 4:10pm, good as any... go!
// 4:32pm, stuck on allocating right side... gg
//  - think of it as a dual of the left, mirrored.. allocate on right as much
//    as needed, then fill the rest w junk... 4:33pm cmon!! want at least this..
// 4:42pm, finished writing out, feels dirty, idk if correct...
//  - segfault?? gg.. wait, indexing idk
//  - used i++ not i--, and had the condition flipped, should be r_ind <= right
//  - now passing all sample tests?? submit! 4:47pm
// - OMG!!!! CORRECT!!! 4:48pm, that was the most dogwater code...
//  - now done HLGK, not D...
// - A done by 6 (maybe 7) teams, B by 2, C by 1, D by 7, E by 0 (maybe 2),
//   F by 3 (3 more failed), G by 9 (maybe 10), H by 11 (maybe 12),
//   I by 0 (maybe 1), J by 3, K by 11 (incl. me), L by 10 (maybe 11)
// - "UNSW K17 Seclab" only done D, damn.. must be rectangle sliding surely?
//    Either that, or it's ccw/convex hull and Hugo did it, lol.. bizarre...
// - 4:52pm, 8 mins, either debug D or rewrite sliding lines?? idk.. now 6.5 mins

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, left, right;
  cin >> n >> left >> right;

  vector<int> heights(n);

  bool mirror = false;
  if (left > right) {
    swap(left, right);
    mirror = true;
  }
  if (right < 2 || right > n - left + 1) { // TODO: check
    cout << "no\n";
    return 0;
  }

  // e.g. n = 5, left = 2, allocate 4 5 x x x. Or, left=3, allocate 3 4 5 x x
  // etc
  for (int i = 1; i <= left; i++) {
    heights[i - 1] = n - (left - i);
    // cerr << i << ' ' << heights[i - 1] << endl; //! debug
  }

  // TODO: print no if impossible... can only do [2, n-left+1] on right? hrm.
  // -> done above (4:26pm)

  // now used up numbers (n-left, n], have numbers [1, n-left] available to put
  // on right. Keep in mind the 5 will add a 1 to the right number
  // for (int i = n; i > left; i++) {
  //   heights[i - 1] =
  // }

  right--; // 5 already takes up one, easier to ignore
  int new_max = n - left;
  // if n=3 remaining, allocate x x 3 (R=1), or x 3 2 (R=2), or 3 2 1 (R=3)
  // as before, mirrored
  for (int i = n; i > left; i--) {
    int r_ind = n - i + 1;
    if (r_ind <= right) {
      heights[i - 1] = new_max - (right - r_ind);
    } else {
      // Allocate leftover as whatever
      // TODO: check
      heights[i - 1] = r_ind - right;
      // TODO: maybe move "no" check here?? ensure r_ind - right isn't negative?
      //  -> can't be? r_ind > right by the condition...
    }
  }

  if (mirror)
    reverse(heights.begin(), heights.end());

  cout << "yes\n";
  for (auto h : heights) {
    cout << h << ' '; // TODO: newline
  }
}