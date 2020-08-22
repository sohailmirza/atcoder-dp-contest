#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

double f(int n, int m, vector<double> &prob, vector<vector<double> > &dp) {
	if(n < m) return 0;
	if(n < 0) return 1;
	if(m < 0) {
		double x = 1;
		for(int i = 0; i <= n; i++) x *= (1 - prob[i]);
		return x;
	}
	if(dp[n][m] >= 0) return dp[n][m];
	double x = (prob[n] * f(n - 1, m - 1, prob, dp)) + ((1 - prob[n]) * f(n - 1, m, prob, dp));
	dp[n][m] = x;
	return x;
}

void solve() {
	int n;
	cin >> n;
	vector<double> prob(n);
	for(int i = 0; i < n; ++i) cin >> prob[i];
	vector<vector<double> > dp(n, vector<double>(n, -1));
	double ans = 0;
	for(int i = n /2; i <= n; i++) {
		ans += f(n - 1, i, prob, dp);
	}
	printf("%.10lf", ans);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
