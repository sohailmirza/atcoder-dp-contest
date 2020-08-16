#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int f(int n, vector<int> &h, vector<int> &dp) {
	if(n == 0) return 0;
	if(n == 1) return abs(h[1] - h[0]);
	if(dp[n] != -1) return dp[n];
	int x = min(f(n - 1, h, dp) + abs(h[n] - h[n - 1]), f(n - 2, h, dp) + abs(h[n] - h[n - 2]));
	dp[n] = x;
	return x;
}

void solve() {
	int n;
	cin >> n;
	vector<int> h(n);
	for(int i = 0; i < n; i++) {
		cin >> h[i];
	}
	vector<int> dp(n, -1);
	cout << f(n - 1, h, dp) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
