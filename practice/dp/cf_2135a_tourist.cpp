// Source: https://codeforces.com/contest/2135/submission/335945430

/**
 *    author:  tourist
 *    created: 28.08.2025 07:33:57
**/
#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "algo/debug.h"
#else
#define debug(...) 42
#endif
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<vector<int>> at(n + 1);
    for (int i = 0; i < n; i++) {
      at[a[i]].push_back(i);
    }
    vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
      dp[i + 1] = max(dp[i + 1], dp[i]);
      auto it = lower_bound(at[a[i]].begin(), at[a[i]].end(), i);
      int pos = int(it - at[a[i]].begin());
      pos += a[i] - 1;
      if (pos < int(at[a[i]].size())) {
        int j = at[a[i]][pos];
        dp[j + 1] = max(dp[j + 1], dp[i] + a[i]);
      }
    }
    cout << dp[n] << '\n';
  }
  return 0;
}