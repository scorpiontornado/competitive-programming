// Source: https://atcoder.jp/contests/abc425/editorial/14082

#include <bits/stdc++.h>
using namespace std;
int main() {
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (i % 2 == 0) {
			ans += i * i * i;
		} else {
			ans -= i * i * i;
		}
	}
	cout << ans << endl;
}
