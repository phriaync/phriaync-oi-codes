#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1E6+5;

int n;

int dp[MAXN];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1];
		if (i % 2 == 0) dp[i] = min(dp[i], dp[i >> 1]);
		dp[i]++;
	}
	cout << dp[n];
	
	return 0;
}