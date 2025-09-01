// https://atcoder.jp/contests/abc416/tasks/abc416_d
//
// "Up-solve" - was unable to solve it during the contest, but then read the
// editorial (https://atcoder.jp/contests/abc416/editorial/13540), walked
// through it with ChatGPT, and wrote pseudocode for a mirrored solution
/*
  sort(A ascending)
  sort(B ascending)

  a = 0
  b = B.size() - 1
  c = 0

  WHILE a < A.size()
      WHILE b >= 0 AND A[a] + B[b] < M
          b--
      ENDWHILE

      IF b < 0
          BREAK
      ENDIF

      c++
      a++
      b--
  ENDWHILE

  OUTPUT sum(A) + sum(B) - c * M
*/
//
// 27/07/2025, 11:06:00pm, go! Upsolve - collapsed pseudocode, hid editorial
// - 11:38:00pm, testing. See obsidian 2025-07-27 btw.
// - 11:41/42pm, resubmitting after many WA's - changed sum from int to ll.
// - btw got WA on even more, realised c * m def can't fit in an int as M < 1e9,
//   changed c to be a long long (ll) so the product will also be ll - approved!

// #define __DEBUG__ ;

#pragma region template
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
using namespace std;

// -------------------- Type Aliases --------------------
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
using ld = long double;

using vi = vector<int>;
using vll = vector<ll>;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using vpi = vector<pi>;
using vpll = vector<pll>;
using vvi = vector<vi>;
using vvll = vector<vll>;

using mi = map<int, int>;
using mll = map<ll, ll>;
using si = set<int>;
using sll = set<ll>;
using umii = unordered_map<int, int>;
using usi = unordered_set<int>;

// Min/Max heaps
using pqi = priority_queue<int>;
using pqll = priority_queue<ll>;
using pqi_min = priority_queue<int, vi, greater<>>;
using pqll_min = priority_queue<ll, vll, greater<>>;

// Order Statistic Tree (PBDS)
// template <typename T>
// using ost = tree<T, null_type, less<T>, rb_tree_tag,
// tree_order_statistics_node_update>;

// PBDS - alternative, from lecture code (4-datastructures-code.cpp)
// typedef tree<int, null_type, less<int>, rb_tree_tag,
//             tree_order_statistics_node_update> ordered_set;
// typedef tree<int, char, less<int>, rb_tree_tag,
//             tree_order_statistics_node_update> ordered_map;

// -------------------- Constants --------------------
const int inf = numeric_limits<int>::max();
const ll INF = numeric_limits<ll>::max();

// -------------------- Macros --------------------
#define rep(i, a, b) for (int i = (a); i < (b); ++i)        // half-open: [a, b)
#define repi(i, a, b) for (int i = (a); i <= (b); ++i)      // inclusive: [a, b]
#define rrep(i, a, b) for (int i = (b) - 1; i >= (a); --i)  // reverse: [b-1, a]
#define rrepi(i, a, b) for (int i = (b); i >= (a); --i)     // reverse: [b, a]

#define repn(i, n) rep(i, 0, n)   // repeat n times, starting at 0: [0, n)
#define rep1(i, n) repi(i, 1, n)  // repeat n times, starting at 1: [1, n]

#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define F first
#define S second

// print macro, from Tian
#pragma region debug_print
#ifdef __DEBUG__
void __p(int x) { cerr << x; }
void __p(long x) { cerr << x; }
void __p(long long x) { cerr << x; }
void __p(unsigned x) { cerr << x; }
void __p(unsigned long x) { cerr << x; }
void __p(unsigned long long x) { cerr << x; }
void __p(float x) { cerr << x; }
void __p(double x) { cerr << x; }
void __p(long double x) { cerr << x; }
void __p(char x) { cerr << '\'' << x << '\''; }
void __p(const char *x) { cerr << '"' << x << '"'; }
void __p(const string &x) { cerr << '"' << x << '"'; }
void __p(bool x) { cerr << (x ? "true" : "false"); }

template <typename A>
void __p(const A &x);
template <typename A, typename B>
void __p(const pair<A, B> &p);
template <typename... A>
void __p(const tuple<A...> &t);
template <typename T>
void __p(stack<T> s);
template <typename T>
void __p(queue<T> q);
template <typename T, typename... U>
void __p(priority_queue<T, U...> q);

template <typename A>
void __p(const A &x) {
  auto first = true;
  cerr << '[';
  for (const auto &i : x) {
    cerr << (first ? "" : ","), __p(i);
    first = false;
  }
  cerr << ']';
}

template <typename A, typename B>
void __p(const pair<A, B> &p) {
  cerr << '(';
  __p(p.first);
  cerr << ",";
  __p(p.second);
  cerr << ')';
}

template <typename... A>
void __p(const tuple<A...> &t) {
  auto first = true;
  cerr << '(';
  apply(
      [&first](const auto &...args) {
        ((cerr << (first ? "" : ","), __p(args), first = false), ...);
      },
      t);
  cerr << ')';
}

template <typename T>
void __p(stack<T> s) {
  vector<T> v;
  while (!s.empty()) {
    T t = s.top();
    v.push_back(t);
    s.pop();
  }
  reverse(all(v));
  __p(v);
}

template <typename T>
void __p(queue<T> q) {
  vector<T> v;
  while (!q.empty()) {
    T t = q.front();
    v.push_back(t);
    q.pop();
  }
  __p(v);
}

template <typename T, typename... U>
void __p(priority_queue<T, U...> q) {
  vector<T> v;
  while (!q.empty()) {
    T t = q.top();
    v.push_back(t);
    q.pop();
  }
  __p(v);
}

void _p() { cerr << "]\n"; }
template <typename Head, typename... Tail>
void _p(const Head &H, const Tail &...T) {
  __p(H);
  if (sizeof...(T)) cerr << ", ";
  _p(T...);
}

#define print(...)                                              \
  cerr << "" << __LINE__ << " => [" << #__VA_ARGS__ << "] = ["; \
  _p(__VA_ARGS__);

#else
#define print(...) ;
#endif
#pragma endregion debug_print
#pragma endregion template

int t, n, m;
int const N = 300'300;  // 3 * 10^5
int A[N];
int B[N];
//! Careful! Ensure A & B don't carry over between test cases

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> t;
  repn(case_num, t) {
    cin >> n >> m;

    ll sum = 0;
    repn(i, n) {
      cin >> A[i];
      sum += A[i];
    }
    repn(i, n) {
      cin >> B[i];
      sum += B[i];
    }

    sort(A, A + n, greater<int>());
    sort(B, B + n);

    // sum_i((A_i + B_i)) mod M) = sum_i(A_i) + sum_i(B_i) - c*M
    ll c = 0;

    // Pair up A's, largest to smallest, with smallest possible unchosen B that
    // makes the sum >= M (and < 2M), so that (mod M) subtracts M. Count the
    // number of such pairings to see how much the total sum can be reduced by
    for (int a = 0, b = 0; a < n; a++, b++, c++) {
      while (A[a] + B[b] < m && b < n) b++;
      if (b == n) break;  // No more B's can pair with an A to sum to >= M
      // A[a] + B[b] >= M, mod M will subtract M from total so increment c
    }

    //! Careful - both sum and c * m can't fit in int, make sure to use ll
    cout << sum - c * m << '\n';
  }
}
