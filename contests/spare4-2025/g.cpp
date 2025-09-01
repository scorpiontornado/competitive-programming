// 1:39pm read Q, hrmm...
// 94 characters between 126-31
//  - 26 lowercase letters (need >= 1)
//  - 26 uppercaes letters (need >= 1)
//  - 10 digits (need >= 1)
//  - 32 special symbols (need >= 1)
// - &, between 8 to 12 characters.
// - Edit distance 2:
//  - Iterate over lengths 8, 10, 12
//  - for each, need at least two symbols different between each of same length
//  - or, could also do length 9 & 11 but must have 1 symbol different in
//    addition to the extra symbol?
// - 1 <= n <= 1000...
//    - n = 1, pick any valid password (e.g. 5 lowercase, 1 uppercase, 1 digit,
//    1 symbol)
//    - n = 2, pick e.g. two different lowercase in 2nd vs the 1st one
//      - e.g. aaaaaA0! and bbaaaA0! (or abbaaA0!) etc
//  - how many to do...? need 1000, order matters too?
//    - xxaaaA0! gives 26, can't do e.g. cbaaaA0! though cause too close to
//    bbaaaA0!
//    - axxaaA0! ... nvm some overlaps rah
//    - aaxxaA0! gives another 26?
// damn this feels like it should be easier, 1:48pm,
// wonder if maybe exponential DP or something, with 1000 would be cooked!
//  - need a way to guarantee edit distance >= 2 with ALL passwords so far

// 1:50pm, moving onto D (4 solves)... K also has 4 solves, could go back?
// G on 5 solves (everyone above me)
// 1:53pm skim other problems...
// 3:15pm stuck on D, back here - solved by the 7 above me
// 3:23pm back from break, still confused
//  - visualising it as a graph, can't select neighbours...
//  - probably too many neighbours to literally graph search
//  - thinking about combinations again... e.g. choose the number of letters,
//    choose their positions, etc... need 1000
//  - if select e.g. pairs of lowercaes letters, 12 character passwords, 6
//    non-overlapping places to put them. If assigning both the same letter,
//    that's 6*26=156 right there. can then easily get more by just varying the
//    number!! 1560
//    - wait, vary upper case letters intead ig, or even just number & symbol
//  - format: aaAA0000!!!!, and AAaa0000!!!!, and AA00aa00!!!! etc
//  - or wait, even just vary pairs of lowercase & uppercase letters
//    - aaAA0000!!!!, bbAA0000!!!!, cc....
//    - aaBB..., aaCC..., aaDD... etc, then bbBB..., bbCC..., bbDD... etc
//    - 26*26 = 676. Then just vary number for each one.. (in pairs too ig)
// 3:31pm, impl!
// 3:35pm think it works, submit. with n=1000, gets up to ddVV99!!
//  - (neat, submitted, selected g.cpp, auto detected problem G)
//  - correct!! 3:36pm, 1:23:30 remaining. 8th, vs 6th and 7th on 5 each...

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int i = 0;
  for (char lower = 'a'; lower <= 'z'; lower++) {
    for (char upper = 'A'; upper <= 'Z'; upper++) {
      for (char digit = '0'; digit <= '9' && i < n; digit++, i++) {
        cout << lower << lower << upper << upper << digit << digit << "!!\n";
      }
    }
  }
}
