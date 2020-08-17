#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

void solve() {
	int n, w;
	cin >> n >> w;
	vector<ll> wt(n), v(n);
	for(int i = 0; i < n; ++i) {
		cin >> wt[i] >> v[i];
	}
	vector<vector<ll> > dp(2, vector<ll>(w + 1));
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= w; j++) {
			if(i == 0 || j == 0) {
				dp[i % 2][j] = 0;
				continue;
			}
			dp[i % 2][j] = max(dp[(i - 1) % 2][j], (j >= wt[i - 1] ? v[i - 1] + dp[(i - 1) % 2][j - wt[i - 1]] : 0));
		}
	}
	cout << dp[n % 2][w] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
