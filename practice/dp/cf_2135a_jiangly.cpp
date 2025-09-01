// Source: https://codeforces.com/contest/2135/submission/335945238
// Author: jiangly

#include <bits/stdc++.h>

using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;

using u128 = unsigned __int128;
using i128 = __int128;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    
    std::vector<std::vector<int>> vec(n);
    std::vector<int> id(n);
    for (int i = 0; i < n; i++) {
        id[i] = vec[a[i]].size();
        vec[a[i]].push_back(i);
    }
    
    std::vector<int> dp(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i];
        if (id[i] >= a[i]) {
            dp[i + 1] = std::max(dp[i + 1], a[i] + 1 + dp[vec[a[i]][id[i] - a[i]]]);
        }
    }
    
    std::cout << dp[n] << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}