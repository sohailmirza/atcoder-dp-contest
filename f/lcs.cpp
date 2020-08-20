#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

const int INF = 1e9 + 5;
const int MOD = 1e9 + 7;

int f(int n, int m, string &a, string &b, vector<vector<int> > &dp) {
	if(n < 0 || m < 0) return 0;
	if(dp[n][m] != -1) return dp[n][m];
	int x = 0;
	if(a[n] == b[m]) {
		x = f(n - 1, m - 1, a, b, dp) + 1;
	} else {
		x = max(f(n - 1, m, a, b, dp), f(n, m - 1, a, b, dp));
	}
	dp[n][m] = x;
	return x;
}

void create(int n, int m, string &a, string &b, vector<vector<int> > &dp, string &ans) {
	if(n < 0 || m < 0) return;
	if(f(n, m, a, b, dp) == max(f(n - 1, m, a, b, dp), f(n, m - 1, a, b, dp))) {
		if(f(n - 1, m, a, b, dp) >= f(n, m - 1, a, b, dp)) {
			create(n - 1, m, a, b, dp, ans);
		} else {
			create(n, m - 1, a, b, dp, ans);
		}
	} else {
		ans += a[n];
		create(n - 1, m - 1, a, b, dp, ans);
	}
}

void solve() {
	string a, b;
	cin >> a >> b;
	int n = a.length(), m = b.length();
	vector<vector<int> > dp(n, vector<int>(m, -1));
	string ans;
	create(n - 1, m - 1, a, b, dp, ans);
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	solve();
	
	return 0;
}
