#include <bits/stdc++.h>
using namespace std;
const int MAXN = 25;

int n, a[MAXN];
string s;

bool p[MAXN];

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		if (isdigit(s[i])) a[i + 1] = s[i] - '0';
		else a[i + 1] = s[i] - 'A' + 10;
	}
	p[n] = true;
	double mnavr, mxavr, avr, ans = 1E9;
	for (int z = 1; z < (1 << (n - 1)); z++) {
		for (int i = 0; i < n - 1; i++) 
			p[i + 1] = (z >> i) & 1;
		mnavr = 1E9, mxavr = -1, avr = 0;
		for (int i = 1, l = 0; i <= n; i++) {
			avr += a[i];
			if (p[i]) {
				avr /= i - l;
				mnavr = min(mnavr, avr);
				mxavr = max(mxavr, avr);
				avr = 0, l = i;
			}
		}
		ans = min(ans, mxavr - mnavr);
	}
	cout << fixed << setprecision(8) << ans;

	return 0;
}

/*

This little peace is all I need.

*/