#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

ll f(int n, int m, vector<vector<char>> &G, vector<vector<ll> > &dp) {
	if(n == 0 && m == 0) return 1ll;
	if(n < 0 || m < 0 || G[n][m] == '#') return 0;
	if(dp[n][m] != -1) return dp[n][m];
	dp[n][m] = (f(n - 1, m, G, dp) + f(n, m - 1, G, dp)) % MOD;
	return dp[n][m];
}

void solve() {
	int m, n;
	cin >> n >> m;
	vector<vector<char> > G(n, vector<char>(m));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j< m; ++j) {
			cin >> G[i][j];
		}
	}
	vector<vector<ll> > dp(n, vector<ll>(m, -1));
	cout << f(n - 1, m - 1, G, dp);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
