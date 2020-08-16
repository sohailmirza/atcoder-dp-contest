#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> h(n);
	for(int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	vector<int> dp(n);
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);
	for(int i = 2; i < n; i++) {
		int x = INF;
		for(int j = 1; j <= k && i >= j; ++j) {
			x = min(dp[i - j] + abs(h[i] - h[i - j]), x);
		}
		dp[i] = x;
	}
	cout << dp[n - 1] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
