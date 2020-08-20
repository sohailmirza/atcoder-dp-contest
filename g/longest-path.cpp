#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int f(int u, vector<vector<int> > &G, vector<int> &dp) {
	if(dp[u] != -1) return dp[u];
	int x = 0;
	for(int v: G[u]) {
		x = max(f(v, G, dp) + 1, x);
	}
	dp[u] = x;
	return x;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int> > G(n + 1);
	for(int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v);
	}
	vector<int> dp(n + 1, -1);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, f(i, G, dp));
	}
	cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
