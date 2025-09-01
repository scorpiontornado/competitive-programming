// Labour Laws
// 12:52pm

// If an employee works "more than" (>= ?) 6h -> 30 min break
//  - 6h = 360 mins
// If work >= 9h -> 45 min break
//  - 9h = 540 mins
// Working >= 10h -> forbidden (must be break for more than that?)
//  - 10h = 600 mins, t up to 1440, ... eg if t=1440, must have 1440-600=840
//  break

// Nvm, sample 3 -> 540 leads to 30 min break. So, "more than" = strictly >
// Also, output break, not time worked!

// g++ l.cpp -o l; i=1; while [ $i -le 4 ]; do diff -s <(./l <
// samples/samples-L/$i.in) samples/samples-L/$i.ans; i=$((i+1)); done

// Custom testing revealed I was giving 1 for 601, oops!
//  - No sample cases for >10h, careful!

// Hang on, not e.g. t <= 540...? 540mins at work doesn't mean 540 mins working?
// 361... 1 min break is ok..? Would be 6h working, don't need to take 30 min
// break 389 would be 29 min break, 390 to 540 means 30 min break what about
// 541? 31 min break... up until 585 -> 45 min break, as is 586 etc up until 600
// (10 hrs)

// 0 -> 0 (sample 4)
// 1 -> 0
// 360 -> 0 (sample 2)
// 361 -> 1 (prev = 0 @ 0, next = 30 @ 360)
// 389 -> 29
// 390 -> 30
// 391 -> 30 (prev = 30 @ 360, next = 45 @ 540)
// 540 -> 30 (prev = 30 @ 60, next = 45 @ 540)
// 541 -> ~~31~~ 30 (prev = 45 @ 540, next = ... @ 600)
// 584 -> 44
// 585 -> 45
// 585 -> 45
// 600 -> 45
// 601 -> 46
// 602 -> 47
// 700 -> 145
// 800 -> 245
// 1440 ->

// wait no,,, 541 - 30 = 511 mins worked, still <= 540, no need for 45 min break
//  -> 30 min break for 541 still, all the way up to 570 (540 min worked)
// similarly, with 601, 45 is still fine. Just need 2 for not >10, and 45 from
// 9hr constraint
//  -> 45 fine up to 645, i.e. 600 mins worked = 10hrs, then at 646 need 46 min
//  break, etc

// (1:21pm gg, shouldn't be taking this long)
// 0 -> 0
// 1 -> 0
// 360 -> 0
// 361 -> 1 (360 min worked, no need for 30 min break)
// 390 -> 30 (360 min worked, 30 min break not REQUIRED but would be if worked
//            361 min, impossible)
// 391 -> 30 (361 min worked, > 360 so need >= 30 min break, but <= 540 so
//            don't need >= 45 min break)
// 540 -> 30
// 570 -> 30 (540 min worked)
// 571 -> 31 (540 min worked, still just need >= 30 min break)
// 585 -> 45 (540 min worked)
// 586 -> 45 (541 > 540 min worked, but <= 10 hours)
// 645 -> 45 (600 min worked)
// 646 -> 46 (can't have > 600 min worked)
// 647 -> 47 etc.... for all >= 645, break = t - 600

// 1:30pm gg just hardcode those boundaries lol, dw abt generalising

// 1:35pm, manually tested those boundaries, working as expected, submit!
// - correct!! Back to 6th! Next above me has done H (60) then G (69), do G!

#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; // num minutes spent at work
  cin >> t;

  int brk;
  // if (t <= 360) {
  //   brk = 0;
  // } else if (t <= 540) {
  //   // > 6h but <= 9h at work
  //   brk = 30;
  // } else if (t <= 600) {
  //   // > 9h but <= 10h at work
  //   brk = 45;
  // } else {
  //   // Can't work "more than" 10 hours a day, & break must also be at least
  //   45 min
  //   // brk = t - 600;
  //   brk = 45 + (t - 45 - 600); // TODO: fix
  // }

  if (t <= 360) {
    brk = 0;
  } else if (t <= 360 + 30) {
    brk = t - 360; // keep under 6 hours worked to avoid forced 30 min break
  } else if (t <= 540 + 30) {
    brk = 30; // XXX: could prob combine w case above using min(t - 360, 30)?
  } else if (t <= 540 + 45) {
    brk = t - 540;
  } else if (t <= 600 + 45) {
    brk = 45;
  } else {
    brk = t - 600;
  }

  cout << brk << "\n";
}
