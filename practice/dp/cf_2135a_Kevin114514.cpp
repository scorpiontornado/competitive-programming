// Source: https://codeforces.com/contest/2135/submission/335945540

//Author: Kevin
#include<bits/stdc++.h>
//#pragma GCC optimize("O2")
using namespace std;
#define ll long long
#define ull unsigned ll
#define pb emplace_back
#define mp make_pair
#define ALL(x) (x).begin(),(x).end()
#define rALL(x) (x).rbegin(),(x).rend()
#define srt(x) sort(ALL(x))
#define rev(x) reverse(ALL(x))
#define rsrt(x) sort(rALL(x))
#define sz(x) (int)(x.size())
#define inf 0x3f3f3f3f
#define pii pair<int,int>
#define lb(v,x) (int)(lower_bound(ALL(v),x)-v.begin())
#define ub(v,x) (int)(upper_bound(ALL(v),x)-v.begin())
#define uni(v) v.resize(unique(ALL(v))-v.begin())
#define longer __int128_t
void die(string S){puts(S.c_str());exit(0);}
int t;
int n,a[200200];
vector<int> vec[200200];
int f[200200];
void solve()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		vec[i].clear();
	for(int i=1;i<=n;i++)
	{
		f[i]=f[i-1];
		vec[a[i]].pb(i);
		if(sz(vec[a[i]])>=a[i])
			f[i]=max(f[i],a[i]+f[vec[a[i]][sz(vec[a[i]])-a[i]]-1]);
	}
	cout<<f[n]<<'\n';
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--)
		solve();
	return 0;
}