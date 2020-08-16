#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int f(int n, int i, vector<vector<int> > &dp, vector<vector<int> > &v) {
	if(n == 0) {
		return v[n][i];
	}
	if(dp[n][i] != -1) return dp[n][i];
	int x = 0;
	for(int j = 0; j < 3; j++) {
		if(i != j) {
			x = max(x, f(n - 1, j, dp, v) + v[n][i]);
		}
	}
	dp[n][i] = x;
	return x;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int> > v(n, vector<int>(3));
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++){
			cin >> v[i][j];
		}
	}
	vector<vector<int> > dp(n, vector<int>(3, -1));
	int ans = INT_MIN;
	for(int i = 0; i < 3; i++) {
		ans = max(ans, f(n - 1, i, dp, v));
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
