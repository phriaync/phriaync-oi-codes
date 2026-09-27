#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;

int t, n, a[MAXN];

int lp, rp;
long long sa[MAXN], ans, dt;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 1; i < n; i++) cin >> a[i];
		for (int i = 1; i < n; i++) sa[i + 1] = sa[i] + a[i];
		ans = dt = lp = 0, rp = n + 1;
		for (int i = 1; i <= n; i++) {
			if (i & 1) ans += dt, dt -= sa[++lp];
			else dt += sa[--rp], ans += dt;
			cout << ans << ' ';
		}
		cout << '\n';
		// 怎么会有人忘记换行的啊
	}

	return 0;
}

/*

世界わやがて
優しい色に染まる

*/