// Happy Hookup
// https://spare.unswcpmsoc.com/team/problems/107/text

// g++ h.cpp -o h
// diff -s <(./h < samples/samples-H/1.in) samples/samples-H/1.ans
// i=1; while [ $i -le 3 ]; do diff -s <(./h < samples/samples-H/$i.in) samples/samples-H/$i.ans; i=$((i+1)); done

// Accepted, 1st try!! 6th atm, soloing (scorpiontornado). 48 points.
// 1st place (ryno) done K, L, H, G, D, F.. gg
// 2nd place (sanctioned country 3) done K, D, H, L, G
// was  bit stumped on K ngl, try L? D? 3rd place (syntaxation) done L, D, G

#include <bits/stdc++.h>
using namespace std;

const int N = 100100;
int n, m, a, b;
vector<int> adj[N];
bool seen1[N], seen2[N];

int main() {
  // (12:30pm, impl)
  cin >> n >> m;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
  }

  cin >> a >> b;

  // BFS from a (you)
  queue<int> q;
  q.push(a);
  seen1[a] = true;

  while (q.size()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (!seen1[v]) {
        q.push(v);
        seen1[v] = true;
      }
    }
  }

  // BFS from hannah, if any alr seen from first bfs, done
  q.push(b);
  seen2[b] = true;

  while (q.size()) {
    int u = q.front();
    q.pop();

    // XXX: could put this with the pushing, but have to check b too
    if (seen1[u]) {
      cout << "yes\n" << u << '\n';
      return 0;
    }

    for (int v : adj[u]) {
      if (!seen2[v]) {
        q.push(v);
        seen2[v] = true;
      }
    }
  }

  cout << "no\n";
}
