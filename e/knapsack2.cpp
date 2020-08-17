#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

ll f(int n, int j, vector<vector<ll> > &dp, vector<ll> &v, vector<ll> &wt) {
	if(j == 0) return 0;
	if(n < 0) return INF;
	if(dp[n][j] != -1) return dp[n][j];
	ll x = f(n - 1, j, dp, v, wt);
	if(j >= v[n]) x = min(x, wt[n] + f(n - 1, j - v[n], dp, v, wt));
	dp[n][j] = x;
	return x;
}

void solve() {
	int n, w;
	cin >> n >> w;
	vector<ll> wt(n), v(n);
	int value = 0;
	for(int i = 0; i < n; ++i) {
		cin >> wt[i] >> v[i];
		value += v[i];
	}
	vector<vector<ll> > dp(n, vector<ll>(value + 1, -1));
	for(int j = value; j >= 0; j--) {
		ll x = f(n - 1, j, dp, v, wt);
		if(x <= w) {
			cout << j << "\n";
			return;
		}
	}
	cout << "0\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
