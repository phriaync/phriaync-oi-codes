#include <bits/stdc++.h>
using namespace std;

int t, n, m;

bool hv[10005], g[1005][1005];
int k;

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> n >> m;
		if (m + n - 1 >= n * (n - 1) / 2) {
			for (int i = 1; i < n; i++)
				for (int j = i + 1; j <= n; j++)
					g[i][j] = false;
			for (int i = 1, u, v; i <= m; i++) {
				cin >> u >> v;
				if (u > v) swap(u, v);
				g[u][v] = true;
			}
			cout << n * (n - 1) / 2 - m << '\n';
			for (int i = 1; i < n; i++) {
				for (int j = i + 1; j <= n; j++)
					if (!g[i][j]) cout << i << ' ' << j << '\n';
			}
		} else {
			for (int i = 2; i <= n; i++) hv[i] = false;
			k = n - 1;
			for (int i = 1, u, v; i <= m; i++) {
				cin >> u >> v;
				if (u > v) swap(u, v);
				if (u == 1) hv[v] = true, k--;
			}
			cout << k << '\n';
			for (int i = 2; i <= n; i++) 
				if (!hv[i]) cout << "1 " << i << '\n';
		}
	}
	
	
	return 0;
}

/*

the Grand Inception

*/