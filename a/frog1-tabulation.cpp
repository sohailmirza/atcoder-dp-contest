#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

void solve() {
	int n;
	cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; ++i) {
		cin >> h[i];
	}
	vector<int> dp(n);
	dp[0] = 0;
	dp[1] = abs(h[1] - h[0]);
	for(int i = 2; i < n; i++) {
		dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] +abs(h[i] - h[i - 2]));
	}
	cout << dp[n - 1] << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
